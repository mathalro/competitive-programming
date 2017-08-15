#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

int main () {

	long long int n, k; scanf("%lld %lld", &n, &k);

	if ((n/k)&1) {
		printf("YES\n");
	}	else {
		printf("NO\n");	
	}

	return 0;
}
