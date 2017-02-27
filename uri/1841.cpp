#include <bits/stdc++.h>
#define maxn 10000009
#define mod 1000000007

using namespace std;

char bits[maxn];
vector<int> primo;

int st[4*maxn];

void crivo() {

	for (long long int i = 2; i < maxn; i++) {
		if (bits[i] == 0) {
			primo.push_back(i);
			if (i*i < maxn) {
				for (long long j = i*i; j < maxn; j += i) {
					bits[j] = 1;
				}
			}
		}
	}

}

void inicia() {

	for (int i = 0; i < 4*maxn; i++) {
		st[i] = 1;
	}

}


void update(int no, int esq, int dir, int pos) {

	if ( esq == dir ) {
		st[no]++;
		return;
	}

	int mid = (esq+dir) / 2;

	if ( pos <= mid ) {
		update(2*no, esq, mid, pos);
	} else {
		update(2*no+1, mid+1, dir, pos);
	}

	st[no] = (st[2*no]*(long long)st[2*no+1]) % mod;

}

int query(int no, int esq, int dir, int i, int j) {

	if ( i > dir || j < esq ) {
		return 1;
	}
	if ( i <= esq && j >= dir ) {
		return st[no];
	} 

	int mid = (esq + dir) / 2;

	return ( query(2*no, esq, mid, i, j)*(long long)query(2*no+1, mid+1, dir, i, j) ) % mod;

}

int main () {

	long long n;
	int ini, fim, p;

	crivo();
	inicia();

	scanf("%lld", &n);

	fim = primo.size()-1;

	for (int i = 0; i <= fim; i++) {
		while ( !(n%primo[i]) ) {
			update(1, 1, maxn, primo[i]);
			n /= primo[i];
		}
	}

	while (scanf("%d", &p) != EOF) {
		printf("%lld\n", query(1, 1, maxn, ini, p-1));
		update(1, 1, maxn, p);
	}

	return 0;
}