#include <bits/stdc++.h>
#define maxn 1001

using namespace std;

int v[maxn], c[maxn];
int w[maxn][maxn];

int main () {

	int n, m; scanf("%d %d", &n, &m);
	int l; scanf("%d", &l);
	for (int i = 0; i < l; i++) {
		int a; scanf("%d", &a);
		a--;
		v[a]++;
	}
	
	for (int i = 0; i < n; i++) {
		int k; scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			int a; scanf("%d", &a);
			a--;
			w[i][a]++;
		}
	}
	
	if (!l) {
		printf("0\n");
		return 0;
	}
	
	for (int i = 0; i < 2*n; i++) {
		for (int j = 0; j < m; j++)
			if (w[i%n][j]) v[j] = !v[j];
		int cont = 0;
		for (int j = 0; j < m; j++) cont += v[j];
		if (!cont) {
			printf("%d\n", i+1);
			return 0;
		}
	}
	
	printf("-1\n");

	return 0;
}
