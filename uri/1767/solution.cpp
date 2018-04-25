#include <bits/stdc++.h>
#define maxp 50

using namespace std;

int main () {
	
	int t; scanf("%d", &t);

	while (t--) {
		int n; scanf("%d", &n);
		int v[n+1], w[n+1], dp[n+1][maxp+1];

		for (int i = 1; i <= n; i++) scanf("%d %d", v+i, w+i);

		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= maxp; j++) {
				if (i == 0 || j == 0) dp[i][j] = 0;
				else if (j-w[i] >= 0) dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
				else dp[i][j] = dp[i-1][j];
			}
		}

		int i = n, j = maxp;
		int peso = 0;
		int qtd = 0;
		while (i != 0) {
			if (dp[i][j] != dp[i-1][j]) {
				peso += w[i];
				qtd += 1;
				j -= w[i];
			}	
			i--;
		}

		printf("%d brinquedos\n", dp[n][maxp]);
		printf("Peso: %d kg\n", peso);
		printf("sobra(m) %d pacote(s)\n", n-qtd);
		puts("");
	}

	return 0;
}
