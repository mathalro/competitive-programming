#include <bits/stdc++.h>
#define maxn 1002
#define inf 0x3f3f3f3f

using namespace std;

int dp[maxn][maxn];
string s; 

int f(int i, int j) {
	if (i == j) return 1;
	if (i > j) return 0;

	if (dp[i][j] != -1) return dp[i][j];

	if (s[i] == s[j]) return f(i+1, j-1) + 2;
	return dp[i][j] = max(f(i+1, j), f(i, j-1));
}

int main () {
	int t; cin >> t;
	string lixo;
	getline(cin, lixo);
	while (t--) {
		getline(cin, s);
		for (int i = 0; i <= s.size(); i++) {
			for (int j = 0; j <= s.size(); j++) {
				dp[i][j] = -1;
			}
		}
		cout << f(0, s.size()-1) << endl;
	}

	return 0;
}
