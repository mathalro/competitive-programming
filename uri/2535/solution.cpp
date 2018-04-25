#include <bits/stdc++.h>
#define maxn 55

using namespace std;

struct peca {
	int a, b, c;
	bool operator < (peca outro) const {
		a <= outro.a;
	}
};

peca v[maxn];
int n;

int f(int ponta) {
	int maior = 0;
	for (int i = 0; i < n; i++) {
		if (v[i].c) {
			v[i].c = 0;
			if (v[i].a == ponta) maior = max(maior, 1+f(v[i].b));
			if (v[i].b == ponta) maior = max(maior, 1+f(v[i].a));
			v[i].c = 1;
		}
	}
	return maior;
}

int main () {

	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			int a, b; scanf("%d %d", &a, &b);
			v[i] = {a, b, 1};
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			v[i].c = 0;
			ans = max(ans, 1+max(f(v[i].a), f(v[i].b)));
			v[i].c = 1;
		}
		printf("%d\n", ans);
	}

	return 0;
}
