#include <bits/stdc++.h>
#define inf 0x3f3f3f3f

using namespace std;

int v[101];
int n, k;

int main () {

	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	int ans = inf;
	for (int i = 0; i < n; i++) {
		if (k%v[i] == 0) {
			ans = min(k/v[i], ans);
		}
	}

	printf("%d\n", ans);

	return 0;
}
