#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, t, x = 1;

	while (scanf("%d %d", &n, &t) && n != 0) {
		int d, p;
		int v[n+1], w[n+1], dp[t+1];
		for (int i = 1 ; i <= n; i++) scanf("%d %d", &w[i], &v[i]);

		memset(dp, 0, sizeof dp);
		for (int i = 1; i <= t; i++) {
			for (int j = 1; j <= n; j++) {
				if (i-w[j] >= 0) dp[i] = max(dp[i], dp[i-w[j]] + v[j]);
			}
		}

		printf("Instancia %d\n%d\n\n", x++, dp[t]);
	}

	return 0;
}
