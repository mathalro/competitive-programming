#include <bits/stdc++.h>
#define maxn 100001

using namespace std;

struct No {
	int i, v;
	bool operator<(No a) const {
		if (v == a.v) {
			return i > a.i;
		} else {
			return v < a.v;  
		}
	};
};

int v[maxn];
No st[4*maxn];
int lz[4*maxn];

void build(int no, int l, int r) {
	if (l == r) {
		st[no] = {l, v[l]};
		lz[no] = 0;
		return;
	}
	int mid = (l+r)/2;
	build(2*no, l, mid);
	build(2*no+1, mid+1, r);
	st[no] = max(st[2*no], st[2*no+1]);
}

void prop(int no, int mid, int l, int r) {
	if (lz[no]) {
		st[2*no].v += lz[no];
		st[2*no+1].v += lz[no];
		lz[2*no] += lz[no];
		lz[2*no+1] += lz[no];
		lz[no] = 0;
	}
}

void update(int no, int l, int r, int ul, int ur, int val) {
	if (l > ur || r < ur) return;
	if (l == r && l >= ul && r <= ur) {
		st[no].v += val;
		lz[no] += val;
		return;
	}
	int mid = (l+r)/2;
	//prop(no, mid, l, r);
	update(2*no, l, mid, ul, ur, val);
	update(2*no+1, mid+1, r, ul, ur, val);
	st[no] = max(st[2*no], st[2*no+1]);
}

No query(int no, int l, int r, int ql, int qr) {
	if (l > qr || r < ql) return {0, -1};
	if (l >= ql && r <= qr) return st[no];
	int mid = (l+r)/2;
	//prop(no, mid, l, r);
	return max(query(2*no, l, mid, ql, qr), query(2*no+1, mid+1, r, ql, qr));
}

int main () {

	int n, q;

	while (scanf("%d %d", &n, &q) != EOF) {
		for (int i = 1; i <= n; i++) {
			scanf("%d", v+i);
		}

		build(1, 1, n);

		for (int i = 0; i < q; i++) {
			char c; scanf(" %c", &c);
			if (c == 'A') {
				int x, y, z; scanf("%d %d %d", &x, &y, &z);
				update(1, 1, n, x, y, z);
			} else {
				int x, y; scanf("%d %d", &x, &y);
				printf("%d\n", query(1, 1, n, x, y).i);
			}
		}
	}

	return 0;
}
