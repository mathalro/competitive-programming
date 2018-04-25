#include <bits/stdc++.h>
#define maxn 1001

using namespace std;

bool dp[maxn][maxn];

void f(string s) {
	int n = s.size();
	int start = 0, size = 1;

	// substrings of size 1 are palindromic
	for (int i = 0; i < n; i++) {
		dp[i][i] = true;
	}

	// check for substring of size 2 
	for (int i = 0; i < n-1; i++) {
		if (s[i] == s[i+1]) {
			dp[i][i+1] = true;
			start = i;
			size = 2;	
		}
	}

	// check for k size of substring
	for (int k = 3; k <= n; k++) {
		// fix an i position and check for a string with k size starting in i
		for (int i = 0; i <= n-k; i++) {
			int j = i+k-1;
			// check if the kth position of a substring starting in i is equal to the i position
			// ans checj if the substring i+1 ... k-1 is a palindromic substring
			if (s[i] == s[j] && dp[i+1][j-1]) {
				dp[i][j] = true;
				start = i;
				size = k;
			}
		}
	}
	
	cout << s.substr(start, size) << endl;
}

int main () {

	string s; cin >> s;

	f(s);	

	return 0;
}








