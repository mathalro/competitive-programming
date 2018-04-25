#include <bits/stdc++.h>
#define maxn 1001
#define eps 0.000000001

using namespace std;

struct eng {
	int x, y, r;
	int sent;
	int num, den;
	eng() {}
	eng(int _x, int _y, int _r) : x(_x), y(_y), r(_r), sent(-1) {}
};

vector<int> g[maxn];
int vis[maxn];
vector<eng> v;

double dist(int x1, int y1, int x2, int y2) {
	return hypot(x1-x2, y1-y2);
}

bool verifica(int i, int j) {
	return dist(v[i].x, v[i].y, v[j].x, v[j].y) - (v[i].r + v[j].r) < eps;
}

void constroi () {
	for (int i = 0; i < v.size(); i++) {
		for (int j = i+1; j < v.size(); j++) {
			if (verifica(i, j)) {
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
	}
}

void setFrac(int i) {
	int gcd = __gcd(v[0].r, v[i].r);
	v[i].num = v[0].r/gcd;
	v[i].den = v[i].r/gcd;
}

void dfs(int u, int sent) {
	vis[u] = 1;
	v[u].sent = sent;
	setFrac(u);
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (!vis[v]) {
			dfs(v, !sent);
		}
	}
}

int main () {
	int t; scanf("%d", &t);
	while (t--) {
		int n; 
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int x, y, r; scanf("%d %d %d", &x, &y, &r);
			v.push_back(eng(x, y, r));
		}
		constroi();
		dfs(0, 1);
		for (int i = 0; i < n; i++) {
			if (v[i].sent == -1) {
				printf("not moving\n");
			} else {
				if (v[i].den == 1) printf("%d ", v[i].num);
				else printf("%d/%d ", v[i].num, v[i].den);
				if (v[i].sent == 1) printf("clockwise\n");
				else printf("counterclockwise\n");
			}
			g[i].clear();
		}
		memset(vis, 0, sizeof vis);
		v.clear();
	}

	return 0;
}
