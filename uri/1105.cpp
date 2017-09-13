#include <bits/stdc++.h>
#define maxb 21

using namespace std;

int reserva[maxb];

int main () {

	int b, n;

	while (scanf("%d %d", &b, &n)) {
		if (b+n == 0) return 0;

		for (int i = 0; i < b; i++) {
			scanf("%d", &reserva[i]);
		}

		for (int i = 0; i < n; i++) {
			int d, c, v;
			scanf("%d %d %d", &d, &c, &v);
			reserva[d-1] -= v;
			reserva[c-1] += v;
		}

		for (int i = 0; i < b; i++) {
			if ( reserva[i] < 0 ) {
				printf("N\n");
				break;
			}

			if (i == b-1) {
				printf("S\n");
			}
		}
	}

	return 0;
}