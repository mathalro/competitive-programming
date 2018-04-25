#include <bits/stdc++.h>
#define maxn 100009

using namespace std;

int n, c;
long long st[4*maxn], lz[4*maxn];

void prop(int no, int l, int r, int mid) {
	st[2*no] += (mid-l+1)*lz[no];
	st[2*no+1] += (r-(mid+1)+1)*lz[no];
	lz[2*no] += lz[no];
	lz[2*no+1] += lz[no];
	lz[no] = 0;
}

void update(int no, int l, int r, int ul, int ur, long long val) {
	if (l > ur || r < ul) return;
	if (l >= ul && r <= ur) {
		st[no] += (r-l+1)*val;
		lz[no] += val;
		return;
	}
	int mid = (l+r)/2;
	prop(no, l, r, mid);
	update(2*no, l, mid, ul, ur, val);
	update(2*no+1, mid+1, r, ul, ur, val);
	st[no] = st[2*no] + st[2*no+1];
}

long long query(int no, int l, int r, int ql, int qr) {
	if (l > qr || r < ql) return 0;
	if (l >= ql && r <= qr) {
		return st[no];
	}

	int mid = (l+r)/2;
	prop(no, l, r, mid);
	return query(2*no, l, mid, ql, qr) + query(2*no+1, mid+1, r, ql, qr);
}

int main () {

	int t; scanf("%d", &t);

	while (t--) {
		scanf("%d %d", &n, &c);
		for (int i = 0; i <= 4*n; i++) st[i] = lz[i] = 0;
		for (int i = 0; i < c; i++) {
			int x, y, w; scanf("%d %d %d", &x, &y, &w);
			if (!x) {
				int z; scanf("%d", &z);
				update(1, 1, n, y, w, z);
			} else {
				printf("%lld\n", query(1, 1, n, y, w));
			}
		}
	}

	return 0;
}
