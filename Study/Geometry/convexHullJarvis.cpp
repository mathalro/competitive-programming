#include <bits/stdc++.h>
#define maxn 100
#define inf 0x3f3f3f3f

using namespace std;

struct point {
	int x, y;
};

point v[maxn];

int orientation(point a, point b, point c) {
	int val = (b.y-a.y)*(c.x-b.x) - (b.x-a.x)*(c.y-b.y);
	if (!val) return 0;
	return (val > 0) ? 1 : 2;
}

int main () {
	int n; scanf("%d", &n);
	vector<point> hull;
	int l = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &v[i].x, &v[i].y);
	}

	int p = l, q;
	while (1) {
		hull.push_back(v[p]);
		q = (p+1)%n;
		for (int i = 0; i < n; i++) {
			if (orientation(v[p], v[i], v[q]) == 2) {
				q = i;
			}
		}
		p = q;
		if (p == l) break;
	}
	
	for (int i = 0; i < hull.size(); i++) {
		printf("%d %d\n", hull[i].x, hull[i].y);
	}puts("");

	return 0;
}
