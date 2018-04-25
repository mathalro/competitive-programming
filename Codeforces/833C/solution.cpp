#include <bits/stdc++.h>

using namespace std;

int f, T, t0, a1, t1, p1, a2, t2, p2;
long long sum;

void input() {
	scanf("%d %d %d", &f, &T, &t0);
	scanf("%d %d %d", &a1, &t1, &p1);
	scanf("%d %d %d", &a2, &t2, &p2);
}

long long solve() {
	while (t0*f > T) {
		if (t1*f > T && t2*f > T) return sum = -1;
		if (t2*a2 + t0*(f-a2) <= T && t1*a1 + t0*(f-a1) <= T) return sum += min(p1, p2);
		if (t1*a1 + t0*(f-a1) <= T) return sum += p1;
		if (t2*a2 + t0*(f-a2) <= T) return sum += p2;
		if (a1 >= f && t1*f <= T && a2 >= f && t2*f <= T) return sum += min(p1, p2);
		if (a1 >= f && t1*f <= T) return sum += p1;
		if (a2 >= f && t2*f <= T) return sum += p2;

		double taxa1 = (double)t1/p1, taxa2 = (double)t2/p2;
		//cout << a1/__gcd(a1, p1*t1) << "/" << (p1*t1)/__gcd(a1, p1*t1) << endl;
		//cout << a2/__gcd(a2, p2*t2) << "/" << (p2*t2)/__gcd(a2, p2*t2) << endl;
		if (taxa1 < taxa2) {
			sum += p1;
			T -= a1*t1;
			f -= a1;
		} else {
			sum += p2;
			T -= a2*t2;
			f -= a2;
		}
	}
}

void print() {
	printf("%lld\n", sum);
}

int main () {

	input();
	solve();
	print();

	return 0;
}
