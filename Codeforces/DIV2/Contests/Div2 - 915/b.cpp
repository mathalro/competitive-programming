#include <bits/stdc++.h>
#define inf 0x3f3f3f3f

using namespace std;


int main () {

	int n, p, l, r; scanf("%d %d %d %d", &n, &p, &l, &r);

	if (l == 1 && r == n) {
		printf("0\n");
	} else if (r == n) {
		printf("%d\n", abs(p-l)+1);
	} else if (l == 1) {
		printf("%d\n", abs(p-r)+1);
	} else {
		if (p < l) {
			printf("%d\n", r-p+2);
		} else if (p > r) {
			printf("%d\n", p-l+2);
		} else if (p >= l && p <= r) {
			if (p-l < r-p) {
				printf("%d", p-l+1 + (r-l+1));
			} else {
				printf("%d\n", r-p+1+(r-l+1));
			}
		}
	}
	
	return 0;
}
