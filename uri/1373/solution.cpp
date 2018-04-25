#include <bits/stdc++.h>
#define maxn 1009

using namespace std;

int dp[maxn][maxn];

int main () {
	int k;

	while (scanf("%d", &k) && k) {
		string s1, s2;
		cin >> s1 >> s2;
	
		for (int i = 0; i < s1.size(); i++) dp[0][i] = 0;
		for (int i = 0; i < s2.size(); i++) dp[i][0] = 0;

		for (int i = 1; i <= s2.size(); i++) {
			for (int j = 1; j <= s1.size(); j++) {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				if (s2[i-1] == s1[j-1]) {
					int n = 0;
					while ((s2[i-n-1] == s1[j-n-1]) && (i-n-1 >= 0) && (j-n-1 >= 0)) n++;
					if (n >= k) {
						if (i-n-1) {
							dp[i][j] = max(dp[i][j], n+dp[i-n][j-n]);
						} else {
							max(dp[i][j], n);
						}
					}
				}
			}
		}

		/*for (int i = 0; i <= s2.size(); i++) {
			for (int j = 0; j <= s1.size(); j++) {
				printf("%2d ", dp[i][j]);
			}puts("");
		}puts("");*/

		printf("%d\n", dp[s2.size()][s1.size()]);
		
	}

	return 0;
}
