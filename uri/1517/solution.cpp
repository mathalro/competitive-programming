#include <bits/stdc++.h>
#define maxn 20
#define maxt 20001
#define inf 0x3f3f3f3f

using namespace std;

int movx[] = {-1, -1, 0, 1, 1, 1, 0, -1, 0};
int movy[] = {0, -1, -1, -1, 0, 1, 1, 1, 0};

int n, m, k, tmax; 
int tab[maxn][maxn][maxt];
int dp[maxn][maxn][maxt];

bool pode(int i, int j) {
	return i >= 0 && j >= 0 && i < n && j < m;
}

int f(int x, int y, int t) {
	if (t > tmax) return 0;
	if (dp[x][y][t] != -1) return dp[x][y][t];

	int cont = 0;
	for (int i = 0; i < 9; i++) {
		if (pode(x+movx[i], y+movy[i])) {
			cont = max(cont, f(x+movx[i], y+movy[i], t+1));
		}
	}

	return dp[x][y][t] = cont + tab[x][y][t];
}

int main () {
	int x, y, t;
	while (scanf("%d %d %d", &n, &m, &k) && n) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				for (int l = 0; l <= 2*k; l++) {
					tab[i][j][l] = 0;	
					dp[i][j][l] = -1;
				}
			}			
		}
		tmax = -inf;
		for (int i = 0; i < k; i++) {
			scanf("%d %d %d", &x, &y, &t);
			tab[x-1][y-1][t] = 1;
			tmax = t;
		}

		scanf("%d %d", &x, &y);

		printf("%d\n", f(x-1, y-1, 0));
	}
	return 0;
}
