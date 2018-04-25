/*

	Esse problema requer a verificação de existencia de pontes.

	Implementacao:

		Monta-se o grafo e o digrafo relativos a entrada, eliminando a rua que sera retirada pela prefeitura.

		Com o grafo, fazemos uma dfs normal, visando verificar se o grafo é conexo e se possui pontes. Se não for conexo, a resposta ja é *, pois não existe a possibilidade de criar vias. 
	
		Se o grafo for conexo, verificamos se o digrafo é fortemente conexo. Caso seja, significa que o governo não precisa fazer nada. 
		Se não for fortemente conexo verificamos se o grafo possui pontes e se estas pontes eram de mao unica. Se isso acontecer é necessario criar vias de mao duplas.
		Se não existirem pontes de mao unica, basta modificar as direções de algumas arestas (informacao do forum). 

*/


#include <bits/stdc++.h>
#define maxn 1001
#define inf 0x3f3f3f3f

using namespace std;

vector<int> g1[maxn], g2[maxn];

int d[maxn], vis[maxn], low[maxn];
int tempo, ponte, U, V, componentes;
bool conexo;
set< pair<int, int> > S;

void init() {
	memset(vis, 0, sizeof vis);
	memset(low, 0, sizeof low);
	memset(d, inf, sizeof d);
	tempo = componentes = 0;
	conexo = true;
}

void dfsU(int u, int p) {
	vis[u] = 1;
	d[u] = low[u] = tempo++;
	for (int i = 0; i < g2[u].size(); i++) {
		int v = g2[u][i];
		if (!vis[v]) {
			dfsU(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] > d[u]) {
				if (S.find(make_pair(v, u)) == S.end() || S.find(make_pair(u, v)) == S.end()) {
					ponte = 1;
				}
			}
		} else if (v != p) {
			low[u] = min(low[u], d[v]);
		}
	}
}

void dfsD(int u, int p=-1) {
	vis[u] = 1;
	d[u] = low[u] = tempo++;
	for (int i = 0; i < g1[u].size(); i++) {
		int v = g1[u][i];
		if (!vis[v]) {
			dfsD(v, u);
			low[u] = min(low[u], low[v]);
		} else  {
			low[u] = min(low[u], d[v]);
		}
	}

	if (low[u] >= d[u]) {
		componentes++;
		low[u] = d[u] = inf;
	}
}

int main () {

	int n, m;

	while (scanf("%d %d", &n, &m) != EOF) {
		for (int i = 0; i < m; i++) {
			int a, b, t; scanf("%d %d %d", &a, &b, &t);
			if (!i) continue;
			S.insert(make_pair(a, b));
			g2[a].push_back(b);
			g2[b].push_back(a);
			g1[a].push_back(b);
			if (t == 2) {
				S.insert(make_pair(b, a));
				g1[b].push_back(a);
			}
		}

		init();
		ponte = 0;
		dfsU(1, -1);
		for (int i = 1; i <= n; i++) {
			if (!vis[i]) {
				conexo = false;
				break;
			}
		}

		if (!conexo) {
			printf("*\n");
		} else {
			init();
			for (int i = 1; i <= n; i++) {
				tempo = 0;
				if (!vis[i]) dfsD(i);
			}

			if (componentes == 1) {
				printf("-\n");
			} else {
				if (ponte) {
					printf("2\n");
				} else {
					printf("1\n");
				}
			}
		}

		for (int i = 1; i <= n; i++) {
			g1[i].clear();
			g2[i].clear();
		}
		S.clear();
	}

	return 0;
}
