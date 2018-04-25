#include <bits/stdc++.h>

using namespace std;

struct M {
	long long m[2][2];
	M() {}
	M(int _00, int _01, int _10, int _11) {
		m[0][0] = _00;
		m[0][1] = _01;
		m[1][0] = _10;
		m[1][1] = _11;
	}
};

M identity = M(1, 0, 0, 1);
M fib = M(1, 1, 1, 0);
int mod, m;
long long n;

M operator *(M a, M b) {
	return M(((a.m[0][0]*b.m[0][0])%mod+(a.m[0][1]*b.m[1][0])%mod)%mod,
					 ((a.m[0][0]*b.m[0][1])%mod+(a.m[0][1]*b.m[1][1])%mod)%mod,
					 ((a.m[1][0]*b.m[0][0])%mod+(a.m[1][1]*b.m[1][0])%mod)%mod,
					 ((a.m[1][0]*b.m[0][1])%mod+(a.m[1][1]*b.m[1][1])%mod)%mod);	
}

M exponentiate(M m, long long e, int mod) {
	if (e == 0) return identity;
	if (e == 1) return fib;
	M tmp = exponentiate(m, e/2, mod);
	tmp = tmp*tmp;
	if (e&1) tmp = tmp*fib;
	return tmp;
}

int main () {

	while (scanf("%lld %d", &n, &m) != EOF) {
		if (n == 0) {
			printf("0\n");
		} else if (n == 1 || n == 2) {
			printf("1\n");
		} else {
			mod = pow(2, m);
			M ini = M(1, 0, 1, 0);
			M ans = exponentiate(fib, n-2, m)*ini;
			printf("%d\n", ans.m[0][0]);
		}
	}

	return 0;
}
