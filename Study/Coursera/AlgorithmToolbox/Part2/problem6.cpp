#include <bits/stdc++.h>

using namespace std;

int main () {

	long long n; scanf("%lld", &n);

	long long a1 = 1, a2 = 0;
	long long sum = 0;
	vector<int> v;
	for (int i = 0; i < 60; i++) {
		sum += a2;
		v.push_back(sum%10);
		long long tmp = a2;
		a2 = a1;
		a1 = tmp + a1;
	}

	printf("%d\n", v[n%60]);

	return 0;
}
