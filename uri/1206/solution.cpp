#include <bits/stdc++.h>

using namespace std;

struct peca {
	char tipo;
	int x, y;
	peca(char tipo, int x, int y) : tipo(tipo), x(x), y(y) {}
};

int tab[10][10], xRei, yRei;
vector<peca> pecas;

bool ataqueTorre(int x, int y) {
	for (int i = y+1; i <= 8 && (tab[x][i-1] != 2 || i-1 == y); i++) {
		if (x == xRei && i == yRei) return true;
	}
	for (int i = y-1; i >= 1 && (tab[x][i+1] != 2 || i+1 == y); i--) {
		if (x == xRei && i == yRei) return true;
	}
	for (int i = x+1; i <= 8 && (tab[i-1][y] != 2 || i-1 == x); i++) { 
		if (y == yRei && i == xRei) return true;
	}
	for (int i = x-1; i >= 1 && (tab[i+1][y] != 2 || i+1 == x); i--) { 
		if (y == yRei && i == xRei) return true;
	}

	return false;
}

bool ataqueBispo(int x, int y) {
	for (int i = x-1, j = y-1; i >= 0 && j >= 0 && (tab[i+1][j+1] != 2 || i+1 == x && j+1 == y); i--, j--) {
		if (i == xRei && j == yRei)	return true;
	}
	for (int i = x-1, j = y+1; i >= 0 && j <= 8 && (tab[i+1][j-1] != 2 || i+1 == x && j-1 == y); i--, j++) {
		if (i == xRei && j == yRei)	return true;
	}
	for (int i = x+1, j = y-1; i <= 8 && j >= 0 && (tab[i-1][j+1] != 2 || i-1 == x && j+1 == y); i++, j--) {
		if (i == xRei && j == yRei)	return true;
	}
	for (int i = x+1, j = y+1; i <= 8 && j <= 8 && (tab[i-1][j-1] != 2 || i-1 == x && j-1 == y); i++, j++) {
		if (i == xRei && j == yRei)	return true;
	}
	
	return false;
}

bool ataque(peca p) {
	if (p.tipo == 'P') {
		return p.x-1 == xRei && p.y+1 == yRei ||
				p.x-1 == xRei && p.y-1 == yRei;
	} else if (p.tipo == 'T') {
		return ataqueTorre(p.x, p.y);
	} else if (p.tipo == 'B') {
		return ataqueBispo(p.x, p.y);
	} else if (p.tipo == 'R') {
		return ataqueBispo(p.x, p.y) || ataqueTorre(p.x, p.y);
	} else if (p.tipo == 'W') {
		return p.x-1 == xRei && p.y-1 == yRei || p.x == xRei && p.y-1 == yRei ||
				p.x+1 == xRei && p.y-1 == yRei || p.x+1 == xRei && p.y == yRei ||
				p.x+1 == xRei && p.y+1 == yRei || p.x == xRei && p.y+1 == yRei ||
				p.x-1 == xRei && p.y+1 == yRei || p.x-1 == xRei && p.y == yRei;
	}
}

bool verifica(int x, int y) {
	xRei = x; yRei = y;
	for (int i = 0; i < pecas.size(); i++) {
		if (ataque(pecas[i])) return true;
	}
	
	return false;
}

int main () {
	
	ios_base::sync_with_stdio(false);
	
	int n;
	while (cin >> n) {
	
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			peca aux = peca(s[0], s[2]-'0', s[1]-'a'+1);
			tab[aux.x][aux.y] = 2;
			pecas.push_back(aux);
		}
		
		for (int i = 0; i <= 9; i++) {
			tab[i][0] = 1; tab[0][i] = 1;
			tab[9][i] = 1; tab[i][9] = 1;
		}
				
		string rei;
		cin >> rei;
		
		int x = rei[2]-'0', y = rei[1]-'a'+1;
	
		if ((tab[x-1][y-1] == 1 || verifica(x-1, y-1)) &&
		   (tab[x][y-1] == 1 || verifica(x, y-1)) &&
		   (tab[x+1][y-1] == 1 || verifica(x+1, y-1)) &&
		   (tab[x+1][y] == 1 || verifica(x+1, y)) &&
		   (tab[x+1][y+1] == 1 || verifica(x+1, y+1)) &&
		   (tab[x][y+1] == 1 || verifica(x, y+1)) &&
		   (tab[x-1][y+1] == 1 || verifica(x-1, y+1)) &&
		   (tab[x-1][y] == 1 || verifica(x-1, y)) && 
		    verifica(x, y)) {
			   cout << "SIM" << endl;
		} else {
			cout << "NAO" << endl;
		}
		
		
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				tab[i][j] = 0;
			}
		}
		
		pecas.clear();
	}
	return 0;
}