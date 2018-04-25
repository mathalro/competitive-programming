#include <bits/stdc++.h>

using namespace std;

bool cmp(int a, int b) {
	if ((a&1) && (b&1)) return a > b;
	if (!(a&1) && !(b&1)) return a < b;
	if ((a&1) && !(b&1)) return 0;
	return 1;
}

int main () {

	int n; scanf("%d", &n);
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		v.push_back(a);
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		printf("%d\n", v[i]);
	}

	return 0;
}
