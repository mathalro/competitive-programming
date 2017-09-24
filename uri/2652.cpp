#include <bits/stdc++.h>
#define maxn 49

using namespace std;

int n;
vector<int> g[maxn];
set< vector< multiset<int> > > S;

vector< multiset<int> > bfs(int pai) {
	vector< multiset<int> > niveis(maxn);
	int visitado[maxn], nivel[maxn];
	memset(visitado, 0, sizeof visitado);
	memset(nivel, 0, sizeof nivel);
	queue<int> q;
	q.push(pai);
	visitado[pai] = 1;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		int cont = 0;
		for (int i = 0; i < g[u].size(); i++) {
			int v = g[u][i];
			if (!visitado[v]) {
				cont++;
				visitado[v] = 1;
				nivel[v] = nivel[u]+1;
				q.push(v);
			}
		}
		if (cont) {
			niveis[nivel[u]].insert(cont);
		}
	}

	return niveis;
}

int main () {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int m; scanf("%d", &m);
		for (int i = 2; i <= m; i++) {
			int a; scanf("%d", &a);
			g[i].push_back(a);
			g[a].push_back(i);
		}

		S.insert(bfs(1));

		for (int i = 0; i < maxn; i++) {
			g[i].clear();
		}
	}

	printf("%u\n", S.size());
} 
