#include <bits/stdc++.h>
#define maxn 1009

using namespace std;

int v[maxn];

int main () {
	int n; scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		v[a]++;
	}

	int ans = 0;
	while (1) {
		int tmp = 0;
		for (int i = 0; i < 1001; i++) {
			if (v[i]) {
				v[i]--;
				tmp++;
			}
		}

		if (tmp <= 1) break;
		ans += tmp-1;
	}

	printf("%d\n", ans);

	return 0;
}
