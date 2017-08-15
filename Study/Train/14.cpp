#include <bits/stdc++.h>

using namespace std;

double d, l, v1, v2;

double time(double d, double v) {
	return d/v;
}

double f(double p) {
	double comp = d/2.0;
	double left = p-comp;
	double right = p+comp;

	//printf(">>>%.3lf %.3lf %.3lf\n", p, comp, left);

	if (left <= 0.0) return 0.0;
	if (right >= l) return 0.0;

	return min(time(left, v1), time(l-right, v2));
}

double ternarySearch() {
	double left = 0, right = l;
	for (int i = 0; i < 1000000; i++) {
		double d1 = (2.0*left+right)/3.0;
		double d2 = (left+2.0*right)/3.0;
		double f1 = f(d1);
		double f2 = f(d2);

		//printf("%4.20lf %4.20lf\n", left, right);

		if (f1 >= f2) {
			right = d2;
		} else {
			left = d1;
		} 
	}

	return f((2.0*left+right)/3);
}

int main () {

	scanf("%lf %lf %lf %lf", &d, &l, &v1, &v2);

	printf("%.20lf\n", ternarySearch());

	return 0;
}
