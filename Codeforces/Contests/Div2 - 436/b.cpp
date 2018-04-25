#include <bits/stdc++.h>

using namespace std;

int v[26];

int main () {

	int n; cin >> n;
	string s; cin >> s;

	int cont = 0, ans = 0;

	memset(v, 0, sizeof v);
	cont = 0;
	for (int j = 0; s[j] >= 'a' && s[j] <= 'z' && j < s.size(); j++) {
		if (!v[s[j]-'a']) {
			cont++;
			v[s[j]-'a']++;
		}
	}

	ans = max(cont, ans);

	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			memset(v, 0, sizeof v);
			cont = 0;
			for (int j = i+1; s[j] >= 'a' && s[j] <= 'z' && j < s.size(); j++) {
				if (!v[s[j]-'a']) {
					cont++;
					v[s[j]-'a']++;
				}
			}
			ans = max(ans, cont);
		}
	}

	memset(v, 0, sizeof v);
	cont = 0;
	for (int j = s.size()-1; s[j] >= 'a' && s[j] <= 'z' && j >= 0; j--) {
		if (!v[s[j]-'a']) {
			cont++;
			v[s[j]-'a']++;
		}
	}
	ans = max(ans, cont);

	cout << ans << endl;

	return 0;
}
