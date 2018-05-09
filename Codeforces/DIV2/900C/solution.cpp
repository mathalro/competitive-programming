#include <bits/stdc++.h>
#define maxn 100001
#define inf 0x3f3f3f3f

using namespace std;

int v[maxn];
int p[maxn];
int c[maxn];

int main () {

	int aux = inf;
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", v+i);	
	}

	int maior, segMaior;
	if (v[1] > v[2]) {
		maior = 1;
		segMaior = 2;
		p[2] = 1;
	} else {
		maior = 2;
		segMaior = 1;
		p[2] = 0;
	}

	p[1] = 0;

	for (int i = 3; i <= n; i++) {
		if (v[i] < v[maior]) {
			p[i] = maior;
			if (v[i] < v[segMaior]) {
				p[i] = -1;
			}
		}
		if (v[i] > v[maior]) {
			segMaior = maior;
			maior = i;
		} else if (v[i] > v[segMaior]) {
			segMaior = i;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (p[i] > 0) {
			c[p[i]]++;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		if (p[i] == 0) {
			c[i]--;
		}
	}

	int maiorRec = 0;

	for (int i = 1; i <= n; i++) {
		if (c[maiorRec] < c[i]) {
			maiorRec = i;
		}
	}

	if (c[maiorRec] < 1) {
		int tmp = inf;
		for (int i = 1; i <= n; i++) {
			if (p[i] == -1) {
				tmp = min(tmp, v[i]);
			}
		}

		if (tmp == inf) {
			for (int i = 1; i <= n; i++) {
				tmp = min(tmp, v[i]);
			}
		}
		printf("%d\n", tmp);
	} else {
		printf("%d\n", v[maiorRec]);
	}

	return 0;
}
