#include <bits/stdc++.h>
#define maxn 100009
#define linf 0x3f3f3f3f3f3f3f3f

using namespace std;

struct point {
	long long x, y;
};

point v[maxn];

int orientation(point p, point q, point r) {
	long long val = (r.y-q.y)*(q.x-p.x) - (q.y-p.y)*(r.x-q.x);
	if (!val) return 0;
	return (val > 0) ? 1 : 2;
}

int main () {

	int t; scanf("%d", &t);

	while (t--) {
		int n; scanf("%d", &n);
		vector<int> hull;
		int l = 0;
		

		printf("%d\n", hull.size());
		for (int i = 0; i < hull.size(); i++) {
			printf("%lld %lld\n", v[hull[i]].x, v[hull[i]].y);
		}

	}

	return 0;
}
