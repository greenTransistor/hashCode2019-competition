int calculate_result(vector <Slide*>& sls) {
	int sum = 0;
	for (int i = 0; i < sls.size() - 1; i++) {
		sum += countScore<Slide>(*sls[i], *sls[i + 1]);
	}
	return sum;
}
