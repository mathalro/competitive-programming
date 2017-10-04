#include <bits/stdc++.h>
#define maxn 1009
#define maxt 2009
#define inf 0x3f3f3f3f

using namespace std;

int v[maxn], c[maxn];
int dp[maxn][maxt];

int n, t;

int f(int i, int cont) {
	if (i >= n) return 0;

	if (dp[i][cont] != -1) return dp[i][cont];

	int maior = f(i+1, cont);

	if (c[i]+cont <= t) {
		maior = max(maior, f(i, cont+c[i])+v[i]);
	}

	return dp[i][cont] = maior;
}

int main () {
	scanf("%d %d", &n, &t);

	for (register int i = 0; i < n; i++) {
		scanf("%d %d", &c[i], &v[i]);
	}

	memset(dp, -1, sizeof dp);

	printf("%d\n", f(0, 0));

	return 0;
}
