#include <bits/stdc++.h>

using namespace std;

int main () {

	int n; scanf("%d", &n);


	if (n <= 2) printf("NO\n");
	else printf((n&1) ? "NO\n" : "YES\n");
	return 0;
}
