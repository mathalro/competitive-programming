#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long llu;

int main () {

	llu n, k; scanf("%llu %llu", &n, &k);

	if (k == 1) {
		printf("%llu\n", n);
	} else {
		string s = bitset<64>(n).to_string();
		int i = 0;
		while (s[i++] != '1');
		while (i < s.size()) {
			s[i] = '1';
			i++;
		}
		unsigned long long ans = bitset<64>(s).to_ullong();
		printf("%llu\n", ans);
	}
	return 0;
}
