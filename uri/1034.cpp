/*
	accepted
*/

#include <bits/stdc++.h>
#define maxn 26
#define maxm 1000001
#define inf 0x3f3f3f3f

using namespace std;

int v[maxn];
int dp[maxm];
int n, m; 

int f() {
	for (int i = 1; i <= m; i++) dp[i] = inf;
	dp[0] = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < n; j++) {
			if (i-v[j] >= 0) {
				dp[i] = min(dp[i], dp[i-v[j]]+1);
			}
		}
	}

	return dp[m];
}

int main () {

	int t; scanf("%d", &t);

	while (t--) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) {
			scanf("%d", v+i);
		}
		printf("%d\n", f());
	}

	return 0;
}
