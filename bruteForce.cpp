int bruteForceAttemptNumber;

void bruteForceAttempt() {
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
			cout << "File " << fileName << ", attempt " << bruteForceAttemptNumber << "/" << BRUTE_FORCE_ATTEMPTS_COUNT << ", slide " << (i + 1) << "/" << n << "\n";
		}
		int mxscore = -1, mxpos = 0;
		for (auto it = poss.begin(); it != poss.end(); it++) {
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

void bruteForce() {
	for (bruteForceAttemptNumber = 1; bruteForceAttemptNumber <= BRUTE_FORCE_ATTEMPTS_COUNT; bruteForceAttemptNumber++) {
		getRandomSlides();
		bruteForceAttempt();
	}
}
