#include <bits/stdc++.h>
#define maxn 101

using namespace std;

int v[maxn];

int main () {

	int n, m; scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		int a, b; scanf("%d %d", &a, &b);
		for (int j = a; j < b; j++) {
			v[j] = 1;
		}
	}

	for (int i = 0; i < m; i++) {
		if (!v[i]) {
			printf("NO\n");
			return 0;
		}
	}

	printf("YES\n");

	return 0;
}
