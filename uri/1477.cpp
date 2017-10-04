/*
	 accepted
*/

#include <bits/stdc++.h>
#define maxn 100009

using namespace std;

struct No {
	int h, e, r;
	No() {}
	No(int h, int e, int r) : h(h), e(e), r(r) {}
	No operator+(const No &a) const {
		return No(h+a.h, e+a.e, r+a.r);
	}
	void update(int n) {
		n%=3;
		for (int i = 0; i < n; i++) {
			int aux = e;
			e = h;
			h = r;
			r = aux;
		}
	}
};

int n, m;

No st[3*maxn];
int lz[3*maxn];

void build(int no, int l, int r) {
	lz[no] = 0;
	if (l == r) {
		st[no] = No(1, 0, 0);
		return;
	}
	int mid = (l+r)/2;
	build(2*no, l, mid);
	build(2*no+1, mid+1, r);
	st[no] = st[2*no] + st[2*no+1];
}

void prop(int no) {
	if (lz[no]) {
		st[2*no].update(lz[no]);
		st[2*no+1].update(lz[no]);
		lz[2*no] += lz[no];
		lz[2*no+1] += lz[no];
		lz[no] = 0;
	}
}

void update(int no, int l, int r, int ul, int ur) {
	if (l > ur || r < ul) return;
	if (l >= ul && r <= ur) {
		st[no].update(1);
		//cout << "U: " << st[no].h << ' ' << st[no].e << ' ' << st[no].r << endl;
		lz[no] += 1;
		return;
	}
	int mid = (l+r)/2;
	prop(no);
	update(2*no, l, mid, ul, ur);
	update(2*no+1, mid+1, r, ul, ur);
	st[no] = st[2*no]+st[2*no+1];
}

No query(int no, int l, int r, int ql, int qr) {
	if (l > qr || r < ql) return No(0, 0, 0);
	if (l >= ql && r <= qr) return st[no];
	int mid = (l+r)/2;
	prop(no);
	return query(2*no, l, mid, ql, qr)+query(2*no+1, mid+1, r, ql, qr);
}

int main () {
	while (scanf("%d %d", &n, &m) != EOF) {
		build (1, 1, n);
		for (int i = 0; i < m; i++) {
			char a;
			int b, c; scanf(" %c %d %d", &a, &b, &c);	
			if (a == 'M') {
				update(1, 1, n, b, c);	
			} else {
				No q = query(1, 1, n, b, c);
				printf("%d %d %d\n", q.h, q.e, q.r);
			}
		}puts("");
	}

	return 0;
}
