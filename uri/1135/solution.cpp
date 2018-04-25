#include <bits/stdc++.h>
#define maxn 100009

using namespace std;

int pai[maxn], peso[maxn], nivel[maxn];

long long lca(int a, int b) {
	long long cont = 0;
	if (nivel[a] < nivel[b]) swap(a, b);

	while (nivel[a] != nivel[b]) {
		cont += peso[a];
		a = pai[a];
	}	

	while (a != b) {
		cont += peso[a] + peso[b];
		a = pai[a]; b = pai[b];
	}

	return cont;
}

int main () {
	int n; 
	while (scanf("%d", &n) && n) {
		nivel[0] = 0;
		for (int i = 1; i < n; i++) {
			int a, l; scanf("%d %d", &a, &l);
			pai[i] = a;
			peso[i] = l;
			nivel[i] = nivel[a]+1;
		}

		int q; scanf("%d", &q);

		for (int i = 0; i < q; i++) {
			int a, b; scanf("%d %d", &a, &b);
			printf("%lld", lca(a, b));
			if (i < q-1) printf(" ");
		}puts("");
	}
}
