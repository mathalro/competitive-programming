#include <bits/stdc++.h>
#define maxn 10100

using namespace std;

vector<int> canhota[maxn];
vector<int> destra[maxn];

int calculaCentralCanhota() {
	int atual = 1, cont = 1;
	while (canhota[atual][1]) {
		atual = canhota[atual][1];
		cont++;
	}
	
	return cont;
}

int calculaCentralDestra() {
	int atual = 1, cont = 1;
	while (destra[atual][0]) {
		atual = destra[atual][0];
		cont++;
	}
	
	return cont;
}

int calculaLadoCanhota(int pai) {
	int cont = 0, maximo = 0, contFilho;
	while (pai) {
		if (canhota[pai][0]) {
			maximo = max(maximo, calculaLadoCanhota(canhota[pai][0]));	
		}
		
		cont++;
		pai = canhota[pai][1];
	}

	return max(cont, maximo);
}

int calculaLadoDestra(int pai) {
	int cont = 0, maximo = 0;
	while (pai) {
		if (destra[pai][1]) {
			maximo = max(maximo, calculaLadoDestra(destra[pai][1]));	
		}

		cont++;
		pai = destra[pai][0];
	}

	return max(cont, maximo);
}

int main () {
	int n, total = 0;
	scanf("%d", &n);
	total += n;
	for (int j = 0; j < n; j++) {
		int i, l, k;
		scanf("%d %d %d", &i, &l, &k);
		canhota[i].push_back(l);
		canhota[i].push_back(k);
	}
	
	scanf("%d", &n);
	total += n;
	for (int j = 0; j < n; j++) {
		int i, l, k;
		scanf("%d %d %d", &i, &l, &k);
		destra[i].push_back(l);
		destra[i].push_back(k);
	}
	
	int centralCanhota = calculaCentralCanhota();
	int centralDestra = calculaCentralDestra();
	int ladoCanhota = calculaLadoCanhota(1);
	int ladoDestra = calculaLadoDestra(1);

	printf("%d\n", total - max(min(centralCanhota, ladoDestra), min(centralDestra, ladoCanhota)));
	
	return 0;
}
