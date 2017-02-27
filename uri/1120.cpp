/*
 ============================================================================
 Name        : URI: 1220 - Revisao de Contrato
 Author      : Matheus de Almeida Rosa (Tchola)
 Version     : 1
 Copyright   : 
 Description : Strings
 ============================================================================
*/

#include <bits/stdc++.h>

using namespace std;

int main () {

	char d;
	string n;

	while(cin >> d >> n) {
		
		if ( d == '0' and n == "0" ) {
			break;
		}

		string res = "";
		bool zeroEsq = true;
		for (int i = 0; i < n.size(); i++) {
			if ( n[i] != d ) {
				if ( n[i] == '0' ) {
					if ( !zeroEsq ) {
						res += n[i];
					}
				} else {
					res += n[i];
					zeroEsq = false;
				}
			}
		}

		if ( zeroEsq ) {
			cout << "0" << endl;
		}else {
			cout << res << endl;
		}
	}

	return 0;
}