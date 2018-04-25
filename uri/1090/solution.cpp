/*
 * Accepted: 03/02/2017 uri 0,320s
 * Abordagem: Programação dinamica com mapeamento usando hash
 */

#include <bits/stdc++.h>

using namespace std;

int sets[21][3] = {{3, 4, 5}, {6, 7, 8}, {0, 1, 2}, {3, 6, 0}, {4, 7, 1}, {5, 8, 2}, {3, 7, 2}, 
		   {3, 8, 1}, {4, 8, 0}, {4, 6, 2}, {5, 7, 0}, {5, 6, 1}, {3, 3, 3}, {4, 4, 4},
		   {5, 5, 5}, {0, 0, 0}, {1, 1, 1}, {2, 2, 2}, {6, 6, 6}, {7, 7, 7}, {8, 8, 8}};

		   
int pd[1000000];
int cartas[9];

int add(int estado, int pos, int qtd) {
    return estado | (qtd<<(pos*2));
}

int geraEstado() {
    int estado = 0;
    for (int i = 0; i < 9; i++) {
	estado = add(estado, i, cartas[i]);
    }
    
    return estado;
}

bool testaSet(int pos) {
    if (pos > 11) {
	if (cartas[sets[pos][0]] >= 3) {
	    return true;
	}
    }else {
	if (cartas[sets[pos][0]] > 0 && cartas[sets[pos][1]] > 0 && cartas[sets[pos][2]] > 0) {
	    return true;
	}
    }
    
    return false;    
}

int atualizaCartas(int pos, int estado, int qtd) {
    
    if (pos > 11) {
	cartas[sets[pos][0]] += 3*qtd;
    }else {
	cartas[sets[pos][0]] += qtd;
	cartas[sets[pos][1]] += qtd;
	cartas[sets[pos][2]] += qtd;
    }
    
    return estado;
}
		  
int f(int estado) {
    int res = 0;
    int novoEstado;
    
    if (pd[estado] != -1) {
	return pd[estado];
    }
    
    for (int i = 0; i < 21; i++) {
	if (testaSet(i)) {
	    atualizaCartas(i, estado, -1);
	    novoEstado = geraEstado();
	    res = max(res, f(novoEstado)+1);
	    atualizaCartas(i, estado, 1);
	    novoEstado = geraEstado();
	}
    }
    
    return pd[estado] = res;
}	  

int diminuiTriplos() {
    int res = 0;
    
    for (int i = 0; i < 9; i++) {
	while (cartas[i] > 3) {
	    cartas[i] -= 3;
	    res++;
	}
    }
    
    return res;
}		  

int main () {
    int n;
    map<string, int> mapaQtd;
    map<char, int> mapaTipo;
    
    mapaQtd["um"] = 0;
    mapaQtd["dois"] = 1;
    mapaQtd["tres"] = 2;
    mapaTipo['t'] = 0;
    mapaTipo['c'] = 1;
    mapaTipo['q'] = 2;
    memset(pd, -1, sizeof pd);
    
    while (scanf("%d", &n) && n != 0) {
	memset(cartas, 0, sizeof cartas);
	
	for (int i = 0; i < n; i++) {
	    char qtd[5], tipo[10];
	    scanf("%s %s", &qtd, &tipo);
	    
	    cartas[mapaQtd[qtd]+3*mapaTipo[tipo[0]]]++;
	}
	
	int res = diminuiTriplos();
	int estado = geraEstado();
	
	printf("%d\n", res+f(estado));
    }
    
    return 0;
}