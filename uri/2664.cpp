#include <bits/stdc++.h>
#define mod 1000000007

int t, m, n, cont, dp[2][100001];
int main () {
	scanf("%d %d %d", &t, &m, &n);
	for (int i = m; i <= n; i++) dp[0][i] = 1;
	for (int i = 1; i < t; i++) 
		for (int j = m; j <= n; j++) 
			dp[i&1][j] = (dp[!(i&1)][j-1] + dp[!(i&1)][j+1])%mod;
	for (int i = m; i <= n; i++) cont = (cont+dp[!(t&1)][i])%mod;
	printf("%d\n", cont);
}
