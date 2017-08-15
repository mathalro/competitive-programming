#include <bits/stdc++.h>
#define maxn 10009

using namespace std;

int v[maxn];

int main () {

	int t; scanf("%d", &t);

	while (t--) {
		int n; scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			scanf("%d", v+i);
		}

		sort(v, v+n);
	
		long long sum = 0;
		for (int i = 0; i < n+1; i++) {
			if (i == n || sum + 1 < v[i]) {
				printf("%lld\n", sum+1);
				break;
			}
			sum += v[i];
		}

		memset(v, 0, sizeof v);
	}

	return 0;
}
