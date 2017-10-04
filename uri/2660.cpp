#include <bits/stdc++.h>
#define maxn 10001

using namespace std;

long long __mmc(long long a, long long b) {
	return (a*b)/__gcd(a, b);
}

long long v[maxn];
int main () {
	int n, l; scanf("%d %d", &n, &l);
	for (int i = 0; i < n; i++) scanf("%d", &v[i]);

	long long mmc = __mmc(v[0], v[1]);
	for (int i = 2; i < n; i++) mmc = __mmc(mmc, v[i]);

	long long maior = mmc, ans = 1;
	for (int i = 1; i <= l; i++) {
		long long aux = __mmc(mmc, i);
		if (aux <= l && aux > maior) {
			maior = aux;
			ans = i;
		}
	}

	printf("%d\n", ans);
}
