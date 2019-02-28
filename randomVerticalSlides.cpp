vector<int> verticalSlidesIndexes;

void selectVerticalSlides() {
	for (int i = 0; i < slides.size(); i++) {
		if (slides[i]->orientation == 'V') {
			verticalSlidesIndexes.push_back(i);
		}
	}
}
