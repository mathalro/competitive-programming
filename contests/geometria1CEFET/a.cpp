#include <bits/stdc++.h>
#define EPS 0.000000001

using namespace std;

int main () {
	unsigned long long int n;
	while (scanf("%llu", &n) && n != (unsigned long long)(-1)) {
		if (n < EPS) printf("0\n");
		else printf("%llu\n", n-1);
	}

	return 0;
}
