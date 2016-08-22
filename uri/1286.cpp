/**
	Problema: Uri 1286
	accepted - 22/08/2016. Time 0.012ms
	Solução: 
		Programacao dinamica. Problema da mochila.  
**/
#include <bits/stdc++.h>
#define maxn 31
#define inf 0x3f3f3f3f

using namespace std;

int tempo[maxn], pizza[maxn];
int pd[maxn][maxn];

int n, qtdMax;

int f(int indice, int qtd) {
	if (indice == n) return 0;

	int &p = pd[indice][qtd];

	if (p != -1) return p;

	p = f(indice+1, qtd);

	if (qtd + pizza[indice] <= qtdMax) {
		p = max(p, f(indice+1, qtd+pizza[indice]) + tempo[indice]);
	}

	return p;
}

int main () {
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		scanf("%d", &qtdMax);

		for(int i = 0; i < n; i++) {
			int t, qtd;
			scanf("%d %d", &t, &qtd);
			tempo[i] = t;
			pizza[i] = qtd;
		}

		memset(pd, -1, sizeof pd);
		printf("%d min.\n", f(0, 0));
	}

	return 0;
}