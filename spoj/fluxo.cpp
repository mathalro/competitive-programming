"""
	spoj 
	accept 09/09/2016
	time: 0.0
	memoria: 3.4M
	solução: Fluxo máximo, algoritmo Edemons Karp. 
			 Vale lembrar que os vértices estão contidos no conjunto [A-Za-z]
"""

#include <bits/stdc++.h>
#define maxn 52
#define inf 0x3f3f3f3f

using namespace std;

int grafo[maxn][maxn];
int visitado[maxn];
int pais[maxn];

int n;

int bfs(int origem, int destino) {
	int gargalo = inf, u;

	memset(visitado, 0, sizeof visitado);
	memset(pais, 0, sizeof pais);

	visitado[origem] = 1;
	queue<int> q;
	q.push(origem);

	while(!q.empty()) {
		u = q.front(); q.pop();
		for (int i = 0; i < 52; i++) {
			if (grafo[u][i] && !visitado[i]) {
				pais[i] = u;
				visitado[i] = 1;
				q.push(i);
				if (i == destino) {
					goto label;
				}
			}
		}
	}

	return 0;

	label: 
	int fim = destino;
	u = destino;
	while (u) {
		gargalo = min(gargalo, grafo[pais[u]][u]);
		u = pais[u];
	}

	while(fim) {
		grafo[fim][pais[fim]] += gargalo;
		grafo[pais[fim]][fim] -= gargalo;
		fim = pais[fim];
	}

	return gargalo;
}

int fluxo(int origem, int destino) {
	int fluxo = 0;
	while(1) {
		int gargalo = bfs(origem, destino);
		if (gargalo == 0) {
			return fluxo;
		}
		fluxo += gargalo;
	}
}

int main(){
	scanf("%d", &n);
	for(int i=0;i<n;++i){
		char v0, v1;
		int w;
		scanf(" %c %c %d", &v0, &v1, &w);
		if (v0 >= 'a' && v0 <= 'z') {
			v0 -= 'a';
			v0 += 26;
		}else {
			v0 -= 'A';
		}
		if (v1 >= 'a' && v1 <= 'z') {
			v1 -= 'a';
			v1 += 26;
		}else {
			v1 -= 'A';
		}
		grafo[v0][v1] += w;
	}
	printf("%d\n", fluxo(0, 25));
}	
