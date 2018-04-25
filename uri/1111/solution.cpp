#include <bits/stdc++.h>
#define maxn 11
#define inf 0x3f3f3f3f

using namespace std;

int g[maxn*maxn][maxn*maxn];
int movi[] = {-1, 1, 0, 0};
int movj[] = {0, 0, -1, 1};


int main () {

	int n, DIR = 4;
	while (scanf("%d", &n) && n) {
		memset(g, inf, sizeof g);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int origem = n*i + j;
				for (int k = 0; k < DIR; k++) {
					int a; scanf("%d", &a);
					if (a) {
						int destino = (n)*(movi[k]+i) + j+movj[k];
						g[origem][destino] = 1;
					}
				}
			}
		}
		
		int N = n*n;

		// floyd-warshal to find the min path between all pairs of vertices
		for (int i = 0; i < N; i++) g[i][i] = 0;
		for (int k = 0; k < N; k++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
				}
			}
		}

		int m; scanf("%d", &m);

		for (int i = 0; i < m; i++) {
			int x0, y0, x1, y1; scanf("%d %d %d %d", &x0, &y0, &x1, &y1);
			int origem = (n-y0-1)*n + x0;
			int destino = (n-y1-1)*n + x1;
			if (g[origem][destino] >= inf) printf("Impossible\n");
			else printf("%d\n", g[origem][destino]);
		}
		puts("");
	}

	return 0;
}
