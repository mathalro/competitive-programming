#include <bits/stdc++.h>
#define maxn 10000009
#define mod 1000000007

using namespace std;

char bit[maxn];
vector<int> primos;

int st[4*maxn];

void crivo() {
	for (int i = 2; i < maxn; i++) {
		if (!bit[i]) {
			primos.push_back(i);
			for (long long j = (long long)i*i; j < maxn; j += i) {
				bit[j] = 1;
			}
		}
	}
}

void build() {
	for (int i = 0; i < 4*maxn; i++) {
		st[i] = 1;
	}
}

void update(int no, int l, int r, int ul, int ur, int val) {
	if (l > ur || r < ul) return;
	if (l >= ul && r <= ur) {
		st[no] += val;
		return;
	}

	int mid = (l+r)/2;
	update(2*no, l, mid, ul, ur, val);
	update(2*no+1, mid+1, r, ul, ur, val);
	st[no] = ((long long)st[2*no]*st[2*no+1])%mod;
}

int query(int no, int l, int r, int ql, int qr) {
	if (l > qr || r < ql) return 1;
	if (l >= ql && r <= qr) return st[no];
	int mid = (l+r)/2;
	return ((long long)query(2*no, l, mid, ql, qr)*query(2*no+1, mid+1, r, ql, qr))%mod;	
}

int main () {

	crivo();
	build();
	long long n; scanf("%lld", &n);
	
	int i = 0;
	while (i < primos.size()) {
		int cont = 0;
		while (!(n%primos[i])) {
			cont++;
			n /= primos[i];
		}
		update(1, 1, maxn, primos[i], primos[i], cont);
		i++;
	}

	int p;
	while (scanf("%d", &p) != EOF) {
		update(1, 1, maxn, p, p, 1);
		printf("%d\n", query(1, 1, maxn, 1, p-1));
	}

	return 0;
}
