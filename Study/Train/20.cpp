#include <bits/stdc++.h>
#define mod 1000000007
#define maxn 101

using namespace std;

int N, K, D;

int dp[maxn][maxn][2];

int f(int n, bool d) {
	if (n > N) return 0;
	if (n == N && !d) return 0;
	if (n == N && d) return 1;

	int ans = 0;
	for (int i = 1; i <= K; i++) {
		if (dp[n][i][d] == -1) {
			dp[n][i][d] = f(n+i, d || (i>=D));
		}
		ans = (ans+dp[n][i][d])%mod;
	}

	return ans;
}

int main () {

	memset(dp, -1, sizeof dp);
	scanf("%d %d %d", &N, &K, &D);

	printf("%d\n", f(0, 0));
}
