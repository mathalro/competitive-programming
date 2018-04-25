/**
	Problema: Uri 1058
	accepted - 21/08/2016. Time 0.008ms
	Solução: 
		Programacao dinamica. A ideia central e fixar um triangulo, e apos isso chamar uma recursao para os grupos restantes (esquerda, centro, direita).
		a pd guarda os valores de esquerda e direita da chamada atual e as chamadas sao feitas ate que esquerda ultrapasse direita.  
**/
#include <bits/stdc++.h>

using namespace std;

int n, pd[40][40];
char s[40];

int f(int l, int r) {
	if (l > r) return 1;

	int &p = pd[l][r];
	
	if(p != -1)	return p;

	p = 0;
	if ((r-l + 1)%3) return p;

	int vermelhos, e, c, d;
	for (int i = l+1; i <= r; i++) {
		for (int j = i+1; j <= r; j++) {
			vermelhos = 0;
			if (s[l] == 'R')
				vermelhos++;
			if (s[i] == 'R')
				vermelhos++;
			if (s[j] == 'R')
				vermelhos++;

			if (vermelhos > 1) continue;

			e = f(l+1, i-1);
			c = f(i+1, j-1);
			d = f(j+1, r);

			p += e * c * d;
		}
	}

	return p;
}

int main() {
	int t, cases = 1;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %s", &n, s);
		memset(pd, -1, sizeof pd);
		printf("Case %d: %d\n", cases++, f(0, n-1));
	}

	return 0;
}