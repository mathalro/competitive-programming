#include <bits/stdc++.h>
#define maxn 10009

using namespace std;

int n;
long long v[maxn], dp[2][maxn];

void input() {
	memset(dp, 0, sizeof dp);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &v[i]);
		dp[0][i] = v[i];
	}
}

void solve() {
	for (int i = 0; i < n-1; i++) {
		dp[1][i] = max(dp[0][i], dp[0][i+1]);
	}

	for (int i = 2; i < n; i++) {
		int l = i%2;
		for (int j = 0; j < n-i; j++) {
			dp[l][j] = max(min(dp[l][j], dp[l][j+1]) + v[j+i], min(dp[l][j+1], dp[l][j+2]) + v[j]);
		}
	}
}

void print() {
	printf("%lld\n", dp[1][0]);
}

int main () {
	
	while (scanf("%d", &n) != EOF) {
		input();
		solve();
		print();
	}

	return 0;
}
