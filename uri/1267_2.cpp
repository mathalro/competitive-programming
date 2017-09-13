#include <bits/stdc++.h>

using namespace std;

int main () {
	ios_base::sync_with_stdio(false);
	
	short int n, d;
	
	while (cin >> n >> d) {
		if (!n && !d) break;
		
		string ini;
		for (int i = 0; i < n; i++) ini += '1';
		bitset<101> bs(ini);
			
		for (int i = 0; i < d; i++) {
			string num = "";
			for (int j = 0; j < n; j++) {
				char aux;
				cin >> aux;
				num += aux;
			}
			bitset<101> novo(num);
			bs &= novo;
		}
		
		if (bs.any()) cout << "yes" << endl;
		else cout << "no" << endl;
	}
	
	return 0;
}
