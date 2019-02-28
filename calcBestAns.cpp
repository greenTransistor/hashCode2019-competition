
void updateAns(const vector <Slide*>& sls){

	vector <Slide*> sls0 = sls;
	random_shuffle(sls0.begin(), sls0.end());

	int newAns = calculate_result(sls0);
	if (newAns > bestScore) {

		bestScore = newAns;
		setAnswer(sls0);
	}
}

void calcAns(const vector <Slide*>& sls){

	for (int i = 0; i < SLIDESHOW_PER_SET; i++)
		updateAns(sls);
}

void calcBestAns(){

	for (int i = 0; i < SLIDES_SETS_COUNT; i++){

		getRandomSlides();
		calcAns(slides);
	}
}
