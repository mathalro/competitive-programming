#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define maxn 1009
#define vermelho 1
#define laranja 2
#define verde 3
#define azul 4

using namespace std;

int n;

struct cilindro {
	int h, r, cor;
	cilindro() {}
	cilindro(int h, int r, int p) : h(h), r(r), cor(p) {}
	bool operator < (const cilindro &outro) const {
		return r > outro.r;
	}
};

cilindro v[maxn];
int dp[1009][1009];

int f(int l, int r) {
	if(r == n) {
		return 0;
	}

	if(dp[l][r] != -1) {
		return dp[l][r];
	}
	
	int ans = f(l, r + 1);

	if (v[r].r < v[l].r) {	
		bool foo = true;
		if (v[r].cor == vermelho && v[l].cor == laranja) foo = false;
		if (v[r].cor == laranja && v[l].cor == azul) foo = false;
		if (v[r].cor == azul && v[l].cor == verde) foo = false;
		if (v[r].cor == verde && v[l].cor == vermelho) foo = false;
		if (foo) {
			ans = max(ans, f(r, r + 1) + v[r].h);
		}
	}
	
	return dp[l][r] = ans;
}

int main () {

	while (scanf("%d", &n) && n) {
		
		memset(v, 0, sizeof v);
		memset(dp, -1, sizeof dp);

		for (int i = 0; i < n; i++) {
			int h, r; scanf("%d %d", &h, &r);
			string p; cin >> p;
			int cor;
			if (p == "VERMELHO") cor = 1;
			if (p == "LARANJA") cor = 2;
			if (p == "VERDE") cor = 3;
			if (p == "AZUL") cor = 4;
			
			v[i] = cilindro(h, r, cor);
		}

		sort(v, v+n);
		int ans = 0;

		for (int i = 0; i < n; i++) {
			ans = max(ans, v[i].h + f(i, i+1));
		}

		printf("%d centimetro(s)\n", ans);
	}

	return 0;
}
