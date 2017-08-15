#include <bits/stdc++.h>

using namespace std;

int main () {

	int n, k; scanf("%d %d", &n, &k);

	int rest = 0;

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		a += rest;
		if (a > 8) {
			rest = a-8;
			ans += 8; 
		} else {
			rest = 0;
			ans += a;
		}

		if (ans >= k) {
			printf("%d\n", i+1);
			return 0;
		}
	}

	printf("-1\n");

	return 0;
}
