#include <bits/stdc++.h>
#define inf 0x3f3f3f3f

using namespace std;

vector<int> misseis;
int *pd;

int ssc(int n) {
	for (int m = 0; m < n; m++) {
		pd[m] = 1;
		for (int i = m-1; i >= 0; i--) {
			if (misseis[i] > misseis[m] && pd[i]+1 > pd[m]) {
				pd[m] = pd[i] + 1;
			}
		}
	}

	int maior = -inf;
	for (int i = 0; i < n; i++) {
		maior = max(maior, pd[i]);
	}

	return maior;
}

int main () {
	int x, y = 0, test = 1;

	while (scanf("%d", &x)) {
		if (x == -1) break;
		if (test > 1) puts("");
		misseis.push_back(x);
		while (scanf("%d", &x) && x != -1) {
			misseis.push_back(x);
		}

		pd = (int*) malloc(misseis.size()*sizeof(int));

		printf("Test #%d:\n  maximum possible interceptions: %d\n", test, ssc(misseis.size()));
		test++;
		misseis.clear();
	}
	return 0;
}