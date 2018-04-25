#include <bits/stdc++.h>
#define maxn 500
#define inf 0x3f3f3f3f

using namespace std;

struct point {
	double x, y, v;
	point() {}
	point(double _x, double _y) : x(_x), y(_y) {}
};

struct vertex {
	int i;
	double v;
	bool operator <(vertex outro) const {
		return v > outro.v;
	}
};

vector<point> v;
vector<vertex> g[maxn];

int n;

double dist(point a, point b) {
	return hypot(a.x-b.x, a.y-b.y);
}

double prim(int p) {
	double ans = 0.0;
	priority_queue<vertex> pq;
	int vis[n];
	double dis[n];
	for (int i = 0; i < n; i++) {
		vis[i] = 0;
		dis[i] = inf;
	}
	pq.push({0, 0.0});

	while (!pq.empty()) {
		vertex u = pq.top(); pq.pop();
		if (!vis[u.i]) ans += u.v;		
		vis[u.i] = 1;
		for (int i = 0; i < g[u.i].size(); i++) {
			int v = g[u.i][i].i;
			if (!vis[v] && g[u.i][i].v < dis[v]) {
				dis[v] = g[u.i][i].v;
				pq.push({v, g[u.i][i].v});
			}
		}
	}
	return ans;
}

int main () {
	int t; scanf("%d", &t);

	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			double x, y; scanf("%lf %lf", &x, &y);
			v.push_back(point(x, y));		
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i != j) {
					double tmp = dist(v[i], v[j]);
					g[i].push_back({j, tmp});
					g[j].push_back({i, tmp});
				}
			}
		}

		printf("%.2lf\n", prim(0)/100.0);
		for (int i = 0; i < n; i++) {
			g[i].clear();
		}
		v.clear();
	}

	return 0;
}
