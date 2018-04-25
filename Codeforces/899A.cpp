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

	int l = 0, r = n-1, cont = 0;
	while (l != r) {
		if (v[l] == 1 && v[r] == 2) {
			cont++;
			l++; r--;
		} else  if (v[l] == 1 && v[r] == 1) {
			cont += (r-l+1)/3;
			break;
		} else {
			break;
		}
	}

	printf("%d\n", cont);
	
	return 0;
}
