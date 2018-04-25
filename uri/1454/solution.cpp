#include <bits/stdc++.h>
#define maxn 101
#define inf 0x3f3f3f3f

using namespace std;

int g[maxn][maxn];

int main () {

	int n, m;
	int inst = 1;
	while (scanf("%d %d", &n, &m) && n) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) g[i][j] = 0;
				else g[i][j] = inf;
			}
		}
		for (int i = 0; i < m; i++) {
			int a, b, c; scanf("%d %d %d", &a, &b, &c);
			a--; b--;
			g[a][b] = c;
			g[b][a] = c;
		}

		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					g[i][j] = min(g[i][j], max(g[i][k], g[k][j]));
				}
			}
		}

		int k; scanf("%d", &k);
		printf("Instancia %d\n", inst++);
		for (int i = 0; i < k; i++) {
			int s, t; scanf("%d %d", &s, &t);
			if (s == t) printf("0\n");
			else printf("%d\n", g[s-1][t-1]);
		}
		puts("");
	}

	return 0;
}
