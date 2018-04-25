#include <bits/stdc++.h>
#define maxn 100001
#define inf 0x3f3f3f3f

using namespace std;

int n, m, t; 

int dp[maxn];
int f(int atual, int end) {
	if (atual == end) return 0;
	if (atual > end) return -inf;

	if (dp[atual] != -1) return dp[atual];

	return dp[atual] = max(f(atual+n, end), f(atual+m, end))+1;
}

int main () {

	while (scanf("%d %d %d", &n, &m, &t) != EOF) {
		memset(dp, -1, sizeof dp);
		int tempo = f(0, t);

		if (tempo < 0) {
			int end = t;
			while (tempo < 0) {
				end--;
				memset(dp, -1, sizeof dp);
				tempo = f(0, end);
			}
			printf("%d %d\n", tempo, t-end);
		} else {
			printf("%d\n", tempo);
		}
	}

	return 0;
}
