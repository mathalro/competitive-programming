#include <bits/stdc++.h>
#define maxn 5001

using namespace std;

string s;
int dp[maxn][3];

int f(int i, int c) {
	if (i == s.size() || c == 3) return 0;
	if (dp[i][c] != -1) return dp[i][c];
	if (c == 0) {
		if (s[i] == 'a') return dp[i][c] = max(f(i+1, c), f(i+1, c+1)) + 1;
		return dp[i][c] = max(f(i, c+1), f(i+1, c));
	}
	if (c == 1) {
		if (s[i] == 'b') return dp[i][c] = max(f(i+1, c), f(i+1, c+1)) + 1;
		return dp[i][c] = max(f(i, c+1), f(i+1, c));
	}
	if (c == 2) {
		if (s[i] == 'a') return dp[i][c] = max(f(i+1, c), f(i+1, c+1)) + 1;
		return dp[i][c] = max(f(i, c+1), f(i+1, c));
	}
}

int main () {

	cin >> s;
	memset(dp, -1, sizeof dp);
	printf("%d\n", f(0, 0));

	return 0;
}
