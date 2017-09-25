#include <bits/stdc++.h>
#define tab1 qtd+=4
#define tab2 qtd-=4

using namespace std;

string tmp = "$$$$";

void printPontos(int n) {
	for (int i = 0; i < n; i++) {
		cout << ".";
	}
}

void troca(char c) {
	tmp[0] = tmp[1]; tmp[1] = tmp[2];	tmp[2] = tmp[3]; tmp[3] = c;
}

int main () {
  int qtd = 0;
	bool linha = false;
	char c;
	while (scanf("%c", &c) != EOF) {
		troca(c);
 		if (tmp == "for(") {
			cout << c;
			while (scanf("%c", &c) && c != ')') {	
				cout << c;
			}
			cout << c;
		} else {
			if (c == '{') {
				puts("");
				printPontos(qtd);
				puts("{");
				tab1;	
				linha = true;
			} else if (c == '}') {
				tab2;
				printPontos(qtd);
				puts("}");
				linha = true;
			} else if (c == ';') {
				puts(";");
				linha = true;
			} else {
				if (linha) {
					printPontos(qtd);
					linha = false;
				}
				cout << c;
			}
		}
	}

	return 0;
}

