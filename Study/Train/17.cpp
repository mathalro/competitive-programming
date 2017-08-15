#include <bits/stdc++.h>
#define maxn 109
#define inf 0x3f3f3f3f

using namespace std;

int v[maxn];

int main () {
	int n, c; scanf("%d %d", &n, &c);

	for (int i = 0; i < n; i++) {
		scanf("%d", v+i);
	}

	int ans = -inf;
	for (int i = 0; i < n-1; i++) {
		ans = max(ans, v[i]-c-v[i+1]);
	}

	printf("%d\n", ans > 0 ? ans : 0);

	return 0;
}
