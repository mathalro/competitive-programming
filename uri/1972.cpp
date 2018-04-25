#include <bits/stdc++.h>
#define maxn 501
#define inf 0x3f3f3f3f

using namespace std;

struct vertex {
	int i, j, v;
	bool operator < (vertex outro) const { return v > outro.v; }
	bool operator == (vertex outro) const {	return i == outro.i && j == outro.j; }
};

int g[maxn][maxn];
int n, m; 

int movi[] = {0, -1, 0, 1};
int movj[] = {-1, 0, 1, 0};

bool pode(int i, int j) {
	return i >= 0 && i < n && j >= 0 && j < m && g[i][j] != '#';
}

int custo(int i, int j) {
	if (isdigit((char)g[i][j])) return g[i][j]-'0';
	return 0;
}

int dijkstra(vertex s, vertex t) {
	int cost[n*m]; memset(cost, inf, sizeof cost);
	cost[m*s.i+s.j] = 0;
	priority_queue<vertex> pq;
	pq.push({s.i, s.j, 0});

	while (!pq.empty()) {
		vertex topo = pq.top(); pq.pop();
		if (topo == t) return cost[m*topo.i+topo.j];
		for (int i = 0; i < 4; i++) {
			int ii = topo.i + movi[i];
			int jj = topo.j + movj[i];
			if (pode(ii, jj)) {
				if (cost[m*ii+jj] > cost[m*topo.i+topo.j] + custo(ii, jj)) {
					cost[m*ii+jj] = cost[m*topo.i+topo.j] + custo(ii, jj);
					pq.push({ii, jj, cost[m*ii+jj]});
				}
			}			
		}
	}

	return -1;
}

int main () {
	
	scanf("%d %d", &n, &m);

	vertex s, t;
	for (int i = 0; i < n; i++) {
		string aux; cin >> aux;
		for (int j = 0; j < aux.size(); j++) {
			g[i][j] = aux[j];
			if (g[i][j] == 'H') {
				s.i = i;
				s.j = j;
			}
			if (g[i][j] == 'E') {
				t.i = i;
				t.j = j;
			}
		}
	}

	int ans = dijkstra(s, t);

	if (ans != -1) printf("%d\n", ans);
	else printf("ARTSKJID\n");

	return 0;
}
