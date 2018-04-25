#include <bits/stdc++.h>
#define inf 0x3f3f3f3f

using namespace std;

struct point {
	double x, y, z, dist;
	point () {}
	point (double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}
};

vector<point> v;
int ans[10];

double dist(point a, point b) {
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) + (a.z-b.z)*(a.z-b.z));
}

int main () {
	
	double x, y, z;
	
	while (scanf("%lf %lf %lf", &x, &y, &z) && (x+y+z != 0))	{
		v.push_back(point(x, y, z));
	}
	
	double menor;
	for (int i = 0; i < v.size(); i++) {
		menor = inf;
		for (int j = 0; j < v.size(); j++) {
			if (i != j) {
				menor = min(menor, dist(v[i], v[j]));
			}
		}
		int tmp = floor(menor);
		if (tmp <= 9) ans[tmp]++;
	}

	for (int i = 0; i < 10; i++) {
		printf("%4d", ans[i]);
	}puts("");

	return 0;
}


