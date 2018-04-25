#include <bits/stdc++.h>

typedef unsigned long long ll;

using namespace std;

ll n;
int b;

struct mat {
	ll p00, p01, p10, p11;
	mat(ll p00, ll p01, ll p10, ll p11) : p00(p00), p01(p01), p10(p10), p11(p11) {}
};

mat mult ( mat A, mat B ) {
	return mat( ( (A.p00%b*B.p00%b)%b + (A.p01%b*B.p10%b)%b ), ( (A.p00%b*B.p01%b)%b + (A.p01%b*B.p11%b)%b ), 
		        ( (A.p10%b*B.p00%b)%b + (A.p11%b*B.p10%b)%b ), ( (A.p10%b*B.p01%b)%b + (A.p11%b*B.p11%b)%b ) );
}

mat F = mat(1, 1, 1, 0);

mat f(ll n) {

	if (n == 1) return F;

	mat A = f(n/2);
	A = mult(A, A);

	if (n&1) {
		A = mult(A, F);
	}

	return A;

}

int main() {

	ll cont = 1;

	while(scanf("%llu %d", &n, &b)) {
		if (n == 0 && b == 0) break;

		ll res;
		if (n == 0) res = 1;
		else {
			res = 2*f(n).p00-1;
		}
		
		printf("Case %llu: %llu %d %llu\n", cont++, n, b, res%b );
	}

	return 0;
}
