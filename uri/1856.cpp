#include <bits/stdc++.h>
#define maxn 500001
#define smaxn 400

using namespace std;

int v[maxn];
int vsum[smaxn];
int n, bsize;

int build() {
	for (int i = 0; i < n; i++) vsum[i/bsize] += v[i];
}

int update(int pos, int val) {
	vsum[pos/bsize] += val-v[pos];
	v[pos] = val;
}

int query(int l, int r) {
	int sum = 0;
	while (l < r && l%bsize != 0 && l != 0) sum += v[l++];
	while ((l+bsize) <= r) sum += vsum[l/bsize], l += bsize;
	while (l <= r) sum += v[l++];
	return sum;
}

int main () {
	scanf("%d", &n);
	bsize = sqrt(n);

	for (int i = 0; i < n; i++) {
		scanf("%d", v+i);
	}

	build();

	int q; scanf("%d", &q);

	for (int i = 0; i < q; i++) {
		char c; scanf(" %c", &c);
		if (c == 'I') {
			int p, e; scanf("%d %d", &p, &e);
			update(p, e);
		} else if (c == 'R') {
			int e; scanf("%d", e);
		} else {
			int a, b; scanf("%d %d", &a, &b);
			printf("%d\n", query(a, b));
		}
	}
}
