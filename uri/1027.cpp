/*
 ============================================================================
 Name        : URI: 1027 - Onda Cŕitica
 Author      : Matheus de Almeida Rosa (Tchola)
 Version     : 1
 Copyright   : 
 Description : Programação Dinâmica
 ============================================================================
*/

#include <bits/stdc++.h>

using namespace std;

struct ponto {
	int x;
	int y;
	bool operator < (const ponto &p) const {
		return x < p.x;
	}
};

int n, a;

vector<ponto> pontos;

int f(int p, int pos) {

	int maior = 0;

	for (int j = p+1; j < n; j++) {
		if ( pontos[p].x < pontos[j].x ) {
			if ( pos and pontos[j].y == a-1 or pontos[j].y == a+1 and !pos ) {
				maior = max(maior, 1 + f(j, !pos));
			}
		}
	}

	return maior;
}

int main () {
	
	while(cin >> n) {

		int maior = 0;

		for (int i = 0; i < n; i++) {
			ponto p;
			scanf("%d %d", &p.x, &p.y);
			pontos.push_back(p);
		}

		sort(pontos.begin(), pontos.end());

		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				if ( pontos[i].x < pontos[j].x and abs(pontos[i].y - pontos[j].y) == 2 ) {
					int h1 = max(pontos[i].y, pontos[j].y);
					int h2 = min(pontos[i].y, pontos[j].y);
					a = h2 + 1;
					maior = max(maior, 1 + f(j, pontos[j].y==h1));
				}
			}
		}

		printf("%d\n", maior+1);

		pontos.clear();
	}

	return 0;
}