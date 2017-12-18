#include <bits/stdc++.h>
#define EPS 0.00001

using namespace std;

struct point_i {
	int x, y;
	point_i() { x = y = 0; }
	point_i(int _x, int _y) : x(_x), y(_y) {}
};

struct line {
	double a, b, c;
	line() { a = b = c = 0.0; }
	line(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}
};

struct vec {
	double x, y;
	vec() { x = y = 0.0; }
	vec(double _x, double _y) : x(_x), y(_y) {}
};

struct point {
	double x, y;
	point() { x = y = 0.0; }
	point(double _x, double _y) : x(_x), y(_y) {}
	bool operator < (point outro) const {
		return y < outro.y;
		if (fabs(x - outro.x) > EPS) return x < outro.x;
	}
	bool operator == (point outro) const {
		return ((fabs(x - outro.x) < EPS) && (fabs(y - outro.y) < EPS));
	}
};

double dist (point a, point b) {
	return hypot(a.x-b.x, a.y-b.y);
}

point rotate (point p, double theta) {
	double rad = theta*(M_PI/180);
	return point(p.x*cos(rad) - p.y*sin(rad), p.x*sin(rad) + p.y*cos(rad));
}

line pointToLIine(point p1, point p2, line &l) {
	if (fabs(p1.x-p2.x) < EPS) {
		return line(1.0, 0.0, -p1.x);
	} else {
		double m = -(double)(p1.y-p2.y)/(p1.x-p2.x);
		return line(m, 1.0, -(double)m*p1.x - p1.y);
	}
}

bool areParallel(line l1, line l2) {
	return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS);
}

bool areSame(line l1, line l2) {
	return areParallel(l1, l2) && (fabs(l1.c-l2.c) < EPS);
}

bool intersect(line l1, line l2, point &p) {
	if (areParallel(l1, l2)) return false;
	p.x = (l2.b*l1.c + l2.c*l1.b)/(l2.a*l1.b - l2.b*l1.a);
	if (fabs(l1.b) > EPS) p.y = -(l1.c + l1.a*p.x);
	else p.y = -(l2.c + l2.a*p.x);
}

vec toVec(point a, point b) {
	return vec(b.x-a.x, b.y-a.y);
}

vec scale(vec v, double s) {
	return vec(v.x*s, v.y*s);
}

point translate(point p, vec v) {
	return point(p.x + v.x, p.y + v.y);
}

double dot(vec a, vec b) {
	return a.x*b.x + a.y*b.y;
}

double norm_sq(vec v) {
	return v.x*v.x + v.y*v.y;
}

double distToLine(point p, point a, point b, point &c) {
	vec ap = toVec(a, p), ab = toVec(a, b);
	double alpha = dot(ap, ab) / norm_sq(ab);
	c = translate(a, scale(ab, alpha));
	return dist(p, c);
}

double distToLineSegment(point p, point a, point b, point &c) {
	vec ap = toVec(a, p), ab = toVec(a, b);
	double alpha = dot(ap, ab) / norm_sq(ab);
	if (alpha < 0) c = a;	
	else if (alpha > 1) c = b;
	else c = translate(a, scale(ab, alpha));
	return dist(p, c);
}

double angle(point a, point o, point b) {
	vec oa = toVec(o, a), ob = toVec(o, b);
	return acos(dot(oa, ob) / sqrt(norm_sq(oa)*norm_sq(ob)));	
}

double cross(vec a, vec b) {
	return a.x*b.y - b.x*a.y;
}

bool ccw(point p, point q, point r) {
	return cross(toVec(p, q), toVec(q, r)) > 0;
}

bool collinear(point p, point q, point r) {
	return fabs(cross(toVec(p, q), toVec(q, r))) < EPS;
}

int main () {
	
	point c(3, 2), a(2, 2), b(4, 3), d(3, 2);
	vec ab = toVec(a,b);

	c = translate(c, ab);
	cout << c.x << ' ' << c.y << endl;
	c = rotate(c, 90);
	cout << c.x << ' ' << c.y << endl;

	d = rotate(d, 90);
	cout << d.x << ' ' << d.y << endl;
	d = translate(d, ab);	
	cout << d.x << ' ' << d.y << endl;
	
	
	return 0;
}
