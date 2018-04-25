#include <bits/stdc++.h>

using namespace std;

int main () {

	ios_base::sync_with_stdio(0); cin.tie(0);

	// incializacao
	string s(10, 'a');	// funcionaria: s = "aaaaaaaaaa"
	
	// varrendo a string e acessando posicoes
	cout << "Varrendo a string: ";
	for (int i = 0; i < s.size(); i++) {
		cout << s[i] << ' ';
	}
	cout << endl; // equivale a: cout << "\n";

	// substituindo um padrao da string por algo
	s.replace(0, 2, "23");
	s.replace(4, 1, "A");

	cout << "String substituida: " << s << endl;	

	// verificando se um caractere da string e digito. Transformando maiusculas em minusculas
	cout << "Verificando os digitos e transformando maiusculas em minusculas: " << endl;
	for (int i = 0; i < s.size(); i++) {
		if (isdigit(s[i])) {
			cout << "Posicao " << i << " e um digito\n";
		}
		s[i] = tolower(s[i]);
	}

	cout << "String sem maiusculas: " << s << endl;

	// conversao de string para inteiro
	s = "1024";
	cout << "Conversao para inteiro adicionando 10: " << atoi(s.c_str())+10 << endl;

	// verificando se existe um padrao na string
	if (s.find("24", 0) != string::npos) {
		cout << "O padrao 24 existe na string" << endl;
	}

	// pegando parte de uma string de uma string
	string sub = s.substr(0, 3);
	cout << "Substring: " << sub << endl;

	return 0;
}
