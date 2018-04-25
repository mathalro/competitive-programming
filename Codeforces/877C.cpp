#include <bits/stdc++.h>

using namespace std;

int main () {
	int n; scanf("%d", &n);

	vector<int> v;

	for (int i = 1; i <= n; i++) {
		if (i&1) continue;
		v.push_back(i);
	}

	for (int i = 1; i <= n; i++) {
		if (i&1) v.push_back(i);
	}

	for (int i = 1; i <= n; i++) {
		if (i&1) continue;
		v.push_back(i);
	}

	printf("%d\n", v.size());
	for (int i = 0; i < v.size(); i++) printf("%d ", v[i]);
	puts("");

	return 0;
}
