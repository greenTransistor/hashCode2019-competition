#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <map>
#include <queue>
#include <set>
#include <utility>
#include <vector>

using namespace std;

const int GREEDY_ATTEMPTS_COUNT = 5;
const int GREEDY_CANDIDATES_COUNT = 1000;
const int SLIDES_SETS_COUNT = 10;
const int SLIDESHOW_PER_SET = 10;

struct Image {
	char orientation;
	int id;
	vector<int> tags;
};

#include "slide.cpp"

const int FILES_COUNT = 5;
const string FILE_NAMES[FILES_COUNT] = {"a_example", "b_lovely_landscapes", "c_memorable_moments", "d_pet_pictures", "e_shiny_selfies"};
string fileName, inputFileName, outputFileName;

//Global
vector<Image> images;
vector<Slide*> slides;
vector<Slide*> answer;
int bestScore = 0;

#include "memory.cpp"
#include "setAnswer.cpp"
#include "scoring.cpp"
#include "randomVerticalSlides.cpp"
#include "calculate_result.cpp"
#include "calcBestAns.cpp"
#include "greedy_algorithm.cpp"

void readInputFile(string name) {
	int imagesCount;
	int tagsCount;
	ifstream inf(name);
	Image newImage;
	int tag;

	inf >> imagesCount;
	images.resize(imagesCount);
	for (int i = 0; i < imagesCount; i++) {
		newImage = Image();
		newImage.id = i;
		inf >> newImage.orientation;
		inf >> tagsCount;
		newImage.tags.resize(tagsCount);
		for (int j = 0; j < tagsCount; j++) {
			inf >> tag;
			newImage.tags[j] = tag;
		}
		images[i] = newImage;
	}
	inf.close();
}

void writeOutputFile(string name) {
	ofstream outf(name);

	outf << answer.size() << "\n";
	for (Slide* slide : answer) {
		outf << slide->ids[0];
		if (slide->ids.size() > 1) {
			outf << " " << slide->ids[1];
		}
		outf << "\n";
	}
	outf.close();
}

int main() {
	for (int fileIndex = 0; fileIndex < FILES_COUNT; fileIndex++) {
		fileName = FILE_NAMES[fileIndex];
		inputFileName = fileName + ".in";
		outputFileName = fileName + ".out";
		readInputFile(inputFileName);

		bestScore = 0;
		divideSlides();
		//calcBestAns();
		greedy_algorithm();

		writeOutputFile(outputFileName);
		cout << "For dataset #" << fileIndex << " '" << fileName << "' the best score is " << bestScore << "\n";
	}

	return 0;
}
