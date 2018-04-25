/*
	accepted
*/
#include <bits/stdc++.h>
#define maxn 1000009

using namespace std;

int bit[maxn];
vector<int> primos;

void crivo() {
	for (long long i = 2; i < maxn; i++) {
		if (!bit[i]) {
			primos.push_back(i);
			for (long long j = i*i; j < maxn; j += i) {
				bit[j] = 1;
			}
		}
	}
}

unsigned long long fat(int n) {
	unsigned long long cont = 1, i = 2;
	while (i <= n) {
		cont *= i;
		i++;
	}
	return cont;
}

unsigned long long comb(int n, int p) {
	return fat(n)/(fat(n-p)*fat(p));
}

int main () {

	crivo();

	unsigned long long n; scanf("%lld", &n);

	int i = 0, divs = 0;
	while (n >= 1 && i < primos.size()) {
		int cont = 0;
		while ((n%primos[i]) == 0) {
			cont++;
			n /= primos[i];
		}
		divs += (cont>0);
		i++;
	}

	if (n > 1) divs++;

	if (divs < 2) {
		printf("0\n");
	} else {
		unsigned long long ans = 0;
		for (int i = 2; i <= divs; i++) {
			ans += comb(divs, i);
		}
		printf("%llu\n", ans);
	}

	return 0;
}
