#include <bits/stdc++.h>
#define maxn 101
#define inf 0x3f3f3f3f

using namespace std;

vector<int> g[maxn];
int cor[maxn];

bool bfs() {
	memset(cor, inf, sizeof cor);
	queue<int> q; q.push(1);
	bool isBip = true;
	while (!q.empty() && isBip) {
		int u = q.front(); q.pop();
		for (int i = 0; i < g[u].size(); i++) {
			int v = g[u][i];
			if (cor[v] == inf) {
				cor[v] = !cor[u];
				q.push(v);
			} else if (cor[v] == cor[u]) {
				isBip = false; break;
			}
		}
	}
	return isBip;
}

int main () {

	int n, m; scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		g[a].push_back(b);
	}

	cout << bfs() << endl;

	return 0;
}
