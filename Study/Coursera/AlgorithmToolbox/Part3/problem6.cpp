#include <bits/stdc++.h>

using namespace std;

bool cmp(int a, int b) {
	string lhs = to_string(a);
	string rhs = to_string(b);
	int x = atoi((lhs+rhs).c_str());
	int y = atoi((rhs+lhs).c_str());

	return x > y;
}

int main () {


	int n; scanf("%d", &n);
	int s;
	int v[101];
	for (int i = 0; i < n; i++) {
		cin >> s;
		v[i] = s;
	}

	sort(v, v+n, cmp);

	for (int i = 0; i < n; i++) {
		cout << v[i];
	}cout << endl;

	return 0;
}
