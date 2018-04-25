#include <iostream>
#include <string>
#include <map>

using namespace std;

int tam;

string getVis(string s, map<char, char> mapa, char c1, char c2, char c3, char c4) {
	int pos = s.size()-1;

	if (s[pos] == c1 || s[pos] == c2) {
		s[pos] = mapa[s[pos]];
		return s;
	}

	if (s[pos] == c3 || s[pos] == c4) {
		string aux = s;
		while (aux.size() != 1 && aux[aux.size()-1] != c1 && aux[aux.size()-1] != c2) {
			aux = aux.substr(0, aux.size()-1);
		}

		if (aux.size() == 1) return "<none>";

		aux[aux.size()-1] = mapa[aux[aux.size()-1]];	
		while (aux.size() != tam) {
			char c = mapa[s[aux.size()]];
			aux += c;
		}

		return aux;
	}
}

int main () {
	map<char, char> ver, hor;

	ver['r'] = 'q';
	ver['q'] = 'r';
	ver['s'] = 'p';
	ver['p'] = 's';
	
	hor['r'] = 's';
	hor['s'] = 'r';
	hor['p'] = 'q';
	hor['q'] = 'p';

	int t; cin >> t;

	while (t--) {
		string s; cin >> s;
		tam = s.size();
		cout << getVis(s, ver, 'r', 's', 'p', 'q') << ' ';
		cout << getVis(s, ver, 'p', 'q', 'r', 's') << ' ';
		cout << getVis(s, hor, 'q', 'r', 's', 'p') << ' ';
		cout << getVis(s, hor, 's', 'p', 'q', 'r') << endl;
	}

	return 0;
}
