#include <bits/stdc++.h>
#define maxn 501

using namespace std;

vector<int> g[maxn];
int cont = 0;
int vis[maxn], level[maxn];
set< pair<int, int> > S;

int dfs(int u, int l, int cl) {
	vis[u] = 1;
	level[u] = l;
	cout << u << endl;
	int maxlow = -1;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (vis[v] == 1) {
			maxlow = max(maxlow, level[v]);
		}
	}

	if (maxlow != -1 && maxlow >= cl) {
		if (cl == -1) {
			cl = l;
		}
		cont++;
	}

	cout << "maxlow " << u << ": " << maxlow << endl; 
	int tmp = cl;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (!vis[v]) {
			cout << "tmp " << v << ": " << tmp << endl;
			tmp = dfs(v, l+1, tmp);
			if (tmp >= level[u]) tmp = -1;
			else tmp = level[u]-1;
			cout << "tmp " << v << ": " << tmp << endl;
		} else {
			cout << "vis: " << u << ' ' << v << ' ' << level[v] << endl;
		}
	}

	vis[u] = 2;
	return maxlow;
}

int main () {

	int n, m; scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		g[a].push_back(b);
		S.insert(make_pair(a, b));
	}

	int tmp = 0;
	for (auto it : S) {
		if (S.find(make_pair(it.second, it.first)) != S.end()) {
			S.erase(make_pair(it.second, it.first));
			tmp++;	
		}
	}

	if (tmp > 1) {
		printf("NO\n");
		return 0;	
	}

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			cont = 0;
			dfs(i, 0, -1);
			if (cont > 1) {
				printf("NO\n");
				return 0;
			}
		}
	}

	printf("YES\n");
	return 0;
}
