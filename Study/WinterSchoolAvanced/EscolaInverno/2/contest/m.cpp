#include <bits/stdc++.h>
#define maxn 109
#define inf 0x3f3f3f3f

using namespace std;

int v[maxn];
int n;

struct par {
	int a, b;
	par() {}
	par(int _a, int _b) : a(_a), b(_b) {}
	bool operator < (const par &outro) const {
		return abs(a-b) < abs(outro.a-outro.b);
	}
};

struct data {
	int i, a, b;
	data() {}
	data(int i, int a, int b) : i(i), a(a), b(b) {}
	bool operator < (const data &outro) const {
		return i < outro.i;
	}
};

map<data, par> dp;

par minimo(par p1, par p2) {
	return p1 < p2 ? p1 : p2;
}

par f(int i, int a, int b) {	
	if (i == n) {
		return par(a, b);
	}

	if (dp.find(data(i, a, b)) == dp.end()) {
		return dp[data(i, a, b)] = minimo(f(i+1, a+v[i], b), f(i+1, a, b+v[i]));
	} else {
		return dp[data(i, a, b)];
	}
}

int main () {
	
	int t; scanf("%d\n", &t);
	int aux = t;

	while (t--) {		
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", v+i);	
		}

		par ans = f(0, 0, 0);

		if (ans.a > ans.b) {
			swap(ans.a, ans.b);	
		}
	
		printf("%d %d\n", ans.a, ans.b);		
		dp.clear();

		if (t != aux && t) puts("");
	}

	return 0;
}
