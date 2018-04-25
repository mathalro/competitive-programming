#include <bits/stdc++.h>
#define maxn 109
using namespace std;

string origem, destino;
map<string, int> cores;

double dp[109][109];
double remover = 0.5, trocar = 1, inserir = 2.5;

double f(int m, int n) {
	

	if (dp[m][n] != -1) return dp[m][n];

	if (m == 0) {
		return dp[m][n] = (double)n*inserir;
	}

	if (n == 0) {
		return dp[m][n] = (double)m*remover;
	}

	if (origem[m-1] == destino[n-1]) {
		return dp[m][n] = f(m-1, n-1);
	}

	return dp[m][n] = min(min(f(m-1, n) + remover,		 // remover
				   f(m, n-1) + inserir),	 // inserir
			   f(m-1, n-1) + trocar);        // trocar

}

string replace(string s, char a, char b) {
	string res = "";	
	int cont = 0;
	for (int i = 0; i < s.size() && cont < 4; i++) {
		if (s[i] == a) {
			s[i] = b;
			cont = 1;
		}

		if (cont) cont++;
		res += s[i];
 	}

 	return res;
}

int main () {

	int t, r, m, n, caso = 1;
	scanf("%d", &t);

	for (int j = 0; j < t; j++) {

		scanf("%d %d", &r, &m);
		
		origem = ""; destino = "";
		
		int cont = 0;
		for(int i = 0; i < m; i++) {
			string s;
			cin >> s;

			if (cores.find(s) != cores.end()) {
				origem += cores[s]+'0';
			} else {
				origem += cont + '0';
				cores[s] = cont++;
			}
		}

		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			if (cores.find(s) != cores.end()) {
				destino += cores[s] + '0';
			} else {
				destino += cont + '0';
				cores[s] = cont++;
			}
		}

		for (int i = 0; i < maxn; i++) {
			for (int k = 0; k < maxn; k++) {
				dp[i][k] = -1;
			}
		}

		double tempo = f(origem.size(), destino.size());
		double valor = tempo*r;
		string res = to_string(valor);
		res = replace(res, '.', ',');

		cout << "Caso #" << caso++ << ": R$ " << res << endl;

		cores.clear();
	}

	return 0;
}