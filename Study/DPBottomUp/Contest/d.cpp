#include <bits/stdc++.h>
#define maxn 109

using namespace std;

int dp[maxn][maxn][maxn];
int p[maxn][3];

int main () {

	int n;

	while (scanf("%d", &n) && n) {
		
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 3; j++) {
				scanf("%d", &p[i][j]);
			}
		}

		memset(dp, 0, sizeof dp);
		dp[0][0][0] = 1;
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				for (int k = 0; k <= n; k++) {
					if (i > 0 && p[i][0]%3 == 0) dp[i][j][k] |= dp[i-1][j][k];
					if (j > 0 && p[j][1]%3 == 0) dp[i][j][k] |= dp[i][j-1][k];
					if (k > 0 && p[k][2]%3 == 0) dp[i][j][k] |= dp[i][j][k-1];
					if (i > 0 && j > 0 && (p[i][0] + p[j][1])%3 == 0) dp[i][j][k] |= dp[i-1][j-1][k];
					if (i > 0 && k > 0 && (p[i][0] + p[k][2])%3 == 0) dp[i][j][k] |= dp[i-1][j][k-1];
					if (j > 0 && k > 0 && (p[j][1] + p[k][2])%3 == 0) dp[i][j][k] |= dp[i][j-1][k-1];
					if (i > 0 && j > 0 && k > 0 && (p[i][0] + p[j][1] + p[k][2])%3 == 0) {					
						dp[i][j][k] |= dp[i-1][j-1][k-1];
					}
				}
			}
		}

		printf("%d\n", dp[n][n][n]);
	}

	return 0;
}
