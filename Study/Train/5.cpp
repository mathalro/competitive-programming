#include <bits/stdc++.h>

using namespace std;

int main () {
	map<int, int> m;
	
	m['q'-'a'] = 9;
	m['r'-'a'] = 5;
	m['b'-'a'] = 3;
	m['n'-'a'] = 3;
	m['p'-'a'] = 1;
	m['k'-'a'] = 0;

	int white = 0, black = 0;

	for (int i = 0; i < 8; i++) {
		string s; cin >> s;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '.') continue;
			if (s[i] >= 'a' && s[i] <= 'z') {
				black += m[s[i]-'a'];
			} else {
				white += m[s[i]-'A']; 
			}
		}
	}	

	if (black == white) puts("Draw");
	else printf(black > white ? "Black\n" : "White\n");	

	return 0;
}
