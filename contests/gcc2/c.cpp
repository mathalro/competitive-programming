#include <bits/stdc++.h>

using namespace std;

int c[26];

int main () {

	int n; scanf("%d", &n);
	vector<string> v;

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		v.push_back(v);
	}

	char last = '#';
	for (int i = 0; i < v.size(); i++) {
		if (!c[v[i][0]]) {
			c[v[i][0]] = 1;
			last = v[i][0];
		} else if (c[v[i][0]] != last) {
			printf("Impossible\n");
			return 0;
		}
	}

	return 0;
}
