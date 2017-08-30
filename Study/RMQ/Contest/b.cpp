#include <bits/stdc++.h>
#define maxn 50009 
#define maxt 1000000002

using namespace std;

struct op {
	char c;
	int a, b;
} ops[maxn];

map<int, int> id;
map<int, int> donoId;
map<int, int> direita;
map<int, int> idAtual;
map<int, int> inimigoNovoNumero;

int v[maxn];
int st[8*maxn];

void update(int no, int l, int r, int ul, int ur, int val) {
	if (l > ur || r < ul) return;
	if (l >= ul && r <= ur) {
		st[no] += val;
		return;
	}

	int mid = (l+r)/2;
	update(2*no, l, mid, ul, ur, val);
	update(2*no+1, mid+1, r, ul, ur, val);
	st[no] = st[2*no] + st[2*no+1];
}

int query(int no, int l, int r, int ql, int qr) {
	if (l >= qr || r <= ql) return 0;
	if (l > ql && r < qr) return st[no];
	int mid = (l+r)/2;
	return query(2*no, l, mid, ql, qr) + query(2*no+1, mid+1, r, ql, qr);
}

int main() {
	int n; scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", v+i);
		id[v[i]] = id.size();
		donoId[id[v[i]]] = v[i];
		idAtual[v[i]] = id[v[i]];
		if (i < n-1) direita[id[v[i]]] = id[v[i]] + 1;
		else direita[id[v[i]]] = -1;
	}

	// le todas as qeuryes
	int q; scanf("%d", &q);
	for(int i = 0, count = 1; i < q; i++, count++) {
		scanf(" %c %d", &ops[i].c, &ops[i].a);
		if (ops[i].c == 'Q') {
			scanf("%d", &ops[i].b);
		} else if (ops[i].c == 'I'){
			scanf("%d", &ops[i].b);
			int novo = maxt + count; count++;
			inimigoNovoNumero[novo] = ops[i].a;
			ops[i].a = novo;

			// cria uma nova identificacao para o inimigo a ser inserido
			id[ops[i].a] = id.size();
			idAtual[inimigoNovoNumero[ops[i].a]] = id[ops[i].a];
			donoId[id[ops[i].a]] = ops[i].a;
			
			// insere entre na lista encadeada
			novo = id[ops[i].a]; 
			int pai = idAtual[ops[i].b];
			direita[novo] = direita[pai];
			direita[pai] = novo;
		}
	}

	int i = 1, pai = 1;
	for (int i = 1, pai = 1; pai != -1; i++) {
		id[donoId[pai]] = i;
		pai = direita[pai];
	}

	idAtual.clear();

	for(i = 0; i < n; i++) {
		update(1, 1, id.size(), id[v[i]], id[v[i]], 1);
		idAtual[v[i]] = id[v[i]];
	}

	for(i = 0; i < q; i++) {
		if (ops[i].c == 'Q') { 
			printf("%d\n", query(1, 1, id.size(), min(idAtual[ops[i].a], idAtual[ops[i].b]), max(idAtual[ops[i].a], idAtual[ops[i].b])));
		}	else if (ops[i].c == 'R') {
			update(1, 1, id.size(), idAtual[ops[i].a], idAtual[ops[i].a], -1);
		} else {
			update(1, 1, id.size(), id[ops[i].a], id[ops[i].a], 1);
			idAtual[inimigoNovoNumero[ops[i].a]] = id[ops[i].a];		
		}
	}

	return 0;
}
