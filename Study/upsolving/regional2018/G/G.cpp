#include <bits/stdc++.h>
#define maxn 1001
#define inf 0x3f3f3f3f

using namespace std;

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
		for (int i = 1; i <= t; i++) {
			if (i != u && !vis[i] && gr[u][i] > 0) {
				vis[i] = 1;
				pai[i] = u;
				q.push(i);
			}
		}
	}

	if (pai[t] == inf) return 0;

	int gargalo = inf;

	int tmp = t;

	while (pai[tmp] != -1) {
		gargalo = min(gargalo, gr[pai[tmp]][tmp]);
		tmp = pai[tmp];
	}

	tmp = t;
	while (pai[tmp] != -1) {
		gr[pai[tmp]][tmp] -= gargalo;
		gr[tmp][pai[tmp]] += gargalo;
		tmp = pai[tmp];
	}

	return gargalo;
}

bool flow(int cost) {
	for (int i = 1; i <= r; i++) {
		for (int j = r+1; j < t; j++) {
			if (g[i][j] <= cost) {
				gr[i][j] = inf;
			} else {
				gr[i][j] = 0;	
			}
		}
	}

	for (int i = 1; i <= r; i++) gr[0][i] = g[0][i];
	for (int i = r+1; i < t; i++) gr[i][t] = g[i][t];

	int cont = 0;
	while (1) {
		int gargalo = bfs();
		if (!gargalo) return cont >= demanda;
		cont += gargalo;
	}
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

	int l = 1, r = maior;
	while (l < r) {
		int mid = (l+r)>>1;
		if (flow(mid)) {
			r = mid;
		} else {
			l = mid+1;
		}
	}

	printf("%d\n", r);

	return 0;
}










