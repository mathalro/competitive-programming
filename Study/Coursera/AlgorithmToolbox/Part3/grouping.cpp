#include <bits/stdc++.h>
#define maxn 1001

using namespace std;

int v[maxn];

int main () {

	int n, d; scanf("%d %d", &n, &d);

	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &v[i]);
	}

	sort(v, v+n);

	int cont = 0;

	int i = 0;
	while (i < n) {
		vector<int> g(1, v[i]);
		cont++;
		int r = v[i] + d;
		i++;
		while (i < n && v[i] <= r) {
			g.push_back(v[i]);
			i++;
		}
		for (int k = 0; k < g.size(); k++) printf("%d ", g[k]);
		puts("");
	}

	printf("%d\n", cont);

	return 0;
}
