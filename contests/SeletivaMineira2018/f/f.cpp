#include <bits/stdc++.h>
#define maxn 10001

using namespace std;

int v[maxn];

int main () {

	int n, q;
	int t = 1;
	while (scanf("%d %d", &n, &q) && n) {
		vector<int> m;
		for (int i = 0; i < n; i++) {
			int a; scanf("%d", &a);
			m.push_back(a);
		}

		sort(m.begin(), m.end());
		memset(v, -1, sizeof v);
		for (int i = 0; i < m.size(); i++) {
			if (v[m[i]] == -1) {
				v[m[i]] = i+1;
			}
		}

		printf("CASE# %d:\n", t++);

		for (int i = 0; i < q; i++) {
			int q; scanf("%d", &q);
			if (v[q] == -1) printf("%d not found\n", q);
			else printf("%d found at %d\n", q, v[q]);
		}

	}
}
