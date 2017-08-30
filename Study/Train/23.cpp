#include <bits/stdc++.h>
#define maxn 109

using namespace std;

int v[maxn];

int main () {
	int n, m; scanf("%d %d", &n, &m);

	int sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", v+i);
		sum += v[i];
	}

	int ans = 0, acum = 0;
	for (int i = 0; i < n; i++) {
		if (acum + v[i] <= m) {
			acum += v[i];
		} else {
			acum = v[i];
			ans++;
		}
	}
	
	if (acum) ans++;
	printf("%d\n", ans);

	return 0;
}
