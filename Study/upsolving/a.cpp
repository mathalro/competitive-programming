#include <bits/stdc++.h>
#define maxn 100009

using namespace std;

struct No {
	int freq[9];
	No(){
		memset(freq, 0, sizeof freq);
	}
	No (int x, int p) {
		memset(freq, 0, sizeof freq);
		freq[p] = x;
	}

	No operator+(const No &b) const {
		No novo;
		for (int i = 0; i < 9; i++) {
			novo.freq[i] = freq[i] + b.freq[i];
		}
		return novo;
	}
};

No st[4*maxn];
int lz[4*maxn];

int mostFreq(int v[]) {
	int m = v[0], mf = 0;
	for (int i = 0; i < 9; i++) {
		//cout << v[i] << ' ';
		if (m <= v[i]) {
			m = v[i];
			mf = i;
		}
	}//cout << endl;
	return mf;
}

No shift(No atual, int f) {
	No novo = No();
	for (int i = 0; i < 9; i++) {
		novo.freq[(i+f)%9] = atual.freq[i];
	}
	return novo;
}

void build(int no, int l, int r) {
	if (l == r) {
		st[no].freq[1] = 1;
		return;
	}
	int mid = (l+r)>>1;
	build(2*no, l, mid);
	build(2*no+1, mid+1, r);
	st[no] = st[2*no]+st[2*no+1];
}

void prop(int no) {
	if (lz[no]) {
		int f = lz[no];
		st[2*no] = shift(st[2*no], f);
		st[2*no+1] = shift(st[2*no+1], f);
		lz[2*no] += f;
		lz[2*no+1] += f;
		lz[no] = 0;
	}
}

void update(int no, int l, int r, int ul, int ur, int f) {
	if (l > ur || r < ul) return;
	if (l >= ul && r <= ur) {
		st[no] = shift(st[no], f);
		lz[no] += f;
		return;
	}
	int mid = (l+r)>>1;
	prop(no);
	update(2*no, l, mid, ul, ur, f);
	update(2*no+1, mid+1, r, ul, ur, f);
	st[no] = st[2*no]+st[2*no+1];
}

No query(int no, int l, int r, int ql, int qr) {
	if (l > qr || r < ql) return No();
	if (l >= ql && r <= qr) {
		return st[no];
	}int mid = (l+r)>>1;
	prop(no);
	return query(2*no, l, mid, ql, qr) + query(2*no+1, mid+1, r, ql, qr);	
}

int main () {
	int n, q; scanf("%d %d", &n, &q);
	build(1, 1, n);
	for (int i = 0; i < q; i++) {
		int a, b; scanf("%d %d", &a, &b);
		a++; b++;
		int mf = mostFreq(query(1, 1, n, a, b).freq);
		update(1, 1, n, a, b, mf);
	}

	for (int i = 1; i <= n; i++) {
		printf("%d\n", mostFreq(query(1, 1, n, i, i).freq));
	}

	return 0;
}
