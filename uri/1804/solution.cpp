#include <bits/stdc++.h>
#define maxn 100009

using namespace std;

int v[maxn], st[4*maxn];

void build(int no, int l, int r) {
	if (l == r) {
		st[no] = v[l];
		return;
	}
	int mid = (l+r)/2;
	build(2*no, l, mid);
	build(2*no+1, mid+1, r);
	st[no] = st[2*no] + st[2*no+1];
}

void update(int no, int l, int r, int i) {
	if (l > i || r < i) return;
	if (l == r) {
		st[no] = 0;
		return;
	}
	int mid = (l+r)/2;
	update(2*no, l, mid, i);
	update(2*no+1, mid+1, r, i);
	st[no] = st[2*no] + st[2*no+1];
} 

int query(int no, int l, int r, int ql, int qr) {
	if (l > qr || r < ql) return 0;
	if (l >= ql && r <= qr) return st[no];
	int mid = (l+r)/2;
	return query(2*no, l, mid, ql, qr) + query(2*no+1, mid+1, r, ql, qr);
}

int main () {
	int n; scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", v+i);
	}

	build(1, 1, n);

	char c; int a;
	while (scanf(" %c %d", &c, &a) != EOF) {
		if (c == '?') {
			printf("%d\n", query(1, 1, n, 1, a-1));
		} else {
			update(1, 1, n, a);
		}
	}

	return 0;
}
