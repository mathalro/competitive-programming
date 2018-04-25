#include <bits/stdc++.h>
#define maxn 100001

using namespace std;

int st[4*maxn];

void update(int no, int l, int r, int ul, int ur, int val) {
	if (l > ur || r < ul) return;
	if (l == r) {
		st[no]++;
		return;
	}
	int mid = (l+r)/2;
	update(2*no, l, mid, ul, ur, val);
	update(2*no+1, mid+1, r, ul, ur, val);
	st[no] = st[2*no] + st[2*no+1];
}

int query(int no, int l, int r, int ql, int qr) {
	if (l > qr || r < ql) return 0;
	if (l >= ql && r <= qr) return st[no];
	int mid = (l+r)/2;
	return query(2*no, l, mid, ql, qr) + query(2*no+1, mid+1, r, ql, qr);
}

int main () {

	int ip, m;

	while (scanf("%d %d", &ip, &m) != EOF) {
		memset(st, 0, sizeof st);
		int cont = 0;
		for (int i = 0; i < m; i++) {
			int pc, na; scanf("%d %d", &pc, &na);
			if (query(1, 1, maxn, pc-ip, pc+ip) <= na) {
				cont++;
				update(1, 1, maxn, pc, pc, 1);
			}
		}

		printf("%d\n", cont);
	}

	return 0;
}
