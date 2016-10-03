/**
	Problema: Crise de Energia
	accepted: 03/10/2016 0.000ms
	Solução: Aplicação do problema de josephus. Como nesse caso os indices começam de 1, devemos modificar o 13 para 12. 
	Depois basta rodar o algoritmo para encontrar o numero de josephus com um certo k ate encontrar o k ideal.  
**/
#include <bits/stdc++.h>

using namespace std;

int f(int n, int k) {
	if (n == 1) return 1;
	return (f(n-1, k)+k-1)%n + 1;
}

int main () {
	int n;

	while(scanf("%d", &n) && n) {
		for (int i = 1; ; i++) {
			int aux = f(n-1, i);
			if (aux == 12) {
				printf("%d\n", i);
				break;
			}
		}
	}

	return 0;
}