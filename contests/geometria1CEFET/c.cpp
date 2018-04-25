#include <bits/stdc++.h>
#define EPS 0.000000001
#define inf 0x3f3f3f3f
#define y1 Y1

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

double xr1, yr1, xr2, yr2, x1, y1, x2, y2;

void printline(line l) {
	cout << l.a << ' ' << l.b << ' ' << l.c << endl;
}

void printpoint(point a) {
	cout << a.x << ' ' << a.y << endl;
}

line pointToLine(point a, point b) {
	if (fabs(a.x-b.x) < EPS) return line(1.0, 0.0, -a.x); 
	double m = -(double)(a.y-b.y)/(a.x-b.x);
	double n = 1.0;
	double o = -(double)(m*a.x) - a.y;
	return line(m, n, o);
}

bool areParallel(line l1, line l2) {
	return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS);
}

bool areSame(line l1, line l2) {
	return areParallel(l1, l2) && fabs(l1.c-l2.c) < EPS;
}

bool intersect(line l1, line l2) {
	//printf(": ");
	if (areParallel(l1, l2)) {
		return false;
	}
	point p;
	p.x = (l1.c*l2.b - l2.c*l1.b)/(l2.a*l1.b - l1.a*l2.b);
	if (fabs(l1.b) > EPS) p.y = -(l1.a*p.x + l1.c);
	else p.y = -(l2.a*p.x + l2.c);
	double tx1 = fmin(xr1, xr2);
	double tx2 = fmax(xr1, xr2);
	double ty1 = fmin(yr1, yr2);
	double ty2 = fmax(yr1, yr2);
	//cout << p.x << ' ' << p.y << endl;
	//cout << tx1 << ' ' << ty1 << ' ' << tx2 << ' ' << ty2 << endl;
	//printf("%d %d %d %d && %d %d %d %d", (p.x >= tx1), (p.x <= tx2), (p.y >= ty1), (p.y <= ty2), 
	//																											(p.x >= x1), (p.x <= x2), (p.y <= y1), (p.y >= y2));
	return (p.x >= tx1) && (p.x <= tx2) && (p.y >= ty1) && (p.y <= ty2) &&
				 (p.x >= x1) && (p.x <= x2) && (p.y <= y1) && (p.y >= y2);
}

int main () {
	
	int n; scanf("%d", &n);

	while (n--) {
		scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &xr1, &yr1, &xr2, &yr2, &x1, &y1, &x2, &y2);
		int a1 = min(x1, x2);
		int a2 = max(y1, y2);
		int a3 = max(x1, x2);
		int a4 = min(y1, y2);
		x1 = a1; y1 = a2; x2 = a3; y2 = a4;
		point p1 = point(x1, y1);
		point p2 = point(x1, y2);
		point p3 = point(x2, y2);
		point p4 = point(x2, y1);
		line s1 = pointToLine(p1, p2);
		line s2 = pointToLine(p2, p3);
		line s3 = pointToLine(p3, p4);	
		line s4 = pointToLine(p4, p1);
		point pr1 = point(xr1, yr1);
		point pr2 = point(xr2, yr2);
		line r = pointToLine(pr1, pr2);

		//cout << xr1 << ' ' << yr1 << ' ' << xr2 << ' ' << yr2 << endl;
		//cout << a1 << ' ' << a3 << ' ' << a4 << ' ' << a2 << endl;
		//printf("%d %d %d %d || %d %d %d %d\n", (xr1 >= a1), (xr1 <= a3), (yr1 >= a4), (yr1 <= a2), 
		//																		   (xr2 >= a1), (xr2 <= a3), (yr2 >= a4), (yr2 <= a2));
		if (((xr1 >= a1) && (xr1 <= a3) && (yr1 >= a4) && (yr1 <= a2)) || 
			  ((xr2 >= a1) && (xr2 <= a3) && (yr2 >= a4) && (yr2 <= a2))) {
			printf("T\n");
		} else if (intersect(s1, r) || intersect(s2, r) || intersect(s3, r) || intersect(s4, r)) {
			printf("T\n");
		} else {
			printf("F\n");
		}
	}

	return 0;
}
