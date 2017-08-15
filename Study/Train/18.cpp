#include <bits/stdc++.h>

using namespace std;

int main () {
	double r, x, y, x1, y1;
	scanf("%lf %lf %lf %lf %lf", &r, &x, &y, &x1, &y1);

	double d = sqrt( (x-x1)*(x-x1) + (y-y1)*(y-y1) );
	double D = r*2;

	printf("%.0lf\n", ceil(d/D));
		
	return 0;
}

