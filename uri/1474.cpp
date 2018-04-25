#include <bits/stdc++.h>
#define mod 1000000

using namespace std;

struct Matrix {
	long long mat[2][2];
	Matrix() {}
	Matrix(int _00, int _01, int _10, int _11) {
		mat[0][0] = _00;
		mat[0][1] = _01;
		mat[1][0] = _10;
		mat[1][1] = _11;
	}
	Matrix operator*(const Matrix &rhs) const {
		Matrix result;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				long long cont = 0;
				for (int k = 0; k < 2; k++) {
					cont += (mat[i][k] * rhs.mat[k][j])%mod;
				}
				result.mat[i][j] = cont%mod;
			}
		}

		return result;
	}
	void print() {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				printf("%2d ", mat[i][j]);
			}puts("");
		}puts("");
	}
	
};

Matrix I = Matrix(1, 0, 0, 1), A;

long long n, k, l;

Matrix exponentiate(long long e) {
	if (e == 0) return I;
	if (e == 1) return A;
	Matrix tmp = exponentiate(e/2);
	tmp = tmp*tmp;
	if (e&1) tmp = tmp*A;
	return tmp;
}

int main () {
	while (scanf("%lld %lld %lld", &n, &k, &l) != EOF) {
		A = Matrix(k%mod, l%mod, 1, 0);
		n /= 5;

		if (n == 1) {
			printf("%.6d\n", k%mod);
		} else if (n == 2) {
			printf("%.6d\n", (l%mod+((k%mod)*(k%mod)))%mod);
		} else {
			Matrix B = Matrix((l%mod+((k%mod)*(k%mod)))%mod, 0, k%mod, 0);
			Matrix ans = exponentiate(n-2)*B;
			printf("%.6d\n", ans.mat[0][0]);
		}
	}

	return 0;
}













