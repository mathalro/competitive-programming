#include <bits/stdc++.h>
#define maxn 101

using namespace std;

vector<int> g[maxn];
int visitado[maxn];
int cor[maxn];
int nivel[maxn];
int cont = 0;

int dfs(int pai, int n) {
	nivel[pai] = n;
	cor[pai] = 1;
	for (int i = 0; i < g[pai].size(); i++) {
		int v = g[pai][i];
		if (cor[v] == 1) {
			if (nivel[pai]-nivel[v] > 1) {
				cont++;
				continue;
			}
		}	
		if (!cor[v]) {
			dfs(v, n+1);
		}
	}

	cor[pai] = 2;
}

int main () {
	int n, m; scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}


	dfs(1, 1);

	for (int i = 1; i <= n; i++) {
		if (!cor[i]) {
			printf("NO\n");
			return 0;
		}
	}

	if (cont == 1) {
		printf("FHTAGN!\n");
	} else {
		printf("NO\n");
	}

	return 0;
}
