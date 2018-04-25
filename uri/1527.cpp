#include <bits/stdc++.h>
#define maxn 100001

using namespace std;

int pais[maxn];
int	pont[maxn];
int ranc[maxn];

int find(int a) {
	if (a == pais[a]) return a;
	return pais[a] = find(pais[a]);
}

void unionSet(int a, int b) {
	int paiA = find(a);
	int paiB = find(b);

	if (ranc[paiA] > ranc[paiB]) {
		pont[paiA] += pont[paiB];
		pais[paiB] = pais[paiA];
	} else if (ranc[paiA] <= ranc[paiB]) {
		pont[paiB] += pont[paiA];
		pais[paiA] = pais[paiB];
		if (ranc[paiA] == ranc[paiB]) ranc[paiA]++;
	}
}

int main () {
	int n, m;

	while (scanf("%d %d", &n, &m) && n) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &pont[i]);
			pais[i] = i;
			ranc[i] = 0;
		}

		int cont = 0;
		for (int i = 0; i < m; i++) {
			int a, b, c; scanf("%d %d %d", &a, &b, &c);
			b--; c--;
			if (a == 1) {
				unionSet(b, c);
			} else {
				find(0);
				find(b);
				find(c);
				if (pais[0] == pais[b]) {
					cont += (pont[pais[b]] > pont[pais[c]]);
				} else if (pais[0] == pais[c]) {
					cont += (pont[pais[c]] > pont[pais[b]]);
				}
			}
		}

		printf("%d\n", cont);
	}	

	return 0;
}
