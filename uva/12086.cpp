#include <bits/stdc++.h>
#define maxn 200001

using namespace std;

int st[4*maxn];
int v[maxn];

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

void update(int no, int l, int r, int ul, int ur, int val) {
	if (l > ur || r < ul) return;
	if (l == r) {
		st[no] = val;
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
	
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n; 

	int t = 1;
	while (cin >> n && n) {
		for (int i = 1; i <= n; i++) {
			cin >> v[i];
		}
		if (t > 1) cout << "\n";
		build(1, 1, n);	
		cout << "Case " << t++ << ":" << "\n"; 
		string s;
		while (cin >> s && s != "END") {
			int x, y; cin >> x >> y;	
			if (s == "S") {
				update(1, 1, n, x, x, y);
			} else {
				cout << query(1, 1, n, x, y) << endl;
			}
 		}
	}


	return 0;
}
