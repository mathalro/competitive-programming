/**
	Problema: uva 1213
	accepted: 25/09/2016 0.970ms
	solucao: problema da mochila
		A solução pode ser feita com uma programacao dinamica com 3 graus de liberdade. 
**/
#include <bits/stdc++.h>
#define maxn 1121

using namespace std;

char bit[maxn];
vector<int> primos;
int n, k;
int pd[maxn][187][15];

void crivo() {
	for (int i = 2; i < maxn; i++) {
		if (!bit[i])
			primos.push_back(i);
		for (int j = i*i; j < maxn; j += i)
			bit[j] = '1';
	}
}

int f(int valor, int katual, int posicao) {
	if (valor == n && katual == k) return 1;
	if (valor > n || katual > k || posicao == 187) return 0;

	int &p = pd[valor][posicao][katual];

	if (p != -1) return p;

	return p = f(valor, katual, posicao+1) + f(valor+primos[posicao], katual + 1, posicao+1);
}

int main () {
	crivo();
	n = 24; k = 3;
	while(scanf("%d %d", &n, &k)) {
		if (n + k == 0) break;
		memset(pd, -1, sizeof pd);
		printf("%d\n", f(0, 0, 0));
	}

	return 0;
}