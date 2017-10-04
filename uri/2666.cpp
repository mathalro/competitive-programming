#include <bits/stdc++.h>
#define maxn 10001

using namespace std;

struct no {
	int v, p;
	no() {}
	no (int v, int p) : v(v), p(p) {}
};

int n, c;
int divida[maxn];
vector<no> g[maxn];
int visitado[maxn];

int dfs(int pai) {
	visitado[pai] = 1;

	int cont = 0;
	for (int i = 0; i < g[pai].size(); i++) {
		int v = g[pai][i].v;
		int p = g[pai][i].p;
		if (!visitado[v]) {
			int percorre = dfs(v);
			divida[pai] += divida[v];
			cont += 2*p*(divida[v]/c + (divida[v]%c != 0)) + percorre;
		}
	}
	
	return cont;
}

int main () {
	scanf("%d %d", &n, &c);
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &divida[i]);
	}

	for (int i = 0; i < n-1; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		g[a].push_back(no(b, c));
		g[b].push_back(no(a, c));
	}

	printf("%d\n", dfs(1));

	return 0;
}
