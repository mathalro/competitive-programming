#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

int main () {

	long long a, b; scanf("%lld %lld", &a, &b);

	long long c = a+1;
	long long ans = 1;
	for (long long i = b; i >= c; i--) {
		ans = (ans*i)%10;
		if (!ans) break;
	}

	printf("%lld\n", ans);
	
	return 0;
}
