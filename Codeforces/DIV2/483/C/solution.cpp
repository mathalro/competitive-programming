#include <bits/stdc++.h>

using namespace std;

long long p, q, b; 

long long GCD(long long a, long long b) {
	while (b != 0) {
		long long r = a%b;
		a = b;
		b = r;
	}
	return a;
}

int main () {
	int n; scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%lld %lld %lld", &p, &q, &b);
		long long gcd = GCD(p, q);
		q /= gcd;

		if (p == 0 || q == 1) {
			printf("Finite\n");
			continue;
		}

		gcd = GCD(q, b);
		while (gcd != 1) {
			while (q%gcd == 0) q /= gcd;
			gcd = GCD(q, b);
		}

		if (q == 1) printf("Finite\n");
		else printf("Infinite\n");
	}

	return 0;
}
