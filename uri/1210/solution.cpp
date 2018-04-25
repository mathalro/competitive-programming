/*
 ============================================================================
 Name        : URI: 1210 - Produção ótima de vodka
 Author      : Matheus de Almeida Rosa (Tchola)
 Version     : 1
 Copyright   : 
 Description : Programação Dinâmica
 ============================================================================
*/

#include <bits/stdc++.h>
#define maxn 2009

using namespace std;

int n, i, m, p;

int custo[maxn];
int valor[maxn];

int dp[maxn][maxn];
int ds[maxn][maxn];

int f2(int x, int y) {

	for (int i = 0; i <= m; i++) {
		dp[n+1][i] = 0;
	}

	for (int i = n; i >= 1; i--) {
		int op1, op2;
		for (int j = 0; j < m; j++) {
			op1 = p + custo[0] - valor[j] + dp[i+1][1];
			op2 = custo[j] + dp[i+1][j+1];
			if (op1 <= op2) {
				dp[i][j] = op1; ds[i][j] = 1;
			} else {
				dp[i][j] = op2; ds[i][j] = 0;
			}
		}
		
		op1 = p + custo[0] - valor[m] + dp[i+1][1];
		dp[i][m] = op1; ds[i][m] = 1;
	}

	return dp[x][y];

}


int main () {

	while (scanf("%d %d %d %d", &n, &i, &m, &p) != EOF) {

		for (int j = 0; j < m; j++) {
			scanf("%d", &custo[j]);
		}

		for (int j = 1; j <= m; j++) {
			scanf("%d", &valor[j]);
		}

		printf("%d\n", f2(1, i));
		
		bool trocou = false;
		for (int j = 1, k = i; j <= n; j++) {
			if ( ds[j][k] ) {
				// cout << "Local: " << j << endl;
				if ( !trocou ) {
					printf("%d", j);
				} else {
					printf(" %d", j);
				}
				trocou = true;
				k = 1;
			} else {
				k ++;
			}
		}	

		if ( !trocou ) {
			printf("0");
		}

		puts("");

	}

	return 0;
}