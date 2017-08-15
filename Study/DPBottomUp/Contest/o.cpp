#include <bits/stdc++.h>
#define maxn 501
#define x1 dp[i+1][j+1][k-1]
#define x2 dp[i+1][j][k-1]
#define x3 dp[i][j+1][k-1]
#define x4 dp[i][j][k-1]

using namespace std;

int n, p;
char dp[maxn][maxn][maxn];
long long qtdP, qtdB;

int main () {
	
	ios_base::sync_with_stdio(false);

	cin >> n >> p;
	qtdP = qtdB = p;
	for (int i = 0; i < p; i++) {
		int a, b; cin >> a >> b;
		dp[a][b][1] = 2;
	}
	for (int i = 0; i < p; i++) {
		int a, b; cin >> a >> b;
		dp[a][b][1] = 1;
	}

	for (int k = 2; k <= n; k++) {
		for (int i = 1; i <= n-k+1; i++) {
			for (int j = 1; j <= n-k+1; j++) {
				int aux = x1|x2|x3|x4;
				if (aux == 0) {
					dp[i][j][k] = 0;
				} else if (aux == 2) {
					dp[i][j][k] = 2;
					qtdP++;
				} else if (aux == 1) {
					dp[i][j][k] = 1;
					qtdB++;
				} else {
					dp[i][j][k] = 3;
				}
			}
		}
	}

	cout << qtdP << ' ' << qtdB << "\n";

	return 0;
}
