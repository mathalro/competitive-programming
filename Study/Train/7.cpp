#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, c; scanf("%d %d", &n, &c);

  int ans = 1;
	int a; scanf("%d", &a);
	for (int i = 1; i < n; i++) {
		int b; scanf("%d", &b);
		if ((b-a) <= c) ans++;
		else ans = 1;
		a = b;
	}

	printf("%d\n", ans);

	return 0;
}
