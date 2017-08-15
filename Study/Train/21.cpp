#include <bits/stdc++.h>

using namespace std;

int main () {
	int n; scanf("%d", &n);

	int changes = 0;
	int previous; scanf("%d", &previous);
	int first = previous;

	int pt = n, a;
	for (int i = 1; i < n; i++) {
		scanf("%d", &a);
		if (a < previous) {
			changes++;
			pt = i;
		}
		previous = a;
	}

	if (first < a) {
		changes++;
	}

	if (changes > 1) {
			printf("-1\n");
			return 0;
	}

	printf("%d\n", n-pt);
	
	return 0;
}
