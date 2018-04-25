#include <bits/stdc++.h>
#define maxn 500001

using namespace std;

int v[maxn], ida[maxn];

int main () {
	int n; scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", v+i);
	}

	int atual = 0;
	for (int i = 0; i < n-1; i++) {
		if (v[i] >= atual) {
			ida[i] = ++atual;
		} else {
			ida[i] = v[i];
			atual = v[i];
		}
	}

	int maior = 0;
	atual = 0;
	for (int i = n-1; i >= 0; i--) {
		if (v[i] >= atual) {
			if (atual == ida[i]) {
				maior = max(atual, maior);
			}
			atual++;
		} else {
			atual = v[i];
		}
	}

	printf("%d\n", maior);

	return 0;
}
