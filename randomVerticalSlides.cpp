vector<int> verticalImagesIndexes;

void clearSlides() {
	for (Slide* slide : slides) {
		delete slide;
	}
	slides.clear();
}

void getRandomSlides() {
	vector<int> shuffledIndexes = verticalImagesIndexes;
	random_shuffle(shuffledIndexes.begin(), shuffledIndexes.end());
	clearSlides();
}

void selectVerticalSlides() {
	for (int i = 0; i < images.size(); i++) {
		if (images[i].orientation == 'V') {
			verticalImagesIndexes.push_back(i);
		}
	}
}
