/*
 ===========================================
| uri 2446                                  |
| tema: programa programacao dinamica       |
|                                           |
 ===========================================
*/

#include <bits/stdc++.h>
#define maxn 1009

using namespace std;

int moedas[maxn];
int dp[maxn][maxn*100];

int main () {
	int v, m; scanf("%d %d", &v, &m);

	for (int i = 0; i < m; i++) {
		scanf("%d", &moedas[i+1]);
	}

	for (int i = 0; i <= m; i++) {
		dp[i][0] = 1;
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 0; j <= v; j++) {
			dp[i][j] = dp[i-1][j];
			if (moedas[i] <= j) {
				dp[i][j] |= dp[i-1][j-moedas[i]];	
			}
		}
	}

	printf(dp[m][v] ? "S\n" : "N\n");

	return 0;
}
