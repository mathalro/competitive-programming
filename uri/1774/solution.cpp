#include <bits/stdc++.h>
#define maxn 61

using namespace std;

struct edge {
	int u, v, p;
	bool operator < (edge a) const {
		return p <= a.p;
	}
};

set<edge> S;
int pai[maxn];

int find(int a) {
	if (a == pai[a]) return a;
	return pai[a] = find(pai[a]);
}

void unionSet(int a, int b) {
	int paiA = find(a);
	int paiB = find(b);

	pai[paiA] = paiB;
} 

int main () {

	int r, c; scanf("%d %d", &r, &c);

	for (int i = 0; i < c; i++) {
		int u, v, p; scanf("%d %d %d", &u, &v, &p);
		S.insert({u, v, p});
		S.insert({v, u, p});
	}

	for (int i = 1; i <= r; i++) pai[i] = i;

	int ans = 0;
	for (set<edge>::iterator it = S.begin(); it != S.end(); it++) {
		if (find(it->u) != find(it->v)) {
			ans += it->p;
			unionSet(it->u, it->v);
		}
	}	

	printf("%d\n", ans);

	return 0;
}
