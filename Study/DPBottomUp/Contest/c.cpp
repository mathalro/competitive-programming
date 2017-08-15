#include <bits/stdc++.h>
#define maxn 59

using namespace std;

int v[maxn];
int dp[maxn];

int main () {
	int n;

	while (scanf("%d", &n) != EOF) {
		int c; scanf("%d", &c);

		for (int i = 0; i < n; i++) {
			int a; scanf("%d", &a);
			v[i] = a-c;
		}
	
		memset(dp, 0, sizeof dp);
		int maior = 0;
		for (int i = 0; i < n; i++) {
			if (dp[i-1] + v[i] > 0) {
				maior = max(maior, dp[i-1]+v[i]);
				dp[i] = dp[i-1]+v[i];
			} else {
				dp[i] = 0;
			}
		}

		printf("%d\n", maior);
	}

	return 0;
}
