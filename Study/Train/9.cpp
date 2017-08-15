#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define maxn 100005

using namespace std;

struct point {
	int l, r;
};

point v[maxn];

int main () {

	int k; scanf("%d", &k);

	int ml = inf, mr = -inf, pl = 1, pr = 1, l = 0, r = 0;	
	for (int i = 1; i <= k; i++) {
		int a, b; scanf("%d %d", &a, &b);
		v[i].l = a; v[i].r = b;
		l += a; r += b;
		if (ml > a-b) {
			ml = a-b;
			pl = i;
		}
		if (mr < a-b) {
			mr = a-b;
			pr = i;
		}
	}

	int x = abs(l-r);
	int y = abs((l-v[pl].l+v[pl].r) - (r-v[pl].r+v[pl].l));
	int z = abs((l-v[pr].l+v[pr].r) - (r-v[pr].r+v[pr].l));

	if (x >= y && x >= z) {
		printf("0\n");
	} else if (y >= z) {
		printf("%d\n", pl);
	} else {
		printf("%d\n", pr);
	}

	return 0;
}
