#include <bits/stdc++.h>
#define maxn 200001

using namespace std;

struct No {
	int _13, _7, sum;
	No() {}
	No(int _13, int _7, int sum) : _13(_13), _7(_7), sum(sum) { } 
	No operator +(const No &a) const {
		return No(_13+a._13, _7+a._7, sum+a.sum);
	}
};

int v[maxn];

No st[4*maxn];
int lz13[4*maxn], lz7[4*maxn]; 

void build(int no, int l, int r) {
	if (l == r) {
		st[no] = No(v[l]==13, v[l]==7, v[l]);
		return;
	}
	int mid = (l+r)/2;
	build(2*no, l, mid);
	build(2*no+1, mid+1, r);
	st[no] = st[2*no] + st[2*no+1];
}

void prop(int no) {
	int a, b;
	if (lz13[no] != -1 && lz13[no] != 13) {
		a = st[2*no]._13*13, b = st[2*no]._13*lz13[no];
		st[2*no] = No(0, st[2*no]._7+((lz13[no]==7)*st[2*no]._13), st[2*no].sum+b-a);
		a = st[2*no+1]._13*13, b = st[2*no+1]._13*lz13[no];
		st[2*no+1] = No(0, st[2*no+1]._7+((lz13[no]==7)*st[2*no+1]._13), st[2*no+1].sum+b-a);
		lz13[2*no] = lz13[no];
		lz13[2*no+1] = lz13[no];
		lz13[no] = -1;
	}
	if (lz7[no] != -1 && lz7[no] != 7) {
		a = st[2*no]._7*7, b = st[2*no]._7*lz7[no];
		st[2*no] = No(st[2*no]._13+((lz7[no]==13)*st[2*no]._7), 0, st[2*no].sum+b-a);
		a = st[2*no+1]._7*7, b = st[2*no+1]._7*lz7[no];
		st[2*no+1] = No(st[2*no+1]._13+((lz7[no]==13)*st[2*no+1]._7), 0, st[2*no+1].sum+b-a);
		lz7[2*no] = lz7[no];
		lz7[2*no+1] = lz7[no];
		lz7[no] = -1;
	}
}

void update1(int no, int l, int r, int ul, int ur, int val) {
	if (l > ur || r < ul) return;
	if (l == r) {
		st[no] = No(val==13, val==7, val);
		return;
	}
	int mid = (l+r)/2;
	prop(no);
	update1(2*no, l, mid, ul, ur, val);
	update1(2*no+1, mid+1, r, ul, ur, val);
	st[no] = st[2*no] + st[2*no+1];
}

void update2(int no, int l, int r, int ul, int ur, int z, int val) {
	if (l > ur || r < ul) return;
	if (l >= ul && r <= ur) {
		if (z == 13 && val != 13) {
			int a = st[no]._13*13, b = st[no]._13*val;
			lz13[no] = val;
			st[no] = No(0, st[no]._7+((val==7)*st[no]._13), st[no].sum+b-a);
		} else if (z == 7 && val != 7) {
			int a = st[no]._7*7, b = st[no]._7*val;
			lz7[no] = val;
			st[no] = No(st[no]._13+((val==13)*st[no]._7), 0, st[no].sum+b-a);
		}
		return;
	}
	int mid = (l+r)/2;
	prop(no);
	update2(2*no, l, mid, ul, ur, z, val);
	update2(2*no+1, mid+1, r, ul, ur, z, val);
	st[no] = st[2*no] + st[2*no+1];
}

No query(int no, int l, int r, int ql, int qr) {
	if (l > qr || r < ql) {
		return No(0, 0, 0);
	}
	if (l >= ql && r <= qr) {		
		//cout << "Q: " << st[no].sum << ' ' << st[no]._7 << ' ' << st[no]._13 << endl;
		return st[no];
	}

	int mid = (l+r)/2;
	prop(no);
	return query(2*no, l, mid, ql, qr) + query(2*no+1, mid+1, r, ql, qr);
}

int main () {

	int n;

	while (scanf("%d", &n) != EOF) {
		for (int i = 1; i <= n; i++) {
			scanf("%d", v+i);
		}

		for (int i = 0; i <= 4*n; i++) {
			lz13[i] = lz7[i] = -1;
			st[i] = No(0, 0, 0);
		}
		build(1, 1, n);

		int q; scanf("%d", &q);
		for (int i = 0; i < q; i++) {
			int t, a, b; scanf("%d %d %d", &t, &a, &b);
			if (t == 1) {
				update1(1, 1, n, a, a, b);
			} else if (t == 2) {
				int c, d;
				scanf("%d %d", &c, &d);
				update2(1, 1, n, a, b, c, d);
			} else {
				printf("%d\n", query(1, 1, n, a, b).sum);
			}
		}
		
	}

	return 0;
}
