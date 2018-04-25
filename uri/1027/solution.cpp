#include <bits/stdc++.h>
#define maxn 1001

using namespace std;

struct coordenada {
	int x, y;
	bool operator < (coordenada outro) const {
		return x < outro.x;
	}
};

coordenada ponto[maxn];

int h1, h2, n;

int f(int x, int pos) {
	int maior = 0;

	for (register int i = x+1; i < n; i++) {
		if (ponto[x].x < ponto[i].x) {
			if (pos && ponto[i].y == h2 || !pos && ponto[i].y == h1) {
				maior = max(maior, 1+f(i, !pos));
			}
		}
	}

	return maior;
}

int main () {

	ios_base::sync_with_stdio(0); cin.tie(0);

	while (cin >> n) {

		for (register int i = 0; i < n; i++) {
			cin >> ponto[i].x >> ponto[i].y;
		}

		sort(ponto, ponto+n);

		int maior = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				if (ponto[i].x < ponto[j].x && abs(ponto[i].y-ponto[j].y) == 2) {
					h1 = max(ponto[i].y, ponto[j].y);
					h2 = min(ponto[i].y, ponto[j].y);

					maior = max(maior, 1+f(j, ponto[j].y == h1));
				}
			}
		}

		cout << 1+maior << "\n";
	}

	return 0;
}
