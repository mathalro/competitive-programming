#include <bits/stdc++.h>
#define maxn 100009

using namespace std;

vector<int> g[maxn], divs;
int visitado[maxn], d[maxn], low[maxn], st[maxn], ocorrencias[maxn];
int sn, tempo;

void dfs(int u) {
	visitado[u] = 1;
	st[sn++] = u;
	d[u] = low[u] = tempo++;
	for (int v : g[u]) {
		if (!visitado[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		}	else {
			low[u] = min(low[u], d[v]);
		}
	}

	if (low[u] >= d[u]) {
		int cont = 0;
		do {
			cont++;
			--sn;
		} while (st[sn] != u);
		divs.push_back(cont);
	}
}

long long lcm(long long a, long long b) {
	return (a*b)/__gcd(a, b);
}

int main () {
	
	int n; scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		int a; scanf("%d", &a);
		g[i].push_back(a);
		ocorrencias[a]++;
		if (ocorrencias[a] > 1) {
			puts("-1");
			return 0;
		}
	}

	tempo = sn = 0;
	for (int i = 1; i <= n; i++) {
		if (!visitado[i]) {
			dfs(i);
		}
	}

	long long ans = 1;
	if (divs.size() > 1) {
		for (int i = 0; i < divs.size(); i++) {
			ans = lcm(ans, divs[i]);
		}
	} else {
		ans = divs[0];
	}

	printf("%lld\n", ans);

	return 0;
}
