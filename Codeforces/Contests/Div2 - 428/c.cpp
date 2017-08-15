#include <bits/stdc++.h>
#define maxn 100009

using namespace std;

struct par {
	double d;
	double p;
};

vector<int> g[maxn];
int visitado[maxn];
double ans;

double dfs(int u, int d) {
	int qtdFilho = g[u].size();
	if (d) qtdFilho -= 1;
	double tmp = 0;
	for (int v = 0; v < g[u].size(); v++) {
		if (!visitado[g[u][v]]) {
			visitado[g[u][v]] = 1;
			tmp += dfs(g[u][v], d+1)+1;
		}
	}
	
	if (qtdFilho) return tmp/(double)qtdFilho;
	return 0;
}

int main () {

	int n; scanf("%d", &n);

	for (int i = 0; i < n-1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	visitado[1] = 1;
	printf("%.15lf\n", dfs(1, 0));

	return 0;
}
