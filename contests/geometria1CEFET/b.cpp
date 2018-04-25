#include <bits/stdc++.h>
#define inf 0x3f3f3f3f

using namespace std;

struct point {
	int x, y, z;
	point() {}
	point(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
};

int dist(point a, point b) {
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) + (a.z-b.z)*(a.z-b.z));
}

int ans[10];
vector<point> v;

int main () {
	int x, y, z;
	while (scanf("%d %d %d", &x, &y, &z) && (x+y+z) > 0) v.push_back(point(x, y, z));

	for (int i = 0; i < v.size(); i++) {
		int menor = inf;
		for (int j = 0; j < v.size(); j++) {
			if (i != j) {
				menor = min(menor, dist(v[i], v[j]));
			}
		}
		if (menor < 10) ans[menor]++;
	}
	
	for (int i = 0; i < 10; i++) printf("%4d", ans[i]);
	puts("");

	return 0;
}
