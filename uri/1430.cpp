/**
	Uri 1430
	accepted - 21/08/2016. Time 120ms
	Solução: um map guarda os valores de cada nota, depois basta acessá-los.
**/

#include <bits/stdc++.h>

using namespace std;

int main () {
	map<char, double> notas;
	string caso;

	notas['W'] = 1;
	notas['H'] = 0.5;
	notas['Q'] = 0.25;
	notas['E'] = 0.125;
	notas['S'] = 0.0625;
	notas['T'] = 0.03125;
	notas['X'] = 0.015625;

	while (cin >> caso) {
		if (caso == "*")
			break;
		double cont = 0;
		int certos = 0;
		for (int i = 1; i < caso.size(); i++) {
			if (caso[i] == '/') {
				if (cont == 1)
					certos++;
				cont = 0;
			}else {
				cont += notas[caso[i]];
			}
		}

		cout << certos << endl;
	}

	return 0;
}