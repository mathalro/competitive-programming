#include <bits/stdc++.h>
#define mod 1000000
#define maxn 109

using namespace std;

int n, k;
int dp[maxn][maxn];

int f(int valor, int cont) {
	
	if (valor > n) return 0;
	if (cont == k) return valor == n;

	if (dp[valor][cont] != -1) {
		return dp[valor][cont];
	}

	int tmp = 0;
	for (int i = 0; i <= n; i++) {
		tmp = (tmp+f(valor+i, cont+1))%mod;
	}

	return dp[valor][cont] = tmp;
}

int main () {

	while (scanf("%d %d", &n, &k) && n) {
		memset(dp, -1, sizeof dp);
		printf("%d\n", f(0, 0)%mod);
	}
}
