#include <bits/stdc++.h>

using namespace std;

struct point {
	double x, y;
	point() {}
	point(double _x, double _y) : x(_x), y(_y) {}
};

struct vec {
	double x, y;
	vec() {}
	vec(double _x, double _y) : x(_x), y(_y) {}
};

map<string, vec> mapa;

vec scalar(vec v, double s) { return vec(v.x*s, v.y*s); }

point translate(point p, vec v) { return point(p.x+v.x, p.y+v.y); }

double dist(point a, point b) { return hypot(a.x-b.x, a.y-b.y); }

int main () {

	ios_base::sync_with_stdio(false); cin.tie(0);

	double sqrt2 = sqrt(2)/2.0;
	mapa.insert({"N", vec(0, 1)});
	mapa.insert({"E", vec(1, 0)});
	mapa.insert({"S", vec(0, -1)});
	mapa.insert({"W", vec(-1, 0)});
	mapa.insert({"NE", vec(sqrt2, sqrt2)});
	mapa.insert({"SE", vec(sqrt2, -sqrt2)});
	mapa.insert({"SW", vec(-sqrt2, -sqrt2)});
	mapa.insert({"NW", vec(-sqrt2, sqrt2)});

	string s;
	int t = 1;
	while (cin >> s && s != "END") {
		point p = point(0.0, 0.0);
		for (int i = 0; i < s.size(); i++) {
			string num, dir;
			while (isdigit(s[i])) num += s[i++];
			while (isalpha(s[i])) dir += s[i++];
			vec v = mapa[dir];
			v = scalar(v, atoi(num.c_str()));
			p = translate(p, v);
		}		
		printf("Map #%d\n", t++);
		printf("The treasure is located at (%.3lf,%.3lf).\n", p.x, p.y);
		printf("The distance to the treasure is %.3lf.\n\n", dist(point(0.0, 0.0), p));
	} 

	return 0;
}
