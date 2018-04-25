#include <bits/stdc++.h>

using namespace std;

bool primo(int n) {
	if (n == 2) return true;
	if (n == 1) return true;
	if (n%2 == 0) return false;
	for (int i = 3; i <= sqrt(n)+1; i += 2) {
		if (n%i == 0) return false;
	}
	return true;
}

int main () {

	string s;

	while (cin >> s) {
		int cont = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] < 'a') {
				cont += s[i]-'A'+27;
			} else {
				cont += s[i]-'a'+1;
			}
		}

		if (primo(cont)) {
			printf("It is a prime word.\n");
		} else {
			printf("It is not a prime word.\n");
		}
	}	

	return 0;
}
