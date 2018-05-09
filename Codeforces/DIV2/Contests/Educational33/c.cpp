#include <bits/stdc++.h>
#define maxn 100001
#define inf 0x3f3f3f3f

using namespace std;

int v[maxn], visitado[maxn];
vector<int> g[maxn];
int menor;

void dfs(int pai) {
	visitado[pai] = 1;
	menor = min(menor, v[pai]);
	for (int i = 0; i < g[pai].size(); i++) {
		if (!visitado[g[pai][i]]) {
			dfs(g[pai][i]);
		}
	}
}

int main () {

	int n, m; scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);
	}

	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}

	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		menor = inf;
		if (!visitado[i]) {
			dfs(i);
			ans += menor;
		}
	}

	printf("%lld\n", ans);

	return 0;
}
