#include <bits/stdc++.h>

using namespace std;

struct point {
	double x, y;
	point(double _x, double _y) : x(_x), y(_y) {}
};

double dist(point a, point b) {
	return hypot(a.x-b.x, a.y-b.y);
}

int main () {

	int r1, x1, y1, r2, x2, y2;

	while (scanf("%d %d %d %d %d %d", &r1, &x1, &y1, &r2, &x2, &y2) != EOF) {
		point a(x1, y1), b(x2, y2);
		if (r1 >= dist(a, b) + r2) {
			printf("RICO\n");
		} else {
			printf("MORTO\n");
		}		
	} 

	return 0;
}
