/**
	Problema: Uri 1288
	accepted - 22/08/2016. Time 0.040ms
	Solução: 
		Programacao dinamica. Problema da mochila  
**/
#include <bits/stdc++.h>
#define maxn 51
#define maxk 101

using namespace std;

int projeteis[maxn], capacidade[maxk], pd[maxn][maxk];
int n, r, k;

int f(int indice, int peso) {
	if (indice == n) return 0;

	int &p = pd[indice][peso];

	if (p != -1) return p;

	p = f(indice+1, peso);

	if (peso + capacidade[indice] <= k) {
		p = max(p, f(indice+1, peso+capacidade[indice]) + projeteis[indice]);
	}

	return p;
}

int main () {
	int t;
	scanf("%d", &t);

	while(t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int poder, peso;
			scanf("%d %d", &poder, &peso);
			projeteis[i] = poder;
			capacidade[i] = peso;
		}

		scanf("%d %d", &k, &r);
		memset(pd, -1, sizeof pd);
		if (f(0, 0) >= r)
			printf("Missao completada com sucesso\n");
		else
			printf("Falha na missao\n");
	}

	return 0;
}