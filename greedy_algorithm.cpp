int greedyAttemptNumber;

void greedy_algorithm_attempt() {
	set <int> poss;
	int n = slides.size();
	for (int i = 0; i < n; i++) {
		poss.insert(i);
	}
	int first_pos = rand() % n;
	vector <Slide*> bsls = {slides[first_pos]};
	poss.erase(first_pos);
	for (int i = 1; i < n; i++) {
		if (i % 100 == 99) {
			cout << "File " << fileName << ", attempt " << greedyAttemptNumber << "/" << GREEDY_ATTEMPTS_COUNT << ", slide " << (i + 1) << "/" << n << "\n";
		}
		int mxscore = -1, mxpos = 0;
		for (int j = 0; j < GREEDY_CANDIDATES_COUNT; j++) {
			int pos = rand() % n;
			auto it = poss.lower_bound(pos);
			if (it == poss.end()) {
				it = poss.begin();
			}
			int score = countScore(*bsls[i - 1], *slides[*it]);
			if (score > mxscore) {
				mxscore = score;
				mxpos = *it;
			}
		}
		bsls.push_back(slides[mxpos]);
		poss.erase(mxpos);
	}
	int res = calculate_result(bsls);
	if (res > bestScore) {
		bestScore = res;
		setAnswer(bsls);
	}
}

void greedy_algorithm() {
	for (greedyAttemptNumber = 1; greedyAttemptNumber <= GREEDY_ATTEMPTS_COUNT; greedyAttemptNumber++) {
		getRandomSlides();
		greedy_algorithm_attempt();
	}
}
