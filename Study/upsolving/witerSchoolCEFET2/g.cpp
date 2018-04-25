#include <bits/stdc++.h>
#define maxn 1000000

using namespace std;
typedef long long ll;

int st[4*maxn];
int lz[4*maxn];

void propag(int no, int l, int r, int mid) {
	st[2*no] += lz[no]*(mid-l+1);
	st[2*no+1] += lz[no]*(r-(mid+1)+1);
	lz[2*no] += lz[no];
	lz[2*no+1] += lz[no];
	lz[no] = 0;
}

void update(int no, int l, int r, int ul, int ur, int val) {
	if (l > ur || r < ul) return;
  if (l >= ul && r <= ur) {
		st[no] += (r-l+1)*val;
		lz[no] += val;
		return;
	}
	int mid = (l+r)/2;
	propag(no, l, r, mid);
	update(2*no, l, mid, ul, ur, val);
	update(2*no+1, mid+1, r, ul, ur, val);
	st[no] = st[2*no] + st[2*no+1];
}

int query(int no, int l, int r, int ql, int qr) {
	if (l > qr || r < ql) return 0;
	if (l == r) return 	st[no];
	int mid = (l+r)/2;
	propag(no, l, r, mid);
	return query(2*no, l, mid, ql, qr) + query(2*no+1, mid+1, r, ql, qr);
}

int main() {
	int n;
	while (scanf("%d", &n) && n) {
		bool foo = false;
		memset(st, 0, sizeof st);
		memset(lz, 0, sizeof lz);
		string ans = "";
		printf("MENSAGEM: [");
		for (int i = 0; i < n; i++) {
			int a; scanf("%d", &a);
			if (!foo) {
				if (a == 18) {
					int c, d, e; scanf("%d %d %d", &c, &d, &e);
					i += 3;
					update(1, 1, maxn, c+1, d+1, e);
				} else if (a == 42) {
					int b; scanf("%d", &b);
					i++;
					int x = query(1, 1, maxn, b+1, b+1);
					int y = query(1, 1, maxn, b, b);
					int z = x-y;
					if (z < 0) ans += " ";
					else ans += ('A'+(z%26));
				} else {
					foo = true;
				}
			}
		}
		printf("%s]\n", ans.c_str());
	}		
}
