/**
	Problema: Vacations
	accepted: 25/09/2016 15 ms
	solucao: Programacao dinamica
		Existem dois graus de liberdade, sendo o dia das ferias e o tipo de dia (quais atividades estao disponiveis). 
		Basta checar quais atividades podem ser feitas no dia atual e escolher a melhor opção.
**/
#include <bits/stdc++.h>
#define maxn 101
#define inf 0x3f3f3f3f

using namespace std;

int n, dias[maxn], pd[maxn][3];

int f(int dia, int tipo){
	if (dia == n) return 0;
	int &p = pd[dia][tipo];
	if (p != -1) return p;

	if (tipo == 1) {
		if (dias[dia] == 1 || dias[dia] == 3) return p = f(dia+1, 2);
		else return p = f(dia+1, 0) + 1;
	}else if (tipo == 2) {
		if (dias[dia] == 2 || dias[dia] == 3) return p = f(dia+1, 1);
		else return p = f(dia+1, 0) + 1;
	}else {
		if (dias[dia] == 1) return p = f(dia+1, 2);
		else if (dias[dia] == 2) return p = f(dia+1, 1);
		else if (dias[dia] == 3) return p = min(f(dia+1, 2), f(dia+1, 1));
		else return p = f(dia+1, 0) + 1;
	}
}

int main () {
	scanf("%d", &n);

	memset(pd, -1, sizeof pd);

	for (int i = 0; i < n; i++) {
		scanf("%d", &dias[i]);
	}

	printf("%d\n", f(0, 0));

	return 0;
}