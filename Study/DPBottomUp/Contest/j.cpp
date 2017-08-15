#include <bits/stdc++.h>
#define maxn 109

using namespace std;

int r, k;
int v[maxn], dp[maxn][maxn*maxn/2];

void input() {
	memset(v, 0, sizeof v);
	for (int i = 1; i <= k; i++) {
		int a, b; scanf("%d %d", &a, &b);
		v[a]++; v[b]++;
	}
}

void solve() {
	for (int i = 0; i < k; i++) {
		dp[0][i] = 0;
	}
	for (int i = 0; i <= r; i++) {
		dp[i][0] = 1;
	}

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= k; j++) {
			if (j < v[i]) {
				dp[i][j] = dp[i-1][j];	
			} else {
				dp[i][j] = dp[i-1][j] || dp[i-1][j-v[i]];
			}
		}
	}
}

void print() {
	printf("%c\n", dp[r][k] == 1 ? 'S' : 'N');
}

int main () {

	while (scanf("%d %d", &r, &k) != EOF) {
		input();
		solve();
		print();
	}

	return 0;
}
