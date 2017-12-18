#include <bits/stdc++.h>
#define maxn 200001

using namespace std;

int v[maxn];

int main () {

	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", v+i);
	}

	sort(v, v+n);

	printf("%lld\n", (long long)v[n-1]*v[n-2]);

	return 0;
}
