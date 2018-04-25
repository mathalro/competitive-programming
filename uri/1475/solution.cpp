/*
	accepted
*/
#include <bits/stdc++.h>
#define maxn 1000009

using namespace std;

set<int> S;
int n, c, t1, t2; 
int dp[maxn];

int f(int i) {
	if (i > c) {
		return 0;
	}

	if (dp[i] != -1) return dp[i];
	int a, b;
	if (S.find(i) != S.end()) {
		a = f(i+t1+1) + t1;
		b = f(i+t2+1) + t2;
	} else {
		return f(i+1);
	}

	return dp[i] = min(a, b);
}

int main () {

	while (scanf("%d %d %d %d", &n, &c, &t1, &t2) != EOF) {
		for (int i = 0; i < n; i++) {
			int a; scanf("%d", &a);
			S.insert(a);
		}
		for (int i = 0; i <= c; i++) {
			dp[i] = -1;
		}

		printf("%d\n", f(0));
		S.clear();
	}
	return 0;
}
