#include <bits/stdc++.h>

using namespace std;

int main () {

	string s;

	while (getline(cin, s)) {
		if ( s == "*" ) {
			break;
		}

		char f1 = s[0], f2;
		if (islower(f1)) {
			f2 = toupper(f1);
		} else {
			f2 = tolower(f1);
		}
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ') {
				if (s[i+1] != f1 && s[i+1] != f2) {
					printf("N\n");
					break;
				}
			}

			if (i == s.size()-1) {
				printf("Y\n");
			}
		}
	}

	return 0;
}