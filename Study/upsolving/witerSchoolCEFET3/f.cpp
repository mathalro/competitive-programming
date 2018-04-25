#include <bits/stdc++.h>
#define eps 0.000000001

using namespace std;

long long pa(int n) {
	return n*(n+1)/2;
}

int main () {

	int t; scanf("%d", &t);

	while (t--) {
		int n; scanf("%d", &n);
		if (n != 1 && n&1) {
			printf("%d = %d + %d\n", n, n/2, n/2+1);
			goto label;
		} else {
			for (int i = 3; ; i++) {
				if (pa(i) > n) break;
				int sum = pa(i);
				double val = (n-sum)/(double)i;
				if (abs(val-floor(val)) <= eps) {
					printf("%d = %d", n, 1+(int)val);
					for (int j = 2 	; j <= i; j++) {
						printf(" + %d", j+(int)val);
					}
					puts("");
					goto label;
				}
			}
		}

		printf("IMPOSSIBLE\n");		

		label: continue;
	}

	return 0;
}
