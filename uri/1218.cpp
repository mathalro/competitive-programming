#include <bits/stdc++.h>

using namespace std;

int main () {
	
	ios_base::sync_with_stdio(false);
	
	int n, m, f, caso = 1;
	
	while(cin >> n) {
		
		if (caso > 1) cout << endl;
		
		int cont = 0;
		string s;
		m = f = 0;
		while (s.size() == 0) {
			getline(cin, s);
		}
		
		stringstream ss;
		ss.str(s);
		int tam; char tip;
		while (ss >> tam >> tip) {
			if (tam == n) {
				cont++;
				if (tip == 'F') f++;
				else m++;
			}
		}
		
		cout << "Caso " << caso++ << ":" << endl;
		cout << "Pares Iguais: " << cont << endl;
		cout << "F: " << f << endl;
		cout << "M: " << m << endl;
	}
	
	return 0;
}
