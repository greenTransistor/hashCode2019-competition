vector<int> horizontalImagesIndexes;
vector<int> verticalImagesIndexes;

void getRandomSlides() {
	vector<int> shuffledIndexes = verticalImagesIndexes;
	random_shuffle(shuffledIndexes.begin(), shuffledIndexes.end());
	clearSlides();
	for (int i = 0; i + 1 < shuffledIndexes.size(); i += 2) {
		slides.push_back(new Slide(images[shuffledIndexes[i]], images[shuffledIndexes[i + 1]]));
	}
	for (int i = 0; i < horizontalImagesIndexes.size(); i++) {
		slides.push_back(new Slide(images[horizontalImagesIndexes[i]]));
	}
}

void divideSlides() {
	horizontalImagesIndexes.clear();
	verticalImagesIndexes.clear();
	for (int i = 0; i < images.size(); i++) {
		if (images[i].orientation == 'V') {
			verticalImagesIndexes.push_back(i);
		} else {
			horizontalImagesIndexes.push_back(i);
		}
	}
}
