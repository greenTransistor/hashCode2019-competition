vector<int> verticalImagesIndexes;

void selectVerticalSlides() {
	for (int i = 0; i < images.size(); i++) {
		if (images[i].orientation == 'V') {
			verticalImagesIndexes.push_back(i);
		}
	}
}
