#include <bits/stdc++.h>
#define maxn 45
#define maxf 50001

using namespace std;

int positive[maxn];
int negative[maxn];
int operacao[maxn];

int dp[maxn][maxf*2];

int n, f;

int f1(int i, int fluxo) {
	if ( i == n ) {
		return fluxo == f;
	}

	if (dp[i][fluxo+maxf] != -1) {
		return dp[i][fluxo+maxf];
	}

	int pos = f1(i+1, fluxo+operacao[i]);
	int neg = f1(i+1, fluxo-operacao[i]);

	if ( pos ) {
		positive[i] = 1;
	}
	if ( neg ) {
		negative[i] = 1;
	}

	return dp[i][fluxo+maxf] = pos || neg;
}

int main () {
	while (scanf("%d %d", &n, &f)) {
		if ( n + f == 0 ) {
			break;
		}

		memset(positive, 0, sizeof positive);
		memset(negative, 0, sizeof negative);
		memset(dp, -1, sizeof dp);

		for (int i = 0; i < n; i++) {
			scanf("%d", &operacao[i]);
		}

		if ( f1(0, 0) ) {
			for (int i = 0; i < n; i++) {
				if ( negative[i] && positive[i] ) {
					printf("?");
				}else if ( negative[i] ) {
					printf("-");
				}else {
					printf("+");
				}
			}
			puts("");
		} else {
			printf("*\n");
		}
	}
	return 0;
}