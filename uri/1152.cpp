#include <bits/stdc++.h>
#define maxn 200001

using namespace std;

struct edge {
	int a, b, v;
};

int pai[maxn];

bool operator<(edge a, edge b) {
	return a.v <= b.v;
}

int find(int a) {
	if (a == pai[a]) return a;
	return pai[a] = find(pai[a]);
}

void unionSet(int a, int b) {
	int paiA = find(a);
	int paiB = find(b);
	pai[paiA] = pai[paiB];
}

int main () {

	int m, n; 

	while (scanf("%d %d", &m, &n) && m) {
		set<edge> S;
		for (int i = 0; i < m; i++) pai[i] = i;
		int total = 0;
		for (int i = 0; i < n; i++) {
			int a, b, c; scanf("%d %d %d", &a, &b, &c);
			total += c;
			S.insert({a, b, c});
		}
	
		int cont = 0;
		for (auto it : S) {
			if (find(it.a) != find(it.b)) {		
				cont += it.v;
				unionSet(it.a, it.b);
			}
		}

		printf("%d\n", total-cont);
	}

	return 0;
}
