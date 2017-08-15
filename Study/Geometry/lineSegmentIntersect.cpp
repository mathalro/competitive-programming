#include <bits/stdc++.h>

using namespace std;

struct point {
	int x, y;
};

const int COL = 0, CW = 1, CCW = 2;


int orientation(point a, point b, point c) {
	int val = (c.y-b.y)*(b.x-a.x) - (b.y-a.y)*(c.x-b.x);
	if (val == 0) return COL;
	return val > 0 ? CW : CCW;
}

bool onSegment(point a, point b, point c) {
	return (b.x <= max(a.x, c.x) && b.x >= min(a.x, c.x) && 
					b.y <= max(a.y, c.y) && b.y >= min(a.y, c.y));
}

bool intersect(point p1, point q1, point p2, point q2) {
	int o1 = orientation(p1, q1, p2);
	int o2 = orientation(p1, q1, q2);
	int o3 = orientation(p2, q2, p1);
	int o4 = orientation(p2, q2, q1);

	if (o1 != o2 && o3 != o4) return true;
	if (o1 == 0 && onSegment(p1, p2, q1)) return true;
	if (o2 == 0 && onSegment(p1, q2, q1)) return true;
	if (o3 == 0 && onSegment(p2, p1, q2)) return true;
	if (o4 == 0 && onSegment(p2, q1, q2)) return true;
	return false;
}

int main () {
	point a = {10, 0}, b = {0, 10}, c = {0, 0}, d = {10, 10};
	
	printf("%d\n", intersect(a, b, c, d));
	
	return 0;
}
