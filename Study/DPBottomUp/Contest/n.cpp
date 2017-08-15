#include <bits/stdc++.h>
#define maxn 10009

typedef long long ll;

using namespace std;

int n;
ll v[maxn], dp[2][maxn];

void input() {
	for (int i = 0; i < n; i++) {
		scanf("%lld", v+i);
		dp[0][i] = v[i];
	}
}

void solve() {
	for (int i = 0; i < n-1; i++) {
		dp[1][i] = max(dp[0][i+1], dp[0][i]);
	}

	for (int i = 2; i < n; i++) {
		for (int j = 0; j <= n-i; j++) {
			dp[i&1][j] = max(max(dp[i&1][j+2], dp[i&1][j+1]) + v[j], max(dp[i&1][j], dp[i&1][j+1]) + v[j+i]);
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
