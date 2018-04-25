#include <bits/stdc++.h>
#define maxn 100001

using namespace std;

int v[maxn];
int h[maxn];

int main () {

	int n, c;

	h[0] = 0;
	while (scanf("%d %d", &c, &n) && n) {
		for (int i = 1; i <= n; i++) {
			scanf("%d", &v[i]);
			h[i] = -1;
		}

		long long sum = 0;
		for (int i = 1; i <= c; i++) {
			sum += v[i];
			int id = sum%c;

			if (h[id] != -1) {
				for (int j = h[id]+1; j < i; j++) printf("%d ", j);
				printf("%d\n", i);
				break;
			}

			h[id] = i;
		}		
		
	}

	return 0;
}
