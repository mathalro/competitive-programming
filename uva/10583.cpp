#include <bits/stdc++.h>
#define maxn 50001

using namespace std;

int pai[maxn];
int n, m;

int find(int a) {
	if (a == pai[a]) return a;
	return pai[a] = find(pai[a]);
}

void uniao(int a, int b) {
	int paiA = find(a);
	int paiB = find(b);
	pai[paiA] = paiB;
}

int main () {
	int i = 1;
	while (scanf("%d %d", &n, &m) && n) {
		for (int i = 1; i <= n; i++) pai[i] = i;
		for (int i = 0; i < m; i++) {
			int a, b; scanf("%d %d", &a, &b);
			uniao(a, b);
		}
		
		set<int> S;
		for (int i = 1; i <= n; i++) {
			S.insert(find(i));
		}
		
		printf("Case %d: %d\n", i++, S.size());
	}

	return 0;
}
