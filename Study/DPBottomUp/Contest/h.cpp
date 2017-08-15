#include <bits/stdc++.h>
#define maxn 1009
#define vermelho 17
#define laranja 2
#define azul 4
#define verde 8
#define inf 0x3f3f3f3f

using namespace std;

struct cilindro {
	int h, r, cor;
	cilindro() {}
	cilindro(int h, int r, int cor) : h(h), r(r), cor(cor) {}
	bool operator < (const cilindro &outro) const {
		return r > outro.r;
	}
};

cilindro v[maxn];
int dp[maxn][maxn];

bool pode(int base, int atual) {
	if (base == 0 || base == 1) return true;
	if (((v[atual].cor<<1) & v[base].cor) != 0) return false;
	if (v[atual].r >= v[base].r ) return false;
	return true; 
}

int main () {

	int n;

	while (scanf("%d", &n) && n) {

		memset(dp, 0, sizeof dp);
		memset(v, 0, sizeof v);

		for (int i = 2; i <= n+1; i++) {
			int h, r, c;
			string cor;
			cin >> h >> r >> cor;
			if (cor == "VERMELHO") c = vermelho;
			else if (cor == "LARANJA") c = laranja;
			else if (cor == "AZUL") c = azul;
			else if (cor == "VERDE") c = verde;
			v[i] = cilindro(h, r, c);
		}

		sort(v+2, v+n+2);
		v[0] = cilindro(0, inf, 1024);
		v[1] = cilindro(0, inf, 1024);
		
		for (int i = 0; i <= n; i++) {
			dp[n+2][i] = 0;
		}

		for (int i = n+3; i > 0; i--) {
			for (int j = 0; j < i; j++) {
				if (pode(j, i)) {
					dp[i][j] = max( v[i].h + dp[i+1][i], dp[i+1][j]);
				} else {
					dp[i][j] = dp[i+1][j];
				}
			}
		}

		/*
		for (int i = 1; i <= n+2; i++) {
			for (int j = 0; j <= n-1; j++) {
				printf("%2d ", dp[i][j]);
			}puts("");
		}puts("");*/

		printf("%d centimetro(s)\n", dp[1][0]);
	}

	/*
			10001
			00010
			00100
			01000
	*/

	return 0;
}
