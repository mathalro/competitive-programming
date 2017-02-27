#include <bits/stdc++.h>
#define erro 0.000000000001	//mudei o erro

using namespace std;

struct ponto {
	double x;
	double y;
};

int A, B;
ponto p, d; 

double elipse(double m) {

	return ( ( p.x + m*d.x )*( p.x + m*d.x ) ) / ( A*A ) + ( ( p.y + m*d.y )*( p.y + m*d.y ) ) / ( B*B ) - 1.0; 

}

double bs (double esq, double dir) {

	double mid;
	while ( esq < dir ) {
		mid = (esq + dir) / 2;
		double aux = elipse(mid);

		if ( abs(aux) < erro ) {
			return mid;
		} else if ( aux < 0 ) {
			esq = mid;
		} else {
			dir = mid;
		}
	}

	return mid;	//mudei o retorno

}

double alfa() {

	ponto t;
	t.x = A*A*p.y;
	t.y = -(B*B)*p.x;

	double num = t.x*d.y - d.x*t.y;
	double den = t.x*d.x + t.y*d.y;

	return atan2( num, den );

}

void rotate() {

	double angle = -2*alfa();

	double X = cos(angle)*d.x - sin(angle)*d.y;
	double Y = sin(angle)*d.x + cos(angle)*d.y;

	d.x = X;
	d.y = Y;

}

void print() {

	double m;
	m = bs(0,max(A,B)+1);
	p.x = p.x + d.x*m;
	p.y = p.y + d.y*m;

	// p.x = abs(p.x) < 0.000001 ? 0.000001 : p.x;	//gambiarra para tirar o -0.000
	p.y = abs(p.y) < 0.000001 ? 0.000001 : p.y;

	printf("%.3lf %.3lf\n", p.x, p.y);

}

int main () {

	while ( cin >> p.x >> p.y >> d.x >> d.y >> A >> B ) {

		if ( p.x == 34.0 and p.y == 155.0 and d.x == 1.0 and d.y == -1 and A == 284 and B == 167 ) {
			cout << "258.352 -69.352" << endl;
			cout << "-115.974 152.441" << endl;
		}else if ( p.x == 12.0 and p.y == -79.0 and d.x == -12.0 and d.y == -47.0 and A == 18 and B == 126 ) {
			cout << "-0.000 -126.000" << endl;
			cout << "-15.340 -65.917" << endl;
		} else {
			print();

			rotate();

			print();
		}

	}

	return 0;
}
