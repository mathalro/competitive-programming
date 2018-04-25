#include <bits/stdc++.h>

using namespace std;

int main () {

	int n;

	while (scanf("%d", &n)) {
		if (!n) {
			break;
		}

		for (int i = 0; i < n; i++) {
			int a, b, c, d, e;
			scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
			int marcas = (int)(a <= 127) + (int)(b <= 127) + (int)(c <= 127) + (int)(d <= 127) + (int)(e <= 127);
			if ( marcas != 1 ) {
				printf("*\n");
			} else if ( (a <= 127) ) {
				printf("A\n");
			} else if ( (b <= 127) ) {
				printf("B\n");
			} else if ( (c <= 127) ) {
				printf("C\n");
			} else if ( (d <= 127) ) {
				printf("D\n");
			} else {
				printf("E\n");
			}
		}

	}

	return 0;
}