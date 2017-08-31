#include <bits/stdc++.h>
#define maxn 200009

using namespace std;

struct No {
	int n13, n7, val;
	No() {}
	No(int n13, int n7, int val) : n13(n13), n7(n7), val(val) {}
	No operator + (No a, No b) const {
		return No(a.n13+b.n13, a.n7+b.n7, a.val+b.val);
	}
};

int n;
int v[maxn];

No st[4*maxn];
No lz[4*maxn];

void build(int no, int l, int r) {
	if (l == r) {
		st[no].val = v[l];
		return;
	}

	int mid = (l+r)/2;
	build(2*no, l, mid);
	build(2*no+1, mid+1, r);
	st[no] = st[2*no] + st[2*no+1];
}

void update(int no, int l, int r, int lu, int ru, int tipo, int val) {
	
}

int main () {
	
	while (scanf("%d", &n) != EOF) {
		for (int i = 1; i <= n; i++) {
			scanf("%d", v+i);
		}

		build(1, 1, n);

		int q; scanf("%d", &q);

		for (int t = 0; t < q; t++) {
			int t; scanf("%d", &t);

			if (t == 1) {
				int i, v; scanf("%d %d", &i, &v);			
			} else if (t == 2) {
				int i, j, z, v; scnaf("%d %d %d %d", &i, &j, &z, &v);
			} else {
				int i. j; scanf("%d %d", &i, &j);
			}
		}
	}

	return 0;
}
