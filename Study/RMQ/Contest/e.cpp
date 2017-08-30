/*

5 2
1 2 5 4 5
1 5 0
4 5 8

O jogo não seria?

0 0 0 0 0 -> Impossivel
0 0 0 8 8 -> Impossivel

*/


#include <bits/stdc++.h>
#define maxn 100099

using namespace std;

int st[4*maxn];
int lz[4*maxn];
int v[maxn];

void build(int no, int l, int r) {
	if (l == r) {
		st[no] = v[l];
		return;
	}
	int mid = (l+r)/2;
	build(2*no, l, mid);
	build(2*no+1, mid+1, r);
	st[no] = st[2*no]^st[2*no+1];
}

void prop(int no, int l, int r, int mid) {
	if ((mid-l+1)&1) st[2*no] = lz[no];
	else st[2*no] = 0;

	if ((r-mid)&1) st[2*no+1] = lz[no];
	else st[2*no+1] = 0;

	lz[2*no] = lz[2*no+1] = lz[no];
	lz[no] = 0;
}

void update(int no, int l, int r, int ul, int ur, int val) {
	if (l > ur || r < ul) return;
	if (l >= ul && r <= ur) {
		int interv = r-l+1;
		if (interv&1) {
			st[no] = val;
		} else {
			st[no] = 0;
		}
		lz[no] = val;
		return;
	}

	int mid = (l+r)/2;
	if (lz[no]) prop(no, l, r, mid);
	update(2*no, l, mid, ul, ur, val);
	update(2*no+1, mid+1, r, ul, ur, val);
	st[no] = st[2*no] ^ st[2*no+1];
}

int main () {
	
	ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	build(1, 1, n);
	memset(lz, 0, sizeof lz);

	int x, y, v;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> v;
		update(1, 1, n, x, y, v);
		if (st[1]) {
			cout << "Possivel\n";
		} else {
			cout << "Impossivel\n";
		}
	}

	return 0;
}
