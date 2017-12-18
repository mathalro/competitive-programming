#include <bits/stdc++.h>
#define maxn 301
#define maxw 10001

using namespace std;

int v[maxn];
int dp[maxn][maxw];

int main () {

	int w, n; scanf("%d %d", &w, &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", v+i);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= w; j++) {
			if (j-v[i] >= 0) {
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-v[i]] + v[i]);	
			} else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	printf("%d\n", dp[n][w]);

	return 0;
}
