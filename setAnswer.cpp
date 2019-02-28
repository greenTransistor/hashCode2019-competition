void setAnswer(vector<Slide*> slides) {
	answer.clear();
	for (Slide* slide : slides) {
		if (slide->ids.size() == 1) {
			answer.push_back(new Slide(images[slide->ids[0]]));
		} else {
			answer.push_back(new Slide(images[slide->ids[0]], images[slide->ids[1]]));
		}
	}
}
