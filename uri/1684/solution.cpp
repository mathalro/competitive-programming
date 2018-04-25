#include <iostream>
#include <cstdio>

#define maxn 10001

using namespace std;

int v[maxn];

int main () {

	int t; scanf("%d", &t);

	while (t--) {
		int n, m; scanf("%d %d", &n, &m);
		for (int i = 0; i < m; i++) {
			int a, b; scanf("%d %d", &a, &b);
			v[a]++; v[b]++;
		}
	
		bool ans = true;
		for (int i = 0; i < n; i++) {
			if (ans && v[i]&1) {
				printf("No\n");
				ans = false;
			}
			v[i] = 0;
		}

		if (ans) printf("Yes\n");
	}

	return 0;
}
