#include <bits/stdc++.h>
#define maxn 200001

using namespace std;

vector<int> g[maxn];
map<int, int> pos1, pos2;
int vis[maxn], v[maxn], tempo;
int st[4*maxn], lz[4*maxn];

void dfs(int u) {
	vis[u] = 1;
	pos1[u] = tempo++;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (!vis[v]) {
			dfs(v);
		}
	}

	pos2[u] = tempo-1;
}

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

void print(int no, int l, int r) {
	if (l == r) {
		cout << st[no] << endl;
		return;
	}
	int mid = (l+r)/2;
	print(2*no, l, mid);
	print(2*no+1, mid+1, r);
}

void propag(int no, int l, int r, int mid) {
	if (lz[no]) {
		st[2*no] = (mid-l+1)-st[2*no];
		st[2*no+1] = (r-mid)-st[2*no+1];
		lz[2*no] = !lz[2*no];
		lz[2*no+1] = !lz[2*no+1];
		lz[no] = 0;
	}
}

void update(int no, int l, int r, int ul, int ur) {
	if (l > ur || r < ul) return;
	if (l >= ul && r <= ur) {
		st[no] = (r-l+1)-st[no];
		lz[no] = !lz[no];
		return;
	}

	int mid = (l+r)/2;
	propag(no, l, r, mid);
	update(2*no, l, mid, ul, ur);
	update(2*no+1, mid+1, r, ul, ur);
	st[no] = st[2*no] + st[2*no+1];
}

int query(int no, int l, int r, int ql, int qr) {
	if (l > qr || r < ql) return 0;
	if (l >= ql && r <= qr) return st[no];
	int mid = (l+r)/2;
	propag(no, l, r, mid);
	return query(2*no, l, mid, ql, qr) + query(2*no+1, mid+1, r, ql, qr);
}

int main () {

	int n; cin >> n;
	for (int i = 2; i <= n; i++) {
		int a; cin >> a;
		g[a].push_back(i);
		g[i].push_back(a);
	}

	tempo = 1;
	dfs(1);

	for (int i = 1; i <= n; i++) {
		int a; cin >> v[pos1[i]];
		int pos = pos1[i];
	}

	build(1, 1, n);
	int m; cin >> m;

	for (int i = 0; i < m; i++) {
		string s; cin >> s;
		int a; cin >> a;			
		if (s == "get") {
			cout << query(1, 1, n, pos1[a], pos2[a]) << endl;
		} else {
			update(1, 1, n, pos1[a], pos2[a]);
		}
	}

}
