#include <bits/stdc++.h>

using namespace std;

int main () {
	
	ios_base::sync_with_stdio(false);
	
	double valor = 0, qtd = 0;
    int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		float v, q;
		string s = "";
		cin >> v;
		valor += v;
		
		while (s.size() == 0) {
			getline(cin, s);
		}
		
		int cont = 0;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == ' ') cont++;
		}
		
		q = cont+1;
		qtd += q;
		
		printf("day %d: %.0f kg\n", i+1, q);
	}
	
	printf("%.2f kg by day\n", qtd / n);
	printf("R$ %.2f by day\n", valor / n);
	
	
	return 0;
}