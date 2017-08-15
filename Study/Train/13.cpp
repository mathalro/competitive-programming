#include <bits/stdc++.h>
#define maxn 100009

using namespace std;

int v[maxn];

int main ()  {
	long long int n, K; scanf("%lld %lld", &n, &K);
	for (int i = 0; i < n; i++) {
		scanf("%d", v+i);
	}

	long long int k = 0;
	for (int i = 1; i <= n; i++) {
		k += i;
		if (k >= K) {
			while (k != K) {
				k--;
				i--;
			}
			printf("%d\n", v[i-1]);
			return 0;
		}
	}
	
	return 0;
}
