#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define maxn 101

using namespace std;

vector<int> v;
int n, d;

int dp[maxn][maxn];

int f(int l, int r) {
	if (l > r) return 0;
	if (v[r]-v[l] <= d) return 0;
	
	if (dp[l][r] != -1) return dp[l][r];

	return dp[l][r] = 1 + min(f(l+1, r), f(l, r-1));
}

int main () {

	scanf("%d %d", &n, &d);

	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		v.push_back(a);
	}

	sort(v.begin(), v.end());
	memset(dp, -1, sizeof dp);	
	printf("%d\n", f(0, v.size()-1));

	return 0;
}
