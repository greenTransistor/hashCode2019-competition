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
	vector<int> tags;
};

const int FILES_COUNT = 5;
const string FILE_NAMES[FILES_COUNT] = {"a_example", "b_lovely_landscapes", "c_memorable_moments", "d_pet_pictures", "e_shiny_selfies"};
string fileName, inputFileName, outputFileName;

//Global
vector<Image> images;

//Auxiliary
map<string, int> tagsIds;

int getTagId(string tagName) {
	auto searchResult = tagsIds.find(tagName);
	if (searchResult == tagsIds.end()) {
		int newId = tagsIds.size();
		tagsIds.insert(make_pair(tagName, newId));
		return newId;
	} else {
		return searchResult->second;
	}
}

void readInputFile(string name) {
	int imagesCount;
	int tagsCount;
	ifstream inf(name);
	Image newImage;
	string tag;

	inf >> imagesCount;
	for (int i = 0; i < imagesCount; i++) {
		newImage = Image();
		inf >> newImage.orientation;
		inf >> tagsCount;
		for (int j = 0; j < tagsCount; j++) {
			inf >> tag;
			newImage.tags.push_back(getTagId(tag));
		}
		images.push_back(newImage);
	}
	inf.close();
}

int main() {
	for (int fileIndex = 0; fileIndex < FILES_COUNT; fileIndex++) {
		fileName = FILE_NAMES[fileIndex];
		inputFileName = fileName + ".txt";
		readInputFile(inputFileName);
	}

	return 0;
}
