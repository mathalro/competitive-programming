/***
	Existem tres possiveis resposta para o problema. 1, 2 ou 0. O segredo é saber verificar a diagonal.
	Observando que duas casas diagonais uma em relação a outra formam um quadrado.
	Para verificar se o destino esta na diagonal da origem basta checar se a distancia entre X1 e X2 é a mesma que entre Y1 e Y2.
	(isso é uma propriedade de um quadrado, lados são iguais, logo as distancias entre suas abcisas deve ser igual as distancias entre suas ordenadas).
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
	int x1, y1, x2, y2;

	while(scanf("%d %d %d %d", &x1, &y1, &x2, &y2)) {
		if (x1 + x2 + y1 + y2 == 0) break;
		if (x1 == x2 && y1 == y2)
			printf("0\n");
		else if ((x1 == x2 || y1 == y2) || abs(x1 - x2) == abs(y1 - y2))
			printf("1\n");
		else
			printf("2\n");
	}

	return 0;
}