#include <bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f

using namespace std;

int main () {

	unsigned long long n, k; scanf("%llu %llu", &n, &k);

	unsigned long long ans = 0;
	unsigned long long menor = inf;
	unsigned long long qtd = 0;
	
	for (int i = 1; i <= k; i++) {
		unsigned long long a; scanf("%llu", &a);
		if (a <= n && n%a < menor) {
			menor = n%a;
			ans = i;
			qtd = n/a;
		}
	}

	if (ans == 0) printf("1 0\n");
	else printf("%llu %llu\n", ans, qtd);

	return 0;
}
