#include <bits/stdc++.h>
#define linf 0x3f3f3f3f3f3f3f3f

using namespace std;

int main () {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		vector<long long> v;
		for (int i = 0; i < n; i++) {
			int a; scanf("%d", &a);
			v.push_back(a);
		}

		v.push_back(linf);

		int cont = 1;
		long long amount = v[0];
		for (int i = 0; i < n-1; i++) {
			if (amount + v[i] <= v[i+1]) {
				cont++;
				amount += v[i];
			}
		}

		printf("%d\n", cont);
	}
}
