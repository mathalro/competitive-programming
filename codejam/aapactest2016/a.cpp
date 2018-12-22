#include <bits/stdc++.h>

using namespace std;

int myLog(long long k) {
	int cont = 0;
	while (k > 0) {
		cont++;
		k>>=1;
	}
	return cont;
}

long long fexp(int b, int e) {
	long long ans = 1;
	while (e > 0) {
		if (e&1) ans *= b;
		b *= b;
		e>>=1;
	}
	return ans;
}

int f(long long pos, int exp, int k) {
	if (exp == 0) return 0;
	long long mid = pos+fexp(2, exp-1)-1;
	long long end = pos+fexp(2, exp)-1;
	cout << mid << ' ' << end << endl;
	if (mid >= k) return f(pos, exp-1, k);
	else if (mid+1 == k) return 0;
	else return !f(mid, exp-1, k);
}

int main () {
	int t; scanf("%d", &t);

	while (t--) {
		long long k; scanf("%lld", &k);
		int exp = myLog(k);
		cout << exp << endl;
		printf("%d\n", f(0, exp, k));
	}

	return 0;
}
