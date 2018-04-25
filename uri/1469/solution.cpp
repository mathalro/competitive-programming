#include <bits/stdc++.h>
#define maxn 501
#define inf 0x3f3f3f3f

using namespace std;

vector<int> v;
int g[maxn][maxn];
int vis[maxn], ans, uu;
int n, m, I; 

void dfs(int u) {
	if (u != uu) ans = min(ans, v[u]);
	vis[u] = 1;
	for (int i = 1; i <= n; i++) {
		if (g[u][i] && !vis[i]) {
			dfs(i);
		}	
	}
}

int main () {
	while (scanf("%d %d %d", &n, &m, &I) != EOF) {
		v.push_back(0);
		for (int i = 0; i < n; i++) {
			int a; scanf("%d", &a);
			v.push_back(a);
		}
		for (int i = 0; i < m; i++) {
			int a, b; scanf("%d %d", &a, &b);
			g[b][a] = 1;
		}
		for (int i = 0; i < I; i++) {
			char c; scanf(" %c", &c);
			if (c == 'P') {
				scanf("%d", &uu);
				ans = inf;
				memset(vis, 0, sizeof vis);
				dfs(uu);
				if (ans != inf) printf("%d\n", ans);
				else printf("*\n");
			}	else {
				int a, b; scanf("%d %d", &a, &b);
				for (int i = 1; i <= n; i++) {
					if (g[i][a] && !g[i][b]) {
						g[i][a] = 0;
						g[i][b] = 1;
					} else if (g[i][b] && !g[i][a]) {
						g[i][b] = 0;
						g[i][a] = 1;
					}
				}
				for (int j = 1; j <= n; j++) {
					if (g[a][j] && !g[b][j]) {
						g[a][j] = 0;
						g[b][j] = 1;
					} else	if (g[b][j] && !g[a][j]) {
						g[b][j] = 0;
						g[a][j] = 1;
					}
				}
			}
		}
		memset(g, 0, sizeof g);
		v.clear();
	}
	
	return 0;
}
