#include <iostream>
#include <cstdio>
#include <vector>
#include <list>
#include <cstring>
#include <utility>
#define maxn 1001
#define inf 0x3f3f3f3f

using namespace std;

struct mv {
	int x, y, val;
	mv() {}
	mv(int _x, int _y, int _val) : x(_x), y(_y), val(_val) {}
};

struct no {
	int v, c;
	no() {}
	no(int _v, int _c) : v(_v), c(_c) {}
	bool operator<(no o) const {
		return c > o.c;
	}
	bool operator==(no o) const {
		return o.v == v && o.c == c;
	}
};

struct Bucket {
	int last, qtd;
	int count_elements;

	vector< list<no> > buckets;

	Bucket(int _qtd) {
		last = 0;
		count_elements = 0;
		qtd = _qtd;
		buckets.resize(qtd);
	}

	void insert(no element) {
		for (int i = 0; i < qtd; i++) if (!buckets[i].empty() && buckets[i].front() == element) buckets[i].pop_front();
		buckets[element.c%qtd].push_back(element);
		count_elements++;
	}

	vector<no> getCurrentBucket() {
		while(buckets[last].empty()) last = (last+1)%qtd;
		int c = buckets[last].front().c;
		vector<no> elements;		
		while (!buckets[last].empty() && buckets[last].front().c == c) {
			elements.push_back(buckets[last].front());
			buckets[last].pop_front();
			count_elements--;
		}
		last = (last+1)%qtd;
		return elements;
	}

	bool empty() {
		return count_elements == 0;
	}
};

char pant[maxn][maxn];
int c, r;

mv mov[25] = {mv(-2, -2, 7), mv(-1, -2, 6), mv(0, -2, 5), mv(1, -2, 6), mv(2, -2, 7),
							 mv(-2, -1, 6), mv(-1, -1, 3), mv(0, -1, 2), mv(1, -1, 3), mv(2, -1, 6),
						   mv(-2, 0, 5), mv(-1, 0, 2), mv(0, 0, 0), mv(1, 0, 2), mv(2, 0, 5),
							 mv(-2, 1, 6), mv(-1, 1, 3), mv(0, 1, 2), mv(1, 1, 3), mv(2, 1, 6),
							 mv(-2, 2, 7), mv(-1, 2, 6), mv(0, 2, 5), mv(1, 2, 6), mv(2, 2, 7)};

bool pode(int i, int j) {
	return i > 0 && i <= r && j > 0 && j <= c && pant[i][j] != 1;
}

int coord2vert(int i, int j) {
	return i*c + j;
}

pair<int, int> vert2coord(int pos) {
	int i = pos/c;
	int j = pos%c;
	return make_pair(i, j);
}

int heuristic(int s, int t) {
	pair<int, int> p1 = vert2coord(s);
	pair<int, int> p2 = vert2coord(t);
	return abs(p1.first-p2.first) + abs(p1.second-p2.second);
}

int dijkstra(int s, int t, vector<no> g[]) {
	int dist[r*c];
	memset(dist, inf, sizeof dist);
	Bucket pq(7);
	pq.insert(no(s, 0));

	dist[s] = 0;

	while (!pq.empty()) {
		vector<no> topo = pq.getCurrentBucket();

		for (int k = 0; k < topo.size(); k++) {
			int u = topo[k].v;
			if (u == t) {
				return dist[u];
			}
			for (int i = 0; i < g[u].size(); i++) {
				int v = g[u][i].v;
				if (dist[v] > dist[u] + g[u][i].c) {
					dist[v] = dist[u] + g[u][i].c;
					pq.insert(no(v, dist[v]));
				}
			}
		}
	}

	return -1;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	while (cin >> c >> r && c) {
		vector<no> g[r*c];
		int cf, rf, ct, rt; cin >> cf >> rf >> ct >> rt;
		int w; cin >> w;
		for (int k = 0; k < w; k++) {
			int c1, r1, c2, r2; cin >> c1 >> r1 >> c2 >> r2;
			for (int i = r1; i <= r2; i++) {
				for (int j = c1; j <= c2; j++) {
					pant[i][j] = 1;
				}
			}
		}

		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				for (int k = 0; k < 25; k++) {
					int ii = mov[k].y, jj = mov[k].x;
					if (pode(i, j) && pode(i+ii, j+jj)) {
						int a = coord2vert(i-1, j-1);
						int b = coord2vert(i+ii-1, j+jj-1);
						if (a != b) {
							g[a].push_back(no(b, mov[k].val));
						}
					}
				}
			}
		}

		int ans = dijkstra(coord2vert(rf-1, cf-1), coord2vert(rt-1, ct-1), g);
		if (ans == -1) cout << "impossible\n";
		else cout << ans << "\n";

		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				pant[i][j] = 0;
			}
		}
	}
}
