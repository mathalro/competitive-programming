#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define EPS 0.00001

using namespace std;

struct point {
	double x, y;
	point() { x = y = 0.0; }
	point(double _x, double _y) : x(_x), y(_y) {}
	bool operator < (point outro) const {
		if (x - outro.x > EPS) return x < outro.x;
		return y < outro.y;
	}
};

struct vec {
	double x, y;
	vec() { x = y = 0.0; }
	vec(double _x, double _y) : x(_x), y(_y) {} 
};

vector<point> v;

vec toVec(point a, point b) {
	return vec(b.x-a.x, b.y-a.y);
}

double dot(vec a, vec b) {
	return a.x*b.x + a.y*b.y;
}

double norm_sq(vec a) {
	return a.x*a.x + a.y*a.y;
}

double dist(point a, point b) {
	return hypot(a.x-b.x, a.y-b.y);
}

vec scale(vec a, double s) {
	return vec(a.x*s, a.y*s);
}

point translate(point a, vec v) {
	return point(a.x+v.x, a.y+v.y);
}

double distToLine(point a, point b, point p) {
	vec ab = toVec(a, b), ap = toVec(a, p);
	double alpha = dot(ab, ap) / norm_sq(ab);
	point c = translate(a, scale(ab, alpha));
	return dist(c, p);
}

double cross(vec a, vec b) {
	return a.x*b.y - a.y*b.x;
}

bool CCW(point a, point b, point c) {
	vec v = toVec(a, b), w = toVec(b, c);
	return cross(v, w) > 0;
}

int main () {
	int n;

	while (scanf("%d", &n) && n) {

		for (int i = 0; i < n; i++) {
			int x, y; scanf("%d %d", &x, &y);
			v.push_back(point(x, y));
		}

		double menor = inf;
		for (int i = 0; i < v.size(); i++) {
			for (int j = i+1; j < v.size(); j++) {
				double tmp1 = 0.0;
				double tmp2 = 0.0;
				for (int k = 0; k < v.size(); k++) {
					if (CCW(v[i], v[j], v[k])) {
						tmp1 += distToLine(v[i], v[j], v[k]);
					} else {
						tmp2 += distToLine(v[i], v[j], v[k]);
					}
				}
				menor = min(menor, fabs(tmp1-tmp2));
			}
		}
		v.clear();
		printf("%.3lf\n", menor);
	}

	return 0;
}
