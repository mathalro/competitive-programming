#include <bits/stdc++.h>
#define maxn 42
#define inf 0x3f3f3f3f
#define SOURCE 40
#define SINK 41

using namespace std;

int grafo[maxn][maxn], pontos[maxn], n, m, g, necessidade;

int pais[maxn];
bool visitado[maxn];


void direciona() {
	necessidade = 0;
	for (int u=1;u<n;++u){
		for(int adj=1; adj<n;++adj){
			if(grafo[u][adj]){
				pontos[u] += grafo[u][adj];
				grafo[adj][u] = 0;
			}
		}

		if(pontos[u] >= pontos[0]){
			necessidade += pontos[u] - pontos[0] + 1;
			grafo[SOURCE][u] = pontos[u] - pontos[0] +1;
		} else {
			grafo[u][SINK] = pontos[0] - pontos[u] -1;
		}
	}
}

int bfs() {
	int gargalo = inf, u;
	memset(visitado, 0, sizeof visitado);
	memset(pais, 0, sizeof pais);
	pais[SOURCE] = SOURCE;
	queue<int> q;
	q.push(SOURCE);
	visitado[SOURCE] = 1;

	while (!q.empty()) {
		u = q.front(); q.pop();
		if (u == SINK) break;
		for (int i = 1; i < maxn; i++) {
			if (grafo[u][i] && !visitado[i]) {
				pais[i] = u;
				visitado[i] = 1;
				q.push(i);
			}
		}
	}

	if (u == SINK) {
		while (u != SOURCE) {
			gargalo = min(gargalo, grafo[pais[u]][u]);
			u = pais[u];
		}

		u = SINK;
		while (u != SOURCE) {
			grafo[pais[u]][u] -= gargalo;
			grafo[u][pais[u]] += gargalo;
			u = pais[u];
		}

		return gargalo;
	}

	return 0;
}

int fluxomax(){
	int gargalo, fluxoMaximo = 0;
	while (1) {
		gargalo = bfs();
		if (gargalo == 0) {
			return fluxoMaximo;
		}
		fluxoMaximo += gargalo;
	}
}

int main() {
	while(scanf("%d %d %d", &n, &m, &g) && n) {
		memset(pontos, 0, sizeof pontos);
		memset(grafo, 0, sizeof grafo);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if(i != j) grafo[i][j] = grafo[j][i] = 2*m;
			}
		}
		for(int i = 0; i < n; ++i){
			grafo[SOURCE][i] = grafo[SINK][i] = 0;
			grafo[i][SOURCE] = grafo[i][SINK] = 0;
		}

		for (int i = 0; i < g; i++) {
			int a, b;
			char c;
			scanf("%d %c %d", &a, &c, &b);
			grafo[a][b] = grafo[b][a] = grafo[a][b] - 2;
			if (c == '<') {
				pontos[b] += 2;
			}else if (c == '>') {
				pontos[a] += 2;
			}else {
				pontos[a] += 1;
				pontos[b] += 1;
			}
		}


		for (int i = 0; i < n; i++) {
			if (grafo[0][i]) {
				pontos[0] += grafo[0][i];
				grafo[0][i] = grafo[i][0] = 0; 
			}
		}
		
		direciona();

		if (fluxomax() >= necessidade) {
			printf("Y\n");
		}else {
			printf("N\n");
		}
	}

	return 0;
}