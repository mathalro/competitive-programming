#include <bits/stdc++.h>
#define maxn 1009
#define maxm 200009
#define inf 0x3f3f3f3f

using namespace std;

int v[maxn], dp[2][maxm];

int main () {

	int n;

	while (scanf("%d", &n) && n) {
		int k = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", v+i);
			k += v[i];
		}

		for (int i = -k; i <= k; i++) {
			dp[0][i+k] = -inf;
		}
	
		dp[0][k] = 0;

		for (int i = 1; i <= n; i++) {
			for (int j = -k; j <= k; j++) {
				dp[1][j+k] = dp[0][j+k];
				if (j+v[i] <= k) {
					dp[1][j+k] = max(dp[1][j+k], v[i] + dp[0][j+k+v[i]]);
				}
				if (j-v[i] >= -k) {
					dp[1][j+k] = max(dp[1][j+k], v[i] + dp[0][j+k-v[i]]);
				}
			}
			for (int j = -k; j <= k; j++) {
				//if (dp[1][j+k] < -100) {
					//printf("oo ");
				//} else {
					//printf("%2d ", dp[1][j+k]);
				//}
				dp[0][j+k] = dp[1][j+k];	
			}//puts("");
		}//puts("");

		printf("%d\n", dp[0][k]/2);
	}
	
	return 0;
}
