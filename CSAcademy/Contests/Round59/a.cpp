#include <bits/stdc++.h>

using namespace std;

int main () {


	int a; cin >> a;
	string s; cin >> s;

	for (int i = 0; i < s.size(); i++) {
		char c = s[i];
		int cont = 0;
		for (int j = 0; j < s.size(); j++) {
			cont += c == s[j];		
		}
		if (cont == 1) {
			cout << c << endl;
			return 0;
		}
	}

	cout << -1 << endl;

	return 0;
}
