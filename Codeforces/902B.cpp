#include <bits/stdc++.h>
#define maxn 10001

using namespace std;

vector<int> g[maxn];
int cores[maxn], cor[maxn];
int ans;

void dfs(int u, int corAtual) {
	cor[u] = corAtual;
	if (cor[u] != cores[u]) {
		ans++;
		corAtual = cores[u];
		cor[u] = corAtual;
	}

	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (!cor[v])
			dfs(g[u][i], corAtual);
	}
}

int main () {

	int n; scanf("%d", &n);

	for (int i = 2; i <= n; i++) {
		int a; scanf("%d", &a);
		g[a].push_back(i);
		g[i].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		int a; scanf("%d", &a);
		cores[i] = a;
		cor[i] = 0;
	}

	dfs(1, 0);
	printf("%d\n", ans);
	return 0;
}
