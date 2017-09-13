#include <bits/stdc++.h>
#define maxn 20

using namespace std;

vector<int> grafo[maxn];
int visitado[maxn];

void dfs(int origem, int b) {
	visitado[origem] = 1;
	bool quebra = true;
	for (int i = 0; i < grafo[origem].size(); i++) {
		int v = grafo[origem][i];
		if (v != origem) {
			if (b == 2 && origem != 0 && quebra) { 
				quebra = false;
				printf("\n");
			}
			for (int j = 0; j < b; j++) {
				printf(" ");
			}
			if (!visitado[v]) {
				printf("%d-%d pathR(G,%d)\n", origem, v, v);
				dfs(v, b+2);
			}else {
				printf("%d-%d\n", origem, v);
			}
		}
	} 
}

int main () {
	int n,v, e, x, y;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &v, &e);
		for (int j = 0; j < v; j++) {
			grafo[j].clear();
			visitado[j] = 0;
		}
		for (int j = 0; j < e; j++) {
			scanf("%d %d", &x, &y);
			if (find(grafo[x].begin(), grafo[x].end(), y) == grafo[x].end())
				grafo[x].push_back(y);
		}

		for (int j = 0; j < v; j++) {
			sort(grafo[j].begin(), grafo[j].end());
		}

		printf("Caso %d:\n", i+1);
		for(int j = 0; j < v; j++) {
			if (!visitado[j]) { 
				dfs(j, 2);
			}
		}
		printf("\n");
	}

	return 0;
}