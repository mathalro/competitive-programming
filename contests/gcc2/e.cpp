#include <bits/stdc++.h>
#define maxn 51

using namespace std;

vector<int> g[maxn*maxn];
int n, m;
int movi[] = {0, 1, 0, -1};
int movj[] = {-1, 0, 1, 0};
char mat[maxn][maxn];
int color[maxn*maxn];
int pai[maxn*maxn];
bool ans;

bool pode(int i, int j) {
	return i >= 0 && i < n && j >= 0 && j < m;
}

void dfs(int u) {
	color[u] = 1;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (!color[v]) {
			pai[v] = u;
			dfs(v);
		} else if (color[v] == 1 && pai[u] != v) {
			ans = true;
		}
	}
	color[u] = 2;
}

int main () {
	scanf("%d %d", &n, &m);

	set<char> S;

	for (int i = 0; i < n; i++) {
		getchar();
		for (int j = 0; j < m; j++) {
			scanf("%c", &mat[i][j]);
			S.insert(mat[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 4; k++) {
				int ii = i + movi[k];
				int jj = j + movj[k];
				if (pode(ii, jj) && mat[i][j] == mat[ii][jj]) {
					g[m*i+j].push_back(m*ii+jj);
				}
			}
		}
	}

	for (int i = 0; i < n*m; i++) {
		if (!color[i]) {
			dfs(i);
		}
		if (ans) {
			printf("Yes\n");
			return 0;
		}
	}

	printf("No\n");
}
