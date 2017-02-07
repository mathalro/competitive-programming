#include <bits/stdc++.h>
#define maxn 10001

using namespace std;

int posicao[maxn];

int main () {

	int a, c;

	while ( scanf("%d %d", &a, &c) ) {

		if ( a + c == 0 ) {
			return 0;
		}

		int cont = 0;

		for (int i = 0; i < c; i++) {
			int altura;
			scanf("%d", &altura);
			posicao[i] = altura;
		}

		posicao[c] = a;

		int ultimoDir = 0;
		for (int i = 0; i <= c; i++) {
			if ( posicao[i+1] > posicao[i]) {
				ultimoDir = posicao[i+1] - posicao[i];
				cont += ultimoDir;
			}else if ( posicao[i] > posicao[i-1] && i > 0 ) {
				cont += posicao[i] - posicao[i-1] - ultimoDir;
			}
		}

		printf("%d\n", cont);
	}

	return 0;
}