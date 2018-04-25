#include <bits/stdc++.h>
#define inf 0x3f3f3f3f

using namespace std;

int main () {

	long long n, k, A, B; scanf("%lld %lld %lld %lld", &n, &k, &A, &B);
	long long cont = 0;

	if (k == 1) {
		printf("%lld\n", A*(n-1));
		return 0;
	}

	while (n != 1) {
		if (n%k == 0) {
			int dest = n/k;
			cont += min((n-dest)*A, B);
			n = dest;
		} else {
			if (n - n%k >= 1) { 
				cont += (n%k)*A;
				n -= (n%k);
			} else {
				cont += (n-1)*A;
				n = 1;
			}
		}
	}

	printf("%lld\n", cont);

	return 0;
}
