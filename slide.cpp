struct Slide {
	vector <int> tags;
	vector <int> ids;
	
	Slide(Image& im) {
		this->ids = {im.id};
		this->tags = im.tags;
	}
	
	Slide(Image& im1, Image& im2) {
		this->ids = {im1.id, im2.id};
		this->tags = merge(im1.tags, im2.tags);
	}
	
	vector <int> merge(vector <int> tags1, vector <int> tags2) {
		vector <int> tags;
		int p1 = 0, p2 = 0;
		while (p1 != tags1.size() || p2 != tags2.size()) {
			if (p1 == tags1.size()) {
				tags.push_back(tags2[p2++]);
			} else if (p2 == tags2.size()) {
				tags.push_back(tags1[p1++]);
			} else if (tags1[p1] == tags[p2]) {
				tags.push_back(tags1[p1]);
				p1++; p2++;
			} else if (tags1[p1] < tags2[p2]) {
				tags.push_back(tags1[p1++]);
			} else {
				tags.push_back(tags2[p2++]);
			}
		}
		return tags;
	}
};
