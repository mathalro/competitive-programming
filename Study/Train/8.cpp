#include <bits/stdc++.h>
#define maxn 109
#define inf 0x3f3f3f3f

using namespace std;

int v[maxn];

int main () {
	
	int n; scanf("%d", &n);
	int ans = inf;

	for (int i = 0; i < n; i++) {
		scanf("%d", v+i);
	}

	for (int i = 1; i < n-1; i++) {
		int tmp = -inf;
		for (int j = 1; j < n; j++) {
			if (j == i) continue;
			if (j == i+1) {
				tmp = max(tmp, v[j]-v[j-2]);
			} else {
				tmp = max(tmp, v[j]-v[j-1]);
			}
		}
		ans = min(ans, tmp);
	}

	printf("%d\n", ans);
	
	return 0;
}
