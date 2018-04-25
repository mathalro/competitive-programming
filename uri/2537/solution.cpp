#include <bits/stdc++.h>
#define maxn 1001

using namespace std;

int bit[maxn][maxn];
int n, m;

void update(int idx1, int idx2, int val) {
	while (idx1 <= n) {
		int idx = idx2;
		while (idx <= n) {
			bit[idx1][idx] += val;
			idx += (idx & -idx);
		}
		idx1 += (idx1 & -idx1);
	}
}

int query(int idx1, int idx2) {
	int sum = 0;
	while (idx1 > 0) {
		int idx = idx2;
		while (idx != 0) {
			sum += bit[idx1][idx];
			idx -= (idx & -idx);
		}
		idx1 -= (idx1 & -idx1);
	}
	return sum;
}

int compose_query(int i1, int j1, int i2, int j2) {
	return query(i2, j2) - query(i2, j1-1) - query(i1-1, j2) + query(i1-1, j1-1);
}

int main () {

	while (scanf("%d %d", &n, &m) != EOF) {
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				bit[i][j] = 0;
			}	
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int a; scanf("%d", &a);
				if (a) update(i, j, 1);
			}
		}

		m *= 2;
		for (int i = 0; i < m; i++) {
			if (i&1) {
				int a, b, c, d; scanf("%d %d %d %d", &a, &b, &c, &d);
				printf("%d\n", compose_query(a, b, c, d));
			} else {
				int a, b; scanf("%d %d", &a, &b);
				update(a, b, 1);
			}	
		}
	}

	return 0;
}
