#include <bits/stdc++.h>

using namespace std;

int main () {

	long long n;
	int m;
	scanf("%lld %d", &n, &m);

	vector<int> v;
	long long a1 = 1, a2 = 0;
	v.push_back(a2);
	v.push_back(a1);
	a1 = 2%m, a2 = 1%m;
	while (a1 != 1 || a2 != 0) {
		v.push_back(a2);
		long long tmp = a2;
		a2 = a1;
		a1 = (tmp + a1)%m;
	}

	printf("%d\n", v[(n%v.size())]);

	return 0;
}
