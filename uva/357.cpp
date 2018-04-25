#include <bits/stdc++.h>
#define maxn 30001

using namespace std;

int n;

int coin[] = {0, 1, 5, 10, 25, 50};
long long dp[6][maxn];

long long f() {
	for (int i = 0; i <= 5; i++) dp[i][0] = 1;
	for (int i = 1; i <= 5; i++) {
		for (int j = 0; j <= n; j++) {
			if (j-coin[i] >= 0) {
				dp[i][j] = dp[i-1][j] + dp[i][j-coin[i]];
			} else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	return dp[5][n];
}

int main () {
	
	while (scanf("%d", &n) != EOF) {
		long long ans = f();
		if (ans == 1) {
			printf("There is only 1 way to produce %d cents change.\n", n);
		} else {
			printf("There are %lld ways to produce %d cents change.\n", ans, n);		
		}
	}

	return 0;
} 
