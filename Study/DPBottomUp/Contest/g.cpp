#include <bits/stdc++.h>
#define maxn 101

using namespace std;

int dp[maxn][maxn];

const int remover = 1, trocar = 2, inserir = 5;

int main () {
	int t; scanf("%d", &t);
	
	for (int k = 1; k <= t; k++) {
		int r, m, n; 
		string A = "", B = "";
		map<string, char> mapa;
		char aux = 'a';

		scanf("%d", &r);
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			string s; cin >> s;
			if (mapa.find(s) == mapa.end()) {
				A += aux;
				mapa[s] = aux++;
			}	else {
				A += mapa[s];
			}
		}

		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			string s; cin >> s;
			if (mapa.find(s) == mapa.end()) {
				B += aux;
				mapa[s] = aux++;		
			} else {
				B += mapa[s];	
			}
		}
	
		memset(dp, 0, sizeof dp);
		for (int i = 0; i <= A.size(); i++) {
			dp[0][i] = i*remover;	
		}
		for (int i = 0; i <= B.size(); i++) {
			dp[i][0] = i*inserir;
		}

		for (int i = 1; i <= B.size(); i++) {
			for (int j = 1; j <= A.size(); j++) {
				if (A[j-1] == B[i-1]) {
					dp[i][j] = dp[i-1][j-1];
				} else {
					dp[i][j] = min(dp[i-1][j] + inserir, min(dp[i][j-1] + remover, dp[i-1][j-1] + trocar));
				}
			}		
		}
		
		int ans = r*dp[B.size()][A.size()];

		printf("Caso #%d: R$ %d,%02.0lf\n", k, ans/2, ((ans%2)/2.0)*100);

	} 

	return 0;
}
