#include <bits/stdc++.h>
#define maxn 16
#define inf 0x3f3f3f3f

using namespace std;

struct point {
	double x, y;
	point() { x = y = 0.0; }
	point(double _x, double _y) : x(_x), y(_y) {}
};

point v[maxn];
int n; 
double dp[maxn][1<<maxn];


double dist(point a, point b) {
	return hypot(a.x-b.x, a.y-b.y);
}

double tsp(int at, int mask) {
	if (mask == (1<<(n+1))-1) return dist(v[at], v[0]);

	if (dp[at][mask] >= -0.0) return dp[at][mask];

	double menor = inf;
	for (int i = 0; i <= n; i++) {
		if ((mask & (1<<i)) == 0) {
			menor = min(menor, dist(v[at], v[i])+tsp(i, mask | (1<<i)));
		}
	}

	return dp[at][mask] = menor;
}

int main () {
	while (scanf("%d", &n) && n) {
		for (int i = 0; i <= n; i++) {
			double x, y; scanf("%lf %lf", &x, &y);
			v[i] = {x, y};
		}

		for (int i = 0; i < maxn; i++) {
			for (int j = 0; j < (1<<maxn); j++) {
				dp[i][j] = -1.0;
			}
		}
		printf("%.2lf\n", tsp(0, 1));
	}

	return 0;
}


