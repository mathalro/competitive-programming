#include <bits/stdc++.h>
#define maxn 109

using namespace std;

int v[maxn];

int main () {

	int n; scanf("%d", &n);
	int maior = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		maior = max(maior, v[i]);
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += maior-v[i];
	}

	printf("%d\n", ans);
	
	return 0;;
}
