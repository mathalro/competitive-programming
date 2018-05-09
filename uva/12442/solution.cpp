#include <iostream>
#include <algorithm>
#include <cstring>
#define maxn 50001

using namespace std;

int g[maxn];
int vis[maxn];
int d[maxn];

int dfs(int u) {
	vis[u] = 1;
	int v = g[u];

	if (vis[v] == 1) {
		int cont = 1;
		int uu = g[v];
		while (uu != v) {
			cont++;
			uu = g[uu];
		}
		d[v] = cont;
		uu = g[v];
		while (uu != v) {
			d[uu] = cont;
			uu = g[uu];
		}
	} else if (!vis[v]){
		dfs(v);
		if (d[u] == 0) d[u] = 1 + d[v];
	} else {
		d[u] = 1 + d[v];
	}

	vis[u] = 2;
}

int main () {

	int t; scanf("%d", &t);
	int ini = t;
	while (t--) {
		int n; scanf("%d", &n);	

		memset(vis, 0, sizeof vis);
		memset(d, 0, sizeof d);

		for (int i = 0; i < n; i++) {
			int u, v; scanf("%d %d", &u, &v);
			g[u-1] = v-1;
		}

		for (int i = 0; i < n; i++) {
			if (!vis[i])
				dfs(i);
		}

		printf("Case %d: %d\n", ini-t, distance(d, max_element(d, d+n))+1);
	}

	return 0;
}
