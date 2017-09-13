/**
	Problema: Flowers
	accepted: 25/09/2016 93ms
	solucao: Programacao dinamica botton up
		Deve-se calcular quantas maneiras, com um tamanho determinado de k, podemos formar sequencias de R e W, sendo que W deve estar em 
		sequencias de tamanho k. Como ha uma maneira de nao comer nada, iniciamos a pd com 1, e enquanto o tamanho for menor que k, so existe
		uma forma de construir a sequencia, pois, so podem conter Rs. A partir do momento que a sequencia e maior ou igual a k, podemos variar
		onde colocaremos a sequencia de W, ou se colocaremos a sequencia de W. Isso nos leva a uma solucao da pd do tipo:
			pd[i] = 1 -> para i < k
			pd[i] = pd[i-1] + pd[i-k] -> para i >= k. Sendo que i-1 representa nao usar Ws e i-k representa usar Ws em alguma posicao.
**/

#include <bits/stdc++.h>
#define maxn 100001
#define mod 1000000007

using namespace std;

long long int pd[maxn];
int t, k;

int main () {
	scanf("%d %d", &t, &k);

	pd[0] = 1;
	for (int i = 1; i < maxn; i++)
		if (i < k) pd[i] = 1;
		else pd[i] = (pd[i-k] + pd[i-1])%mod;

	for (int i = 1; i < maxn; i++) {
		pd[i] = (pd[i] + pd[i-1]);
	}

	for (int i = 0; i < t; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%lld\n", (pd[b]-pd[a-1])%mod);
	}

	return 0;
}