/**
	Problema: Uri 1148
	accepted - 13/08/2016. Time 0.165ms
	Solução: 
		Aplicação direta de djkstra, desconsiderando as duplas de vértices que são conexos.  
**/

#include <bits/stdc++.h>
#define maxn 501
#define inf 0x3f3f3f3f

using namespace std;

struct node {
	int v, w;
	node () {}
	node(int a, int b) {
		v = a; w = b;
	}
	bool operator < (const node& outro) const {
		return w > outro.w;
	}
};

node grafo[maxn][maxn];
int distancias[maxn];
int n, m, c, k;

int djkstra(int origem, int destino) {
	memset(distancias, inf, sizeof distancias);
	priority_queue<node> q;
	q.push(node(origem, 0));
	distancias[origem] = 0;

	while(!q.empty()) {
		node topo = q.top(); q.pop();
		int u = topo.v;
		if (u == destino) {
			return distancias[destino];
		}

		for (int i = 1; i <= n; i++) {
			if (grafo[u][i].w != -1) {
				if (distancias[i] > distancias[u] + grafo[u][i].w) {
					distancias[i] = distancias[u] + grafo[u][i].w;
					q.push(node(i, distancias[i]));
				}
			}
		}
	}

	return -1;
}

int main () {
	int qtd;
		
	while(scanf("%d %d", &n, &m)) {
		if (n+m == 0) break;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				grafo[i][j].w = -1;
			}
		}
		for (int i = 1; i <= m; i++) {
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			if (grafo[y][x].w != -1) {
				grafo[y][x].w = 0;
				grafo[x][y].w = 0;
			}else {
				grafo[x][y].w = z;
			}
		}
		scanf("%d", &qtd);
		while (qtd--) {
			int x, y;
			scanf("%d %d", &x, &y);
			int res = djkstra(x, y);	
			if (res == -1) 
				printf("Nao e possivel entregar a carta\n");
			else 
				printf("%d\n", res);
		}
		puts("");
	}	

	return 0;
}