#include <bits/stdc++.h>

using namespace std;

int fe(int base, int e, int mod) {
	int ans = 1;
	while (e > 0) {
		if (e&1) ans *= base;
		base *= base;
		e /= 2;
	}
	return ans;
}

int main () {

	int base, e, mod; scanf("%d %d", &base, &e, mod);
	printf("%d\n", fe(base, e, mod));

	return 0;
}
