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

struct Image {
	char orientation;
	int id;
	vector<int> tags;
};

const int FILES_COUNT = 5;
const string FILE_NAMES[FILES_COUNT] = {"a_example", "b_lovely_landscapes", "c_memorable_moments", "d_pet_pictures", "e_shiny_selfies"};
string fileName, inputFileName, outputFileName;

//Global
vector<Image> images;
vector<*Slide> slides;

#include "slide.cpp"
#include "scoring.cpp"
#include "randomVerticalSlides.cpp"

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

	//
	outf.close();
}

int main() {
	for (int fileIndex = 0; fileIndex < FILES_COUNT; fileIndex++) {
		fileName = FILE_NAMES[fileIndex];
		inputFileName = fileName + ".in";
		outputFileName = fileName + ".out";
		readInputFile(inputFileName);
		//writeOutputFile(outputFileName);
	}

	return 0;
}
