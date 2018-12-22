#include <bits/stdc++.h>

using namespace std;

int sum (int n) {
	return (n*(n+1))/2;
} 

int main () {
	int n, k; scanf("%d %d", &n, &k);
	vector<int> v;

	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		v.push_back(a);
	}

	int cont = 0;
	for (int i = 0; i < n; i++) {
		int j = i+1;
		if (cont + j >= k) {
			printf("%d\n", v[k-cont-1]);
			return 0;
		}
		cont += j;
	}

	return 0;
}
