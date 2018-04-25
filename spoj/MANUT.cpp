#include <bits/stdc++.h>
#define maxn 401

using namespace std;

vector<int> g[maxn], v;
int vis[maxn], d[maxn], low[maxn], c[maxn], tempo;

void dfs(int u, int p) {
	vis[u] = 1;
	c[u] = 0;
	d[u] = low[u] = tempo++;
	bool any = false;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (!vis[v]) {
			c[u]++;
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] >= d[u] && p != -1) any = true;
		} else if (v != p) {
			low[u] = min(low[u], d[v]);
		}
	}

	if (any || (p == -1 && c[u] > 1)) v.push_back(u);
}

int main () {

	int n, m;
	int t = 1;

	while (scanf("%d %d", &n, &m) && n) {
		for (int i = 0; i < m; i++) {
			int a, b; scanf("%d %d", &a, &b);
			g[a-1].push_back(b-1);
			g[b-1].push_back(a-1);
		}

		printf("Teste %d\n", t++);

		memset(vis, 0, sizeof vis);
		tempo = 0;
		dfs(0, -1);

		if (!v.size()) printf("nenhum\n\n");
		else {
			sort(v.begin(), v.end());
			printf("%d", v[0]+1);
			for (int i = 1; i < v.size(); i++) {
				printf(" %d", v[i]+1);
			}
			printf("\n\n");
		}

		for (int i = 0; i < n; i++) {
			g[i].clear();
		}
		v.clear();
	}

	return 0;
}
