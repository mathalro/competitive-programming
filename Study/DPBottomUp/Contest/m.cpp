#include <bits/stdc++.h>
#define maxn 59

using namespace std;

int n, t, dp[maxn][maxn];
string s;

bool pode(int i, int j, int k) {
	return ((int)(s[i] == 'R') + (int)(s[j] == 'R') + (int)(s[k] == 'R')) <= 1;
}

void input() {
	memset(dp, 0, sizeof dp);
	scanf("%d", &n);
	cin >> s;
}

void solve() {

	for (int i = 0; i < n; i++) {
		dp[i][i+1] = 0;
		dp[i][i] = 0;
		dp[i+1][i] = 1;
		dp[i+2][i] = 1;
	}

	for (int r = 2; r < n; r++) {
		for (int l = 0, k = 0; l < n; k++, l++) {
			if ((r+k-l+1)%3 == 0) {
				int a, b, c;
				for (int i = l+1; i < r+k && i < n; i++) {
					for (int j = i+1; j <= r+k && j < n; j++) {
						if (i > 0 && j > 0 && pode(l, i, j)) {
							a = dp[l+1][i-1];
							b = dp[i+1][j-1];
							c = dp[j+1][r+k];
							dp[l][r+l] += a*b*c;
						}
					}
				}
			} else {
				if (r+k < n) {
					dp[r+k][l] = 0;
				}
			}
		}
	}
}

void print(int i) {
	printf("Case %d: %d\n", i, dp[0][n-1]);
}

int main () {
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		input();
		solve();
		print(i);
	}
	return 0;
}
