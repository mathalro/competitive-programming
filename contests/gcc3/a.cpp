#include <bits/stdc++.h>

using namespace std;

int c[27];

int main () {

	int n; scanf("%d", &n);
	string s; cin >> s;

	if (n > 26) {
		printf("-1\n");
		return 0;
	}

	for (int i = 0; i < s.size(); i++) {
		c[s[i]-'a']++;
	}

	int cont = 0;
	for (int i = 0; i < 27; i++) {
		cont += max(0, c[i]-1);
	}

	printf("%d\n", cont);

	return 0;
}
