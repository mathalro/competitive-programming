/**
	Problema: Josephus
	accepted: 0.0000 ms
	Aplicação direta da formula do problema de josephus.
**/
#include <bits/stdc++.h>

using namespace std;

int k;

int f(int n) {
	if (n == 1) return 1;
	return (f(n-1)+k-1)%n + 1;
}

int main () {
	int nc, n, res;
	scanf("%d", &nc);

	for (int i = 0; i < nc; i++) {
		scanf("%d %d", &n, &k);


		printf("Case %d: %d\n", i+1, f(n));
	}

	return 0;
}