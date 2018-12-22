#include <bits/stdc++.h>

using namespace std;

int c[26];

int main () {

	int n; scanf("%d", &n);

	string s;
	
	for (int i = 0; i < 1000; i++) {
		s += to_string(i);
	}

	printf("%c\n", s[n]);

	return 0;
}
