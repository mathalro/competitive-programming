#include <bits/stdc++.h>
#define maxn 100009
#define inf 0x3f3f3f3f

using namespace std;

int v[maxn];

int main () {

	int n, d; scanf("%d %d", &n, &d);

	int sum;
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	int ans = 0;
	long long conta = 0;
	for (int i = 0; i < n; i++) {
		long long sum = 0;
		while (v[i] != 0 && i < n) {
			sum += v[i];
			if (sum + conta > d) {
				conta = conta-sum;
				if (conta < 0) {
					printf("-1\n");
					return 0;
				}
			}
			i++;
		}
	
		if (conta + sum < 0) {
			ans++;
		}
		conta = d;
	}

	printf("%d\n", ans);
	return 0;
}
