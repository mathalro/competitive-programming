#include <bits/stdc++.h>
#define maxn 101

using namespace std;

struct item {
	int valor, peso;
};

int dp[maxn][maxn];

item v[maxn];

int main () {

	int t; scanf("%d", &t);

	while (t--) {
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d %d", &v[i].valor, &v[i].peso);
		}

		int p, r; scanf("%d %d", &p, &r);
		memset(dp, 0, sizeof dp);

		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= p; j++) {
				if (v[i].peso <= j) {
					dp[i][j] = max(dp[i-1][j], v[i].valor + dp[i-1][j-v[i].peso]);
				} else {
					dp[i][j] = dp[i-1][j];
				}
			}
		}

		if (dp[n][p] >= r) {
			printf("Missao completada com sucesso\n");
		} else {
			printf("Falha na missao\n");
		}
	}
	
	return 0;
}
