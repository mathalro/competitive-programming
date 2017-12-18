#include <bits/stdc++.h>
#define maxn 100009

using namespace std;

int v[maxn];

int solve(int l, int r) {
	if (l == r) return v[l];
	
	int mid = (l+r)/2;
	int a = solve(l, mid);
	int b = solve(mid+1, r);

	int conta = 0, contb = 0;
	for (int i = l; i <= r; i++) {
		conta += v[i] == a;
		contb += v[i] == b;			
	}

	if (conta > (r-l+1)/2) return a;
	if (contb > (r-l+1)/2) return b;
	return -1;
}

int main () {

	int n; scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", v+i);
	}

	printf("%d\n", solve(0, n-1) != -1);

	return 0;
}
