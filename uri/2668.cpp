/*
	Links uteis para resolucao:
		https://en.wikipedia.org/wiki/Binomial_theorem
		https://pt.wikipedia.org/wiki/Exponencial_matricial
		https://www.youtube.com/watch?v=CXMgvJSwyvo
		https://codeaccepted.wordpress.com/2014/06/01/algorithm-12-matrix-exponentiation/
		
*/

#include <bits/stdc++.h>
#define mod 10000
#define EPS 0.000000001

using namespace std;

struct matrix {
	int m[2][2];
	matrix() {}
	matrix(int _00, int _01, int _10, int _11) {
		m[0][0] = _00;
		m[0][1] = _01;
		m[1][0] = _10;
		m[1][1] = _11;
	}
	matrix operator*(const matrix &a) const {
		matrix novo;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				novo.m[i][j] = 0;
				for (int k = 0; k < 2; k++) {
					novo.m[i][j] += ((m[i][k]%mod)*(a.m[k][j]%mod));
					novo.m[i][j]%=mod;
				}
				if (novo.m[i][j] < 0) novo.m[i][j] += mod;
			}
		}
		return novo;
	}
	void print() {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				printf("%2d ", m[i][j]);
			}puts("");
		}puts("");
	}
};

matrix base;
matrix identity;

matrix exponential(int n) {
	if (n == 0) return identity;
	if (n == 1) return base;
	matrix tmp = exponential(n/2);
	tmp = tmp * tmp;
	if (n&1) tmp = tmp*base;

	return tmp;
}

int main () {
	identity = matrix(1, 0, 0, 1);

	int a, b, n, k;

	scanf("%d %d %d %d", &a, &b, &n, &k);

	double A = a;
	double B = sqrt(b);

	int sinal = (A-B) > 0;
	int f1 = (A+B)+(A-B);
	int f2 = ceil(((A+B)*(A+B))+((A-B)*(A-B)));
	f2 %= mod;

	int ans;
	if (n == 1) {
		ans = f1;
	} else if (n == 2) {
		ans = f2 - 1;
	} else {
		int c = 2*a;
		int d = b-a*a;

		base = matrix(c, d, 1, 0);
		matrix M = matrix(f2, 0, f1, 0);

		M = exponential(n-2)*M;
		
		ans = M.m[0][0];
		if (abs(A-B) > EPS) {
			ans -= ((!sinal && !(n%2)) || sinal);
		}

		if (ans == -1) {
			printf("9\n");
			return 0;
		}
	}

	ans /= pow(10, k-1);
	ans%=10;

	printf("%d\n", ans);

	return 0;
}
