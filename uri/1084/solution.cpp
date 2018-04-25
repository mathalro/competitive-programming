#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, d;
	vector<char> s;
	char c;
	while (scanf("%d %d", &n, &d) && n) {
		while (scanf("%c", &c) && n-- >= 0) {
			while (s.size() > 1 && s[s.size()-1] < c && d) {						
				s.pop_back();
				d--;
			}
			
			s.push_back(c);
		}

		for (int i = 1; i < s.size()-d; i++) printf("%c", s[i]);
		puts("");
		s.clear();
	}
	
	return 0;
}
