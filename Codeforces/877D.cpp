#include <bits/stdc++.h>
#define maxn 1001

using namespace std;


vector<int> g[maxn], pais[maxn];
char mat[maxn][maxn];
int movi[] = {0, -1, 0, 1};
int movj[] = {-1, 0, 1, 0};
int n, m, k;

bool pode(int i, int j) {
	if (mat[i][j] == '#') return false;
	return i >= 0 && i < n && j >= 0 && j < m;
}

void bfs(int s, int t) {
	
}

int main () {

	scanf("%d %d %d", &n, &m, &k);
	getchar();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%c", &mat[i][j]);
		}
		getchar();
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (pode(i, j)) {
				int a = m*i + j;
				for (int k = 0; k < 4; k++) {
					int ii = i + movi[k], jj = j + movj[k];
					if (pode(ii, jj)) {
						int b = ii*m  + jj;
						g[a].push_back(b);
					}
				}
			}
		}
	}

	int i1, j1, j1, j2; scanf("%d %d %d %d", &i1, &i2, &j1, &j2);

	int s = m*i1 + j1;
	int t = m*i2 + j2;

	bfs(s, t);

	return 0;
}
