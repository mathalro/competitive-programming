/*
	accepted
*/

#include <bits/stdc++.h>
#define maxn 100

using namespace std;

struct ponto {
	int x, y;
	ponto() {}
	ponto(int x, int y) : x(x), y(y) {}
};

ponto pa;
ponto pb;
vector<ponto> v;
int dp[maxn];

int orientacao(ponto p1, ponto p2, ponto p3) {
    int val = (p2.y-p1.y)*(p3.x - p2.x) - (p2.x-p1.x)*(p3.y - p2.y);
    if (val == 0) return 0; 
    return (val > 0)? 1: 2;
}

bool contido(int i, int j) {
	if (v[i].y <= v[j].y) return false;
	if (orientacao(pa, v[j], v[i]) != 2) return false;
	if (orientacao(pb, v[j], v[i]) != 1) return false;
	return true;
}

int f(int i) {
	if (dp[i] != -1) return dp[i];
	int maior = 0;
	for (int j = 0; j < v.size(); j++) {
		if (i != j && contido(i, j)) {
			maior = max(maior, f(j) + 1);
		}
	}

	return dp[i] = maior;
}


int main () {
	int n, xa, xb; scanf("%d %d %d", &n, &xa, &xb);

	pa = ponto(xa, 0);
  pb = ponto(xb, 0);

	for (int i = 0; i < n; i++) {
		int x, y; scanf("%d %d", &x, &y);
		v.push_back(ponto(x, y));
	}

	int ans = 1;
	memset(dp, -1, sizeof dp);
	for (int i = 0; i < v.size(); i++) {
		ans = max(ans, f(i)+1);
	}

	printf("%d\n", ans);

	return 0;
}
