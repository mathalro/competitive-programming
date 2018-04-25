#include <bits/stdc++.h>
#define maxn 55
#define inf 0x3f3f3f3f

using namespace std;

int l, n;
int v[maxn];
int dp[1001][1001];

int f(int l, int r) {
	if (dp[l][r] != -1) return dp[l][r];
	if (l+1 == r) return dp[l][r] = 0;
	int menor = inf;
	for (int i = l+1; i < r; i++) {
		menor = min(menor, f(l, i) + f(i, r) + v[r]-v[l]);
	}
	return dp[l][r] = menor;
}

int main () {

	while (scanf("%d", &l) && l) {
		scanf("%d", &n);
		v[0] = 0;
		v[n+1] = l;
		memset(dp, -1, sizeof dp);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &v[i]);
		}

		int ans = f(0, n+1);
		printf("The minimum cutting is %d.\n", ans);
	}
	return 0;
}
