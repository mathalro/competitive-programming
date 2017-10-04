/*
	not accepted
*/

#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define maxn 30

using namespace std;

map<string, char> sc;
map<char, string> cs;

int dp[maxn];
int n, q; 

void f(int lim) {
	int i = 2;
	dp[1] = n;	
	while (dp[i-1] < lim) {
		dp[i] = pow(n, i)*i+dp[i-1];
		i++;
	}
}

string bt(int size, int val, int q) {
	int x = 3;
	while (1) {
		for (int i = 0; i < size*x; i++, val++) {
			if (val == q) {
				cout << q << ' ' << i << endl;
				return cs['A'+(i%size)];
			}
		}
		x *= size;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	while (cin >> n >> q && n) {
		cs.clear();
		for (int i = 0; i < n; i++) {
			string s; cin >> s;
			char c = 'A'+i;
			cs[c] = s;
		}

		int m = -inf;
		vector<int> queryes;
		for (int i = 0; i < q; i++) {
			int a; cin >> a;
			queryes.push_back(a);
			if (a > m) {
				m = a;
			}
		}

		if (n != 1) {
			f(m);

			for (int i = 0; i < queryes.size(); i++) {
				int j;
				for (j = 1; j < maxn; j++) {
					if (dp[j] >= queryes[i]) break;
				}
				cout << bt(j, dp[j-1], queryes[i]) << endl;
			}
		} else {
			cout << cs['A'] << endl;
		}
	}

	return 0;
}
