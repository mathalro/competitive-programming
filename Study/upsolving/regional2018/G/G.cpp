#include <bits/stdc++.h>
#define maxn 1001
#define inf 0x3f3f3f3f

using namespace std;

struct edge {
	int v, p;
};

vector<int> qp, qr;
int g[maxn][maxn], gr[maxn][maxn];
int s, t, demanda;
int p, r, c;

int bfs() {
	int vis[t+1], pai[t+1];
	memset(vis, 0, sizeof vis);
	memset(pai, inf, sizeof pai);
	queue<int> q;
	q.push(s);
	vis[s] = 1;
	pai[s] = -1;

	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (u == t) break;
		for (int i = 1; i < t; i++) {
			if (!vis[i] && gr[u][i] > 0) {
				vis[i] = 1;
				pai[i] = u;
				q.push(i);
			}
		}
	}
	
	int gargalo = inf;

	int tmp = t;

	while (pai[tmp] != -1) {
		tmp = pai[tmp];
		gargalo = min(gargalo, gr[pai[tmp]][tmp]);
	}

	tmp = t;
	while (pai[tmp] != -1) gr[pai[tmp]][tmp] -= gargalo;

	return gargalo;
}

bool flow(int cost) {
	for (int i = 0; i < p+r+1; i++)
		for (int j = 0; j < p+r+1; j++)
			gr[i][j] = g[i][j];

	int cont = 0;
	while (1) {
		int gargalo = bfs();
		if (gargalo > cost) return false;
		if (!gargalo) return cont >= demanda;
		cont += gargalo;
	}
}

int main () {
	
	scanf("%d %d %d", &p, &r, &c);
	int maior = -inf;
	t = r+p;

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

	int ans = 0;
	int l = 1, r = maior;

	while (l < r) {
		int mid = (l+r)<<1;
		if (flow(mid)) {
			r = mid;
		} else {
			l = mid+1;
		}
	}

	printf("%d", r);

	return 0;
}










