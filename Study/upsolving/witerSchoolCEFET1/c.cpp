#include <bits/stdc++.h>
#define maxn 10001

using namespace std;

int mat[maxn][maxn], cor[maxn];
vector<int> g[maxn];

void reduz(int i, int j) {
	mat[i][j]--;
	mat[j][i]--;
	//if (mat[i][j] || mat[j][i] < 0) cout << "Menor: " << i << ' ' << j << endl;
}

int dfs(int u, int pai=-1) {
	cout << u << endl << "Lista: ";
	for (int i = 0; i < g[u].size(); i++) cout << g[u][i] << ' ';
	cout << endl;
	cor[u] = 1;
	bool entra = false;
	bool ciclo = false;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (!mat[u][v]) continue;
		if (!cor[v]) {
			entra = true;
			reduz(u, v);
			int tmp = dfs(v, u);
			if (tmp == -1) return -1;
			if (tmp == u) {
				ciclo = true;
				continue;
			}
			cor[u] = 0;
			return v;
		} else if (cor[v] == 1) {
			cout << "Ciclo " << u << ' ' << v << endl;
			cor[u] = 0;
			reduz(u, v);
			return v;
		}
	}
	if (pai == -1 && !entra) return 0;
	if (ciclo) return 0;
	return -1;
}

int main () {
	int t; scanf("%d", &t);

	while (t--) {
		int n, m; scanf("%d %d", &n, &m);
		for (int i = 0; i < m; i++) {
			int a, b; scanf("%d %d", &a, &b);
			g[a].push_back(b);
			mat[a][b]++;
			if (a != b) {
				g[b].push_back(a);
				mat[b][a]++;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << mat[i][j] << ' ';
			}	cout << endl;
		}cout << endl;

		int ans = true;
		for (int i = 0; i < n; i++) {
			if (!cor[i]) {
				if (g[i].size()) ans = dfs(i);
				if (ans == -1) {
					break;
				}
			}
		}

		if (ans != -1) printf("Yes\n");
		else printf("No\n");
		cout << endl;

		for (int i = 0; i < n; i++) {
			g[i].clear();
			cor[i] = 0;
			for (int j = 0; j < n; j++) {
				mat[i][j] = 0;
			}
		}
	}

	return 0;
}
