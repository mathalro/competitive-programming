#include <bits/stdc++.h>

using namespace std;

void putline(int n, int type) {
	if (type%2 == 0) {
		for (int i = 0; i < n; i++) printf("#");
	} else if (type == 1) {
		for (int i = 0; i < n-1; i++) printf(".");
		printf("#");
	} else if (type == 3) {
		printf("#");
		for (int i = 0; i < n-1; i++) printf(".");
	}
	puts("");
}

int main () {
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 0, j = 0; j < n; i = (i+1)%4, j++) {
		putline(m, i);
	}
	return 0;
}
