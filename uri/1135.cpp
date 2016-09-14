/**
	Problema: Uri 1135
	accepted - 14/09/2016. Time 0.528ms
	Solução: 
			Podemos modelar a colonia como uma arvore e usar o LCA para encontrar o menor caminho.  
**/
#include <bits/stdc++.h>
#define maxn 100000

using namespace std;

int peso[maxn], distancia[maxn], pais[maxn], n;

long long int lca(int u, int v) {
	long long int total = 0;
	if(distancia[u] < distancia[v])
        swap(u, v);

    while(distancia[u] != distancia[v]) {
    	total += peso[u];
    	u = pais[u];
    }

    while(u != v) {
    	total += peso[u];
        total += peso[v];
        u = pais[u];
        v = pais[v];
    }

    return total;
}

int main () {
	int casos;
	while (scanf("%d", &n)) {
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			distancia[i] = 0;
		}
		for (int i = 1; i <	 n; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			pais[i] = x;
			peso[i] = y;
			distancia[i] = distancia[pais[i]] + 1;
		}

		scanf("%d", &casos);
		while (casos--) {
			int x, y;
			scanf("%d %d", &x, &y);
			if (casos == 0)
				printf("%lld\n", lca(x, y));
			else
				printf("%lld ", lca(x, y));
		}
	}

	return 0;
}