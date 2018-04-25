#include <bits/stdc++.h>
#define maxn 109

using namespace std;

struct pedra {
	char tam;
	int dist;
	bool val;
	bool operator < (const pedra &p) const {
		return dist < p.dist;
	}
};

vector<pedra> pedras;
string aux[maxn];

int n, d;

int ida() {

	int maximo = pedras[0].dist;
	int fim = pedras.size()-1;
	for (int i = 0; i < fim; i+=0) {
		if (pedras[i].tam == 'S') {
			pedras[i].val = false;
		}

		if ( i < fim-1 ) {
			if ( pedras[i].tam == 'S' and pedras[i+1].tam == 'S') {
				maximo = max(maximo, pedras[i+2].dist - pedras[i].dist );
				i+=2;
				continue;
			}
		}

		maximo = max(maximo, pedras[i+1].dist - pedras[i].dist);
		i++;
	}

	return maximo;

}

int volta() {

	int maximo = 0;
	int i = pedras.size()-1;
	while (i != 0) {
		int j = i-1;
		while (!(pedras[j].val)) {
			j--;
		}

		maximo = max(maximo, pedras[i].dist - pedras[j].dist);	
		i = j;
	}

	return maximo;
}

int main () {

	int t;
	scanf("%d", &t);

	for (int j = 0; j < t; j++) {
		scanf("%d %d", &n, &d);

		for (int i = 0; i < n; i++) {
			cin >> aux[i];
		}

		for (int i = 0; i < n; i++) {
			pedra p;
			p.tam = aux[i][0];
			string s = "";
			for (int j = 2; j < aux[i].size(); j++) {
				s += aux[i][j];
			}
			p.dist = atoi(s.c_str());
			p.val = true;
			pedras.push_back(p);
		}

		pedra inicio = {'B', 0, true};
		pedra fim = {'B', d, true};
		pedras.push_back(inicio);
		pedras.push_back(fim);

		sort(pedras.begin(), pedras.end());

		int a = ida();
		int b = volta();
		printf("Case %d: %d\n", j+1, max(a, b) );

		pedras.clear();
	}

	return 0;
}