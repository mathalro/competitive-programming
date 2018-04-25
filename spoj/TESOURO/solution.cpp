#include <bits/stdc++.h>
#define maxn 109

using namespace std;

int x, y, n;
int obj[maxn];

int dp[10009][maxn];
int meta;

bool f(int i, int k) {

	if ( k == n ) {
		return i == meta;
	}

	if ( dp[i][k] != -1 ) {
		return dp[i][k];
	}

	if ( i == meta ) {
		return dp[i][k] = 1;
	}

	if ( i > meta ) {
		return dp[i][k] = 0;
	}

	return dp[i][k] = f(i+obj[k], k+1) || f(i, k+1);

}

int main () {

	int cont = 1;
	while(scanf("%d %d %d", &x, &y, &n)) {
		if ( x + y + n == 0 ) {
			break;
		}

		memset(dp, -1, sizeof dp);

		if (cont > 1) {
			puts("");
		}

		int counter = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", obj + i);
			counter += obj[i];
		}

		meta = ( y + x + counter ) / 2 - x;

		printf("Teste %d\n", cont);

		if ( (counter + abs(x-y))%2 ) {
			printf("N\n");
		}else if ( f(0, 0) ) {
			printf("S\n");
		} else {
			printf("N\n");
		}

		cont++;
	}

	return 0;
}

