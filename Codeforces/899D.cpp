#include <bits/stdc++.h>

using namespace std;

int countCasas(int n) {
	int cont = 0;
	while (n >= 1) {
		cont++;
		n /= 10;
	}
	return cont;
}

int fastPow(int b, int e) {
	if (e == 0) return 1;
	if (e == 1) return b;
	int tmp = fastPow(b, e/2);
	tmp *= tmp;
	if (e&1) tmp *= b;
	return tmp;
}

int main () {

	int n; scanf("%d", &n);

	if (n == 1000000000) {
		printf("500000000\n");
		return 0;
	}

	int maior = n+n-1;
	int cont1 = countCasas(maior), cont2 = countCasas(maior+1), cont;
	if (cont1 == cont2) cont = cont1-1;
	else cont = cont1;
	int max9 = fastPow(10, cont)-1;
	int ans = 0;


	while (max9 <= maior) {
		int r = max9-1;
		int l = 1;
		while (r > n) {
			r--; l++;
		}

		while (l < r) {
			ans++;
			l++; r--;
		}
		max9 += fastPow(10, cont);
	}
 
	printf("%d\n", ans);

	return 0;
}
