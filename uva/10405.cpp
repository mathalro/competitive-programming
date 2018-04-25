#include <bits/stdc++.h>
#define maxn 10002

using namespace std;

int dp[maxn][maxn];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	string s1, s2;

	while (getline(cin, s1)) {
		getline(cin, s2);

		for (int i = 0; i <= s1.size(); i++) dp[i][0] = 0;
		for (int i = 0; i <= s2.size(); i++) dp[0][i] = 0;

		for (int i = 1; i <= s1.size(); i++) {
			for (int j = 1; j <= s2.size(); j++) {
				if (s1[i-1] == s2[j-1]) {
					dp[i][j] = dp[i-1][j-1] + 1;
				} else {
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				}
			}
		}

		printf("%d\n", dp[s1.size()][s2.size()]);
	}

	return 0;
}
