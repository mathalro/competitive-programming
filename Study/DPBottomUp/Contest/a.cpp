#include <bits/stdc++.h>
#define maxn 31

using namespace std;

struct item {
	int valor, peso;
	item() {};
	item(int valor, int peso) : valor(valor), peso(peso) {}
};

int dp[maxn][maxn];
item v[maxn];

int main () {
	int n, p;

	while (scanf("%d", &n) && n) {
		scanf("%d", &p);
		for (int i = 1; i <= n; i++) {
			scanf("%d %d", &v[i].valor, &v[i].peso);
		}

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

		printf("%d min.\n", dp[n][p]);
	}

	return 0;
}
