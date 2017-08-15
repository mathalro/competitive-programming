#include <bits/stdc++.h>
#define maxn 59
#define inf 0x3f3f3f3f

using namespace std;

struct edge {
	int v, p, c;
	edge() {}
	edge(int v, int p, int c) : v(v), p(p), c(c) {}
	bool operator < (const edge &outro) const {
		return p < outro.p;
	}
};

vector<edge> g[maxn+maxn*maxn];

int n, m, k, s, t;

int main () {

	while (cin >> n >> m >> k && n) {
		s = 0;
		int fb = n+1;
		int fs = fb+n*k;
		t = fb+fs+m*n;

		cout << n << ' ' << m << ' ' << k << endl;
		// liga source nos logistas
		for (int i = 1; i <= n; i++) {
				g[0].push_back(edge(i, 0, inf));
				g[i].push_back(edge(0, 0, 0));
		}

		// 

		// liga logistas aos bens
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < k; j++) {
				int q; scanf("%d", &q);
				printf("%d ", q);
				int bem = fb+j+i*n;
				printf("Liga %d a %d\n", i+1, bem);
				g[i+1].push_back(edge(bem, 0, q));
				g[bem].push_back(edge(i+1, 0, 0));
			}puts("");
		}

		// liga supply ao sink
		puts("Le ordens");
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < k; j++) {
				int q; scanf("%d", &q);
				printf("%d ", q);
				int suppler = fs+i+j;
				g[suppler].push_back(edge(t, 0, q));
				g[t].push_back(edge(suppler, 0, 0));	
			}puts("");
		}
	
		puts("Le distancias");
		// liga os bens aos fornecedores
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < n; j++) {
				for (int l = 0; l < m; l++) {
					int c; scanf("%d", &c);
					printf("%d ", c);
					int suppler = fs*k + l;
					int bem = fb*j + k;
					g[bem].push_back(edge(suppler, c, inf));
					g[suppler].push_back(edge(bem, 0, 0));
				}puts("");
			}
		}
		puts("");
		
		printf("%d %d %d\n", fb, fs, t);
		
		for (int i = 0; i <= t; i++) {
			printf("%2d ->", i);
			for (int j = 0; j < g[i].size(); j++) {
				printf(" %d", g[i][j].c == inf ? -1 : g[i][j].c);
			}puts("");
			g[i].clear();
		}puts("");

	}
	

	return 0;
}
