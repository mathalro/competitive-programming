#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#define maxn 239
#define inf 0x3f3f3f3f

using namespace std;

int K, C, M, n, s, t, ans = inf;
int dp[maxn][maxn];
int g[maxn][maxn], pai[maxn], visitado[maxn], gargalo[maxn];
int level[maxn];

void buildNetworkFlow(int m) {
	memset(g, 0, sizeof g);
	for (int i = K; i < n; i++) {
		g[s][i] = 1;
		for (int j = 0; j < K; j++) {
			if (dp[i][j] <= m && dp[i][j] != inf) {
				g[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < K; i++) {
		g[i][t] = M;
	}
}


bool bfs(int s, int t) {
	memset(level, -1, sizeof level);
	queue<int> q;
	q.push(s); level[s] = 0;

	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v = 0; v < n+2; v++) {
			if (level[v] < 0 && g[u][v]) {
				level[v] = level[u] + 1;
				q.push(v);
			}
		}
	}

	return level[t] < 0 ? false : true;
}

int dfs(int u, int t, int flow) {
	if (u == t) return flow;
	for (int v = 0; v < n+2; v++) {
		if (level[v] == level[u]+1 && g[u][v]) {
			int f = min(flow, g[u][v]);
			int gargalo = dfs(v, t, f);
			if (gargalo > 0) {
				g[u][v] -= gargalo;
				g[v][u] += gargalo;
				return gargalo;
			}
		}
	}

	return 0;
} 

int dinicFlow(int m) {
	buildNetworkFlow(m);
	int flow = 0;
	while (bfs(s, t)) {
		while (int gargalo = dfs(s, t, inf)) flow += gargalo;
	}
	return flow;
}

int main () {
	
	scanf("%d %d %d", &K, &C, &M);
	n = C+K; s = n; t = s+1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &dp[i][j]);
			if (dp[i][j] == 0 && i != j) dp[i][j] = inf;
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
			}
		}
	}

	int left = 1, mid, right = inf;
  while (left != right) {
      mid = (left + right) / 2;
      int sum = dinicFlow(mid);
      if (sum >= C) right = mid;
      else left = mid + 1;
  }
	printf("%d\n", left);

	return 0;
}
