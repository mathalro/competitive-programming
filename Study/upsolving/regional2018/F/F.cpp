#include <bits/stdc++.h>
#define maxn 1001
using namespace std;

struct show {
	int p, ini, fim, val;
	bool operator<(show o) const {
		if (ini == o.ini) {
			if (fim == o.fim)
				return p < o.p;
			return fim < o.fim;
		}
		return ini < o.ini;
	}
};

int n, c;
int nex[maxn];
int dp[maxn][1050];
vector<show> v;

int f(int show, int mask) {
	if (show == c)
		return (mask == ((1<<n)-1)) ? 0 : -1;

	if (dp[show][mask]) return dp[show][mask];

	int a = f(show+1, mask);
	int b = f(nex[show], mask | (1<<v[show].p));
	if (b != -1) b += v[show].val;
	return dp[show][mask] = max(a, b);
}

int main () {

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int m; scanf("%d", &m);
		c += m;
		for (int j = 0; j < m; j++) {
			int ini, fim, val; scanf("%d %d %d", &ini, &fim, &val);
			v.push_back({i, ini, fim, val});
		}	
	}

	sort(v.begin(), v.end());

	memset(nex,0,sizeof nex);

	for (int i = 0; i < v.size(); i++) {
		for (int j = i+1; j < v.size(); j++) {
			if (v[i].fim <= v[j].ini) {
				nex[i] = j;
				break;
			}
		}
		if (!nex[i]) nex[i] = c;
	}

	int ans = f(0, 0);
	printf("%d\n", !ans ? -1 : ans);

	return  0;
}
