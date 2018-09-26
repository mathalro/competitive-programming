#include <bits/stdc++.h>
#define maxn 2050
#define inf 0x3f3f3f3f

using namespace std;

int g[maxn][maxn], gr[maxn][maxn];
vector<int> gg[maxn];
int s, t, demanda;
int p, r, c;
int level[maxn];

bool bfs(int s, int t) {
    memset(level, -1, sizeof level);
    queue<int> q;
    q.push(s); level[s] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 0; i < gg[u].size(); i++) {
			int v = gg[u][i];
            if (level[v] < 0 && gr[u][v]) {
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
    return level[t] < 0 ? false : true;
}

int dfs(int u, int t, int flow) {
    if (u == t) return flow;
    for (int i = 0; i < gg[u].size(); i++) {
		int v = gg[u][i];
        if (level[v] == level[u]+1 && gr[u][v]) {
            int f = min(flow, gr[u][v]);
            int gargalo = dfs(v, t, f);
            if (gargalo > 0) {
                gr[u][v] -= gargalo;
                gr[v][u] += gargalo;
				gg[v].push_back(u);
                return gargalo;
            }
        }
    }
    return 0;
}

bool flow(int cost) {
	memset(gr, 0, sizeof gr);
	for (int i = 0; i <= t; i++) gg[i].clear();

	for (int i = 1; i <= r; i++) {
		for (int j = r+1; j < t; j++) {
			if (g[i][j] && g[i][j] <= cost) {
				gr[i][j] = inf;
				gg[i].push_back(j);
			} else {
				gr[i][j] = 0;
			}
		}
	}

	for (int i = 1; i <= r; i++) {
		gr[0][i] = g[0][i];
		gg[0].push_back(i);
	}
	for (int i = r+1; i < t; i++) {
		gr[i][t] = g[i][t];
		gg[i].push_back(t);
	}

	/*for (int i = 0; i <= t; i++) {
		printf("%d -> ", i);
		for (int j = 0; j < gg[i].size(); j++) {
			printf("[%d,%d] ", gg[i][j],gr[i][gg[i][j]]);
		}puts("");
	}puts("");*/

    int flow = 0;
	while (bfs(s, t)) {
        while (int gargalo = dfs(s, t, inf)) {
			flow += gargalo;
		}
    }

    return flow >= demanda;

}

int main () {
	scanf("%d %d %d", &p, &r, &c);
	int maior = -inf;
	t = r+p+1;

	for (int i = 0; i < p; i++) {
		int a; scanf("%d", &a);
		g[i+r+1][t] = a;
		demanda += a;
	}
	for (int i = 0; i < r; i++) {
		int a; scanf("%d", &a);
		g[0][i+1] = a;
	}

	for (int i = 0; i < c; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		maior = max(maior, c);
		g[b][a+r] = c;
	}

	int l = 1, r = maior+1;
	
	while (l < r) {
		int mid = (l+r)>>1;
		if (flow(mid)) {
			r = mid;
		} else {
			l = mid+1;
		}
	}

	printf("%d\n", r > maior ? -1 : r);

	return 0;
}

