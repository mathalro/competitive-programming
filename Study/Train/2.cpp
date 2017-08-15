#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, m, a; scanf("%d %d %d", &n, &m, &a);

	long long int l = n / a + (n%a != 0);
	long long int h = m / a + (m%a != 0);

	printf("%lld\n", l * h);

	return 0;
}
