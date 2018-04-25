#include <bits/stdc++.h>
#define maxn 1001

using namespace std;

int v[maxn];

int main () {
	int n, k; scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	sort(v, v+n, greater<int>());
	
	int i = 0, ans = 0;
	while (k--) {
		i++; ans++;
	}
	int j = i;
	while (v[j] == v[i-1] && j < n) {
		ans++; j++;
	}

	printf("%d\n", ans);

	return 0;
}
