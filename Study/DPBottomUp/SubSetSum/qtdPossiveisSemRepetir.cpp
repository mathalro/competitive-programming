/*
 ======================================================
|  Programa que calcula de quantas maneiras é possível |
|  representar um número com um determinado conjunto,  |
|  sem repetir os valores. Coin Change.                |
 ======================================================
*/

#include <bits/stdc++.h>
#define maxn 100

using namespace std;

int dp[maxn][maxn], v[maxn];

int main () {
	int m, n; scanf("%d %d", &m, &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", v+i);
		dp[i][0] = 1;
	}

	for (int j = 0; j < m; j++) {
		dp[0][j] = 0;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (j < v[i]) {
				dp[i][j] += dp[i][j];
			} else {
				dp[i][j] += dp[i][j-v[i]] + dp[i-1][j];
			}
		}
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			printf("%2d ", dp[i][j]);
		}puts("");
	}puts("");

	return 0;
}
