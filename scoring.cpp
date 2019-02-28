

template <typename T>
int countScore(const T& i1, const T& i2){
	
	int p1 = 0, p2 = 0,
		n1 = i1.tags.size(),
		n2 = i2.tags.size(),
		s1 = 0, s2 = 0, s0 = 0;
		
	while (p1 < n1 && p2 < n2){
		
		if (i1.tags[p1] == i2.tags[p2]) {
			s0++;
			p1++;
			p2++;
		}
		else if (i1.tags[p1] < i2.tags[p2]){
			s1++;
			p1++;
		}
		else {
			s2++;
			p2++;
		}
	}
	
	for (int i = p1; i < n1; i++)
		s1++;
		
	for (int i = p2; i < n2; i++)
		s2++;
		
	return min(min(s1,s2),s0);
}
