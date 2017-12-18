#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define maxn 1000009

using namespace std;

int n;
int dp[maxn];
int aux;

int f(int sum) {
	if (aux > 10000)return inf;
	if (sum > n) return inf;
	if (sum == n) return dp[sum] = 0;
	if (dp[sum] != -1) return dp[sum];
	
	aux++;
	dp[sum] = min(f(sum*2), min(f(sum*3), f(sum+1))) + 1;
	aux--;
	return dp[sum];
}

void rec(int sum) {
	printf("%d ", sum);
	if (sum == n) return;

	if (sum*3 <= n && dp[sum*3] <= dp[sum*2] && dp[sum*3] <= dp[sum+1]) rec(sum*3);
	else if (sum*2 <= n && dp[sum*2] < dp[sum+1]) rec(sum*2);
	else rec(sum+1);
}

int main () {
	scanf("%d", &n);
	memset(dp, -1, sizeof dp);
	aux = 0;
	printf("%d\n", f(1));
	rec(1); puts("");
	return 0;
}
