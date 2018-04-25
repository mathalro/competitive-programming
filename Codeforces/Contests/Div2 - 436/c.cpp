#include <bits/stdc++.h>
#define maxn 102

using namespace std;

int v[maxn];

int main () {

	int a, b, f, k; scanf("%d %d %d %d", &a, &b, &f, &k);

	if (2*f-b > 0) {
		printf("-1\n");
		return 0;
	}

	if ((2*(a-f))-b > 0) {
		printf("-1\n");
		return 0;
	}

	int x = f;
	int y = a-f;
	int cont = 0;
	int t = b-x;

	if (k == 1) {
		if (y < t) {
			printf("0\n");
		} else {
			printf("1\n");
		}
		return 0;
	}

	if (k&1) {
		
	} else {

	}

	if (vi == 0) {
		
	}

	return 0;
}
