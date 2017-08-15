#include <bits/stdc++.h>
#define maxn 1009
#define inf 0x3f3f3f3f


/*
		
			dp[corte][tamanho]
			
			
		
*/



using namespace std;

int n, m;

int v[maxn];

struct data {
	int l, r, i, j;
	data() {}
	data(int l, int r, int i, int j) : l(l), r(r), i(i), j(j) {}
	bool operator < (const data &outro) const {
		return l <= outro.l;
	}
};


map<data, int> dp;

int f(int i, int j) {
	if (j < 0 || i == m || l > r || i > j) {
		return 0;
	}

	if (dp.find(data(l, r, i, j)) != dp.end()) {
		return dp[data(l, r, i, j)];
	}

	int ans = inf, size = r-l+1;

	for (int k = i; k <= j; k++) {
		int a = f(l, v[k], i, k-1);
		int b = f(v[k]+1, r, k+1, j);
		ans = min(ans, a+b+size);
	}

	dp.insert(make_pair(data(l, r, i, j), ans));
	return ans;
}

int main () {

	while (scanf("%d %d", &n, &m) != EOF) {
		dp.clear();
		for (int i = 0; i < m; i++) {
			scanf("%d", v+i);
		}

		printf("%d\n", f(1, n, 0, m-1));
	}
	
	return 0;
}
