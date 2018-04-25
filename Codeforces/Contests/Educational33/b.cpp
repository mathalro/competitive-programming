#include <bits/stdc++.h>

using namespace std;


bool beaut (int n) {
	string aux = bitset<64>(n).to_string();
	string s;

	bool foo = false;
	int i = 0;
	while (aux[i] == '0') i++;
	while (i < aux.size()) s += aux[i++];
	
	int n1 = s.size()/2+1;
	int n0 = s.size()/2;

	i = 0;

	int cont = 0;
	while (s[i] == '1' && i < n1) {
		cont++;
		i++;
	}
	if (cont != n1) return false;

	int cont2 = 0;
	int j = 0;
	while (s[i] == '0' && j < n0) {
		cont2++;
		i++;
	}
	if (cont2 != n0) return false;

	return true;
}

int main () {

	int n; scanf("%d", &n); 
	
	int tmp = n;
	while (tmp >= 1) {
		if (n%tmp == 0) {
			if (beaut(tmp)) {
				printf("%d", tmp);
				return 0;
			}
		}
		tmp--;
	}

	return 0;
}
