#include <bits/stdc++.h>

using namespace std;

int main () {

	long long A, B; scanf("%lld %lld", &A, &B);
	long long y, g, b; scanf("%lld %lld %lld", &y, &g, &b);

	long long cont = 0;

	A -= 2*y;
	B -= 3*b;

	if (A < 0) {
		cont += -A;
		A = 0;
	}
	if (B < 0) {
		cont += -B;
		B = 0;
	}

	A -= g;
	B -= g;

	if (A < 0) cont += -A;
	if (B < 0) cont += -B;

	printf("%lld\n", cont);

	return 0;
}
