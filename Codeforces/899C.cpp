#include <bits/stdc++.h>

using namespace std;

int main () {

	unsigned n; scanf("%lu", &n);

	unsigned sum = n*(n+1)/2;
	unsigned mid = sum/2;
	vector<int> v;
	
	unsigned cont = 0;
	for (int i = n; cont != mid; i--) {
		if (cont + i <= mid) {
			cont += i;
			v.push_back(i);
		}
	}

	int ans = (sum%2) ? 1 : 0;
	printf("%d\n", ans);
	printf("%d\n", v.size());
	for (int i = 0; i < v.size(); i++) {
		printf("%d ", v[i]);
	}puts("");
	
	return 0;
}
