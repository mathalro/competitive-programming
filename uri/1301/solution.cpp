#include <bits/stdc++.h>
#define maxn 100009

using namespace std;


int st[4*maxn], v[maxn];
int n, k;

void build(int no, int l, int r) {
	if (l == r) {
		st[no] = v[l];
		return;
	}	
	int mid = (l+r)/2;	
	build(2*no, l, mid);
	build(2*no+1, mid+1, r);
	st[no] = st[2*no] * st[2*no+1];
}

void update(int no, int l, int r, int i, int val) {
	if (l > i || r < i) return;
	if (l == r) {
		st[no] = val;
		return;
	}
	int mid = (l+r)/2;
	update(2*no, l, mid, i, val);
	update(2*no+1, mid+1, r, i, val);
	st[no] = st[2*no] * st[2*no+1];
}

int query(int no, int l, int r, int ql, int qr) {
	if (l > qr || r < ql) return 1;
	if (l >= ql && r <= qr) return st[no];
	int mid = (l+r)/2;
	return query(2*no, l, mid, ql, qr) * query(2*no+1, mid+1, r, ql, qr);
}

int main () {

	while (scanf("%d %d", &n, &k) != EOF) {
		for (int i = 1; i <= n; i++) {
			int a; scanf("%d", &a);
			if (a > 0) v[i] = 1;
			else if (a < 0) v[i] = -1;
			else v[i] = 0;
		}

		build(1, 1, n);

		for (int i = 0; i < k; i++) {
			char c; int a, b; scanf(" %c %d %d", &c, &a, &b);
			if (c == 'C') {
				if (b > 0) b = 1;
				else if (b < 0) b = -1;
				else b = 0;
				update(1, 1, n, a, b);
			} else {
				int ans = query(1, 1, n, a, b);
				printf("%c", (ans == 0) ? '0' : (ans < 0) ? '-' : '+');
			}
		}puts("");
	}
	

	return 0;
}
