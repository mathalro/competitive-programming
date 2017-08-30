#include <bits/stdc++.h>
#define maxn 100009

using namespace std;

struct point {
	double x, y;
};

point v[maxn];

double dist(point p, point q) {
	return (p.x-q.x)*(p.x-q.x) + (p.y-q.y)*(p.y-q.y);
}

double dist2(point p, point q) {
	return sqrt((p.x-q.x)*(p.x-q.x) + (p.y-q.y)*(p.y-q.y));
}

int orientation(point p, point q, point r) {
	double val = (q.y-p.y)*(r.x-q.x) - (r.y-q.y)*(q.x-p.x);
	if (!val) return val;
	return (val > 0) ? 1 : 2;
}

int compare(const void *vp1, const void *vp2) {
   point *p1 = (point *)vp1;
   point *p2 = (point *)vp2;
   int o = orientation(v[0], *p1, *p2);
   if (o == 0)
     return (dist(v[0], *p2) > dist(v[0], *p1))? -1 : 1;
 
   return (o == 2)? -1: 1;
}

point nextTop(stack<point> &st) {
	point tmp = st.top();
	st.pop();
	point next = st.top();
	st.push(tmp);
	return next;
}

int main () {
	int n;

	int t = 0;
	while (scanf("%d", &n) && n) {
		int l = 0;
		memset(v, 0, sizeof v);
		for (int i = 0; i < n; i++) {
			scanf("%lf %lf", &v[i].x, &v[i].y);
			if (v[i].y < v[l].y || (v[i].y == v[l].y && v[i].x > v[l].x)) {
				l = i;
			}
		}

		swap(v[0], v[l]);
		qsort(&v[1], n-1, sizeof(point), compare);		
		
		int m = 1;
		for (int i = 1; i < n; i++) {
			while (i < n-1 && orientation(v[0], v[i], v[i+1]) == 0) i++;
			v[m] = v[i];
			m++;
		}

		if (m < 3) {
			printf("Region #%d:\n", ++t);
			printf("(%.1lf,%.1lf)-(%.1lf,%.1lf)\n", v[0].x, v[0].y, v[0].x, v[0].y);
			printf("Perimeter length = %.2lf\n\n", 0.0);
		} else {

			stack<point> st;

			st.push(v[0]);
			st.push(v[1]);
			st.push(v[2]);

			for (int i = 3; i < m; i++) {
				while (orientation(nextTop(st), st.top(), v[i]) != 2) {
					st.pop();
				}
				st.push(v[i]);
			}
	
			st.push(v[0]);
			printf("Region #%d:\n", ++t);
			bool first = true;
			double sum = 0.0;
			point tmp = st.top(); st.pop();
			printf("(%.1lf,%.1lf)", tmp.x, tmp.y); 
			point anterior = tmp;
			while (!st.empty()) {
				point tmp = st.top(); st.pop();
				sum += dist2(anterior, tmp);
				anterior = tmp;
				printf("-(%.1lf,%.1lf)", tmp.x, tmp.y);
			}puts("");

			printf("Perimeter length = %.2lf\n\n", sum);
		}
	}
	
	return 0;
}
