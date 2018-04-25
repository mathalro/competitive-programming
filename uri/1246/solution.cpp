#include <bits/stdc++.h>
#define maxn 1001

using namespace std;

int estacionamento[maxn], c, n, ans, ponteiro;

void print() {
	for (int i = 0; i < c; i++) cout << estacionamento[i] << " ";
	cout << endl;
}

bool estacionar(int p, int q) {
	bool livre;
	for (int i = ponteiro; i < c; i++) {
		int cont = 0, j = i;
		livre = false;
		while(j < c && !estacionamento[j]) {
			cont++;
			if (cont == q) {
				livre = true;
				break;
			}
			j++;
		}
		if (livre) {
			j = 0;
			while(j < q) {
				estacionamento[i+j] = p;
				j++;
			}
			
			break;
		}
		if(c-i < q) break;
	}
	
	return livre;
}

void sair(int p) {
	bool aux = true;
	for (int i = 0; i < c; i++) {
		if (!aux && estacionamento[i] != p) break;
		if (estacionamento[i] == p) {
			if (aux) {
				if (i < ponteiro) {
					ponteiro = i;
				}
				aux = false;
			}
			estacionamento[i] = 0;
		}
	}
}

int main () {

	while(scanf("%d %d", &c, &n) != EOF) {
		ans = 0; ponteiro = 0;
		for (int i = 0; i < c; i++) estacionamento[i] = 0;
		
		for (int i = 0; i < n; i++) {
			char ev;
			int p, q;
			scanf(" %c %d", &ev, &p);
			if (ev == 'C') {
				scanf("%d", &q);
				if(estacionar(p, q)) ans += 10; 
			} else {
				sair(p);
			}
		}
		
		printf("%d\n", ans);
		
	}
	
	return 0;
}
