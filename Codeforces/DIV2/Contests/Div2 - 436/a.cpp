#include <bits/stdc++.h>
#define maxn 102

using namespace std;

int v[maxn];

int main () {

	int n; scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		v[a]++;
	}

	int cont = 0, a, b;
	for (int i = 0; i < 101; i++) {
		if (cont > 1 && v[i]) {
			printf("NO\n");
			return 0;
		}
		if (!cont && v[i]) {
			cont++;
			a = i;
		}else {
			if (cont == 1 && v[i]) {
				cont++;
				b = i;
			}
		}
	}

	if (cont > 1 && v[a] == v[b]) {
		printf("YES\n%d %d\n", a, b);
	} else {
		printf("NO\n");
	}

	return 0;
}
