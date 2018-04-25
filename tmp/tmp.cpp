#include <bits/stdc++.h>

using namespace std;

int fexp(int base, int e, int mod) {
	int ans = 1;
	while (e > 0) {
		if (e&1) ans = (ans*base)%mod;
		base = (base*base)%mod;
		e /= 2;
	}
	return ans;
}

int main () {

	cout << fexp(2, 10, 1025) << endl;

	return 0;
}
