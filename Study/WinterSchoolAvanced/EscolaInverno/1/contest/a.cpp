#include <bits/stdc++.h>
#define maxn 100009

using namespace std;

struct no {
	int val, l, r, size;
};

no stp[64*maxn];
int st[maxn];
map<int, int> pos;

int indice;

int build(int l, int r) {
	
	if (l > r) return 0;						// caso base

	int id = indice++;							// incrementa na contagem
	int mid = (l+r)/2;							// encontra meio

	stp[id] = {mid, build(l, mid-1), build(mid+1, r), 0};		// filho da esquerda

	return id;
}

int update (int pos, int val) {
	if (pos == 0) return 0;								// caso base

	int id = indice++;									// incrementa na contagem, pois estpa adicionando mais um
	int l = stp[pos].l;									// pega o valor do filho esquerdo
	int r = stp[pos].r;									// pega o valor do filho direito
	
	if (val < stp[pos].val) l = update(l, val);			// atualiza filho da esquerda
	if (val > stp[pos].val) r = update(r, val);			// atualiza filho da direita
	
	stp[id] = {stp[pos].val, l, r, stp[pos].size + 1};

	return id;
}

int query(int pos, int val) {
	if (pos != 0 && val < stp[pos].val) {
		return query(stp[pos].l, val) + stp[pos].size - stp[stp[pos].l].size;
	}

	if (pos != 0 && val > stp[pos].val) {
		return query(stp[pos].r, val);	
	}

	return stp[pos].size - stp[stp[pos].l].size;
}

int main () {
	int n, q; 
	
	while (scanf("%d %d", &n, &q) && n) {
		
		cout << n << ' ' << q << endl;

		memset(stp, 0, sizeof stp);
		memset(st, 0, sizeof st);
		indice = 1;
		pos.clear();
		
		st[0] = build(1, n);
		for (int i = 1; i <= n; i++) {
			int x, posx;
			scanf("%d", &x);
			posx = pos[x];
			if (posx != 0) {
				st[i] = update(st[i-1], posx);
			} else {
				st[i] = update(st[i-1], i);			
			}		
			pos[x] = i; 
		}

		while (q--) {
			int l, r;
			scanf("%d %d", &l, &r);
			printf("%d\n", query(st[r], l));
		}
	}
	
	return 0;
}
