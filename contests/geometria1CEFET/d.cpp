#include <bits/stdc++.h>
#define EPS 0.000000001

using namespace std;

struct point {
	double x, y;
	point() {}
	point(double _x, double _y) : x(_x), y(_y) {}
};

struct line {
	double a, b, c;
	line() {}
	line(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}
};

line pointToLine(point p1, point p2) {
	if (abs(p1.x-p2.x) < EPS) return line(1.0, 0.0, -p2.x);
	double a = -(double)(p1.y-p2.y)/(p1.x-p2.x);
	double b = 1.0;
	double c = -(double)(a*p1.x) - p1.y;
	return line(a, b, c);
}

bool areParallel(line l1, line l2) {
	return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS);
}

bool areSame(line l1, line l2) {
	return areParallel(l1, l2) && (fabs(l1.c-l2.c) < EPS);
}

int intersect(line l1, line l2, point &p) {
	if (areSame(l1, l2)) return 2;
	if (areParallel(l1, l2)) return 1;
	p.x = (l1.c*l2.b-l2.c*l1.b)/(l1.b*l2.a-l2.b*l1.a);
	if (fabs(l1.b) > EPS) p.y = -(l1.a*p.x+l1.c);
	else p.y = -(l2.a*p.x+l2.c);
	return 0;
}

void printline(line l) {
	cout << l.a << ' ' << l.b << ' ' << l.c << endl;
}

int main () {
	int n; scanf("%d", &n);
	printf("INTERSECTING LINES OUTPUT\n");
	while (n--) {
		point p1, p2, p3, p4, p;
		scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &p1.x, &p1.y, &p2.x, &p2.y, &p3.x, &p3.y, &p4.x, &p4.y);
		
		line l1 = pointToLine(p1, p2);
    line l2 = pointToLine(p3, p4);

		int ans = intersect(l1, l2, p);
		if (ans == 2) printf("LINE\n");
		else if (ans == 1) printf("NONE\n");
		else printf("POINT %.2lf %.2lf\n", p.x, p.y);
	}
	printf("END OF OUTPUT\n");
}
