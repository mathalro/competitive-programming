#include <bits/stdc++.h>

using namespace std;

int main () {
	
	ios_base::sync_with_stdio(false);
	
	int cavaloL, cavaloC, caso = 1;
	int tabuleiro[11][11];
	
	string s;
	
	while (cin >> s) {
		
		if (s == "0") break;
		
		cavaloL = s[0] - '0';
		cavaloC = s[1] - 'a'+1;

		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 11; j++) {
				tabuleiro[i][j] = 0;
			}
		}

		for (int i = 0; i < 8; i++) {
			cin >> s;
			tabuleiro[s[0]-'0'][s[1]-'a'+1] = 1;
		}
		
		int cont = 0;

		if (cavaloL < 8 && cavaloC > 2) cont += (int) (!tabuleiro[cavaloL+1+1][cavaloC-2+1] && !tabuleiro[cavaloL+1+1][cavaloC-2-1]);
		if (cavaloL > 2 && cavaloC > 2) cont += (int) (!tabuleiro[cavaloL-1+1][cavaloC-2+1] && !tabuleiro[cavaloL-1+1][cavaloC-2-1]);

		if (cavaloC > 1) {
			if (cavaloL < 7) cont += (int) (!tabuleiro[cavaloL+2+1][cavaloC-1+1] && !tabuleiro[cavaloL+2+1][cavaloC-1-1]);
			if (cavaloL > 3) cont += (int) (!tabuleiro[cavaloL-2+1][cavaloC-1+1] && !tabuleiro[cavaloL-2+1][cavaloC-1-1]);
		}

		if (cavaloL < 8 && cavaloC < 7) cont += (int) (!tabuleiro[cavaloL+1+1][cavaloC+2+1] && !tabuleiro[cavaloL+1+1][cavaloC+2-1]);
		if (cavaloL > 2 && cavaloC < 7) cont += (int) (!tabuleiro[cavaloL-1+1][cavaloC+2+1] && !tabuleiro[cavaloL-1+1][cavaloC+2-1]);

		if (cavaloC < 9) {
			if (cavaloL < 7) cont += (int) (!tabuleiro[cavaloL+2+1][cavaloC+1+1] && !tabuleiro[cavaloL+2+1][cavaloC+1-1]);
			if (cavaloL > 3) cont += (int) (!tabuleiro[cavaloL-2+1][cavaloC+1+1] && !tabuleiro[cavaloL-2+1][cavaloC+1-1]);
		}
		
		cout << "Caso de Teste #" << caso++ << ": "  << cont << " movimento(s)." << endl;
	}
	
	return 0;
} 
