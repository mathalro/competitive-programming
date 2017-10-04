/*
	accepted

	(v[i] + v[i+1] + v[i+2] + ... + v[j])%X = 0
	((v[0] + v[1] + ... + v[j]) - (v[0] + v[1] + ... + v[i]))%X = 0
	(v[0] + v[1] + ... + v[j])%X = (v[0] + v[1] + ... + v[j])%X

*/

#include <bits/stdc++.h>
#define maxn 30

using namespace std;

int v[maxn];

unordered_map<int, int> mapa;

int main () {

	int n, t, a, x, y; scanf("%d %d %d %d %d", &n, &t, &a, &x, &y);
	for (int i = 0; i < t; i++) {
		scanf("%d", v+i);
	}
	
	long long sum = 0;
	int i = 0;
	mapa[sum] = i;
	do {
		i++;
		sum += a;
		if (mapa.find(sum%x) != mapa.end()) {
			if (i-mapa[sum%x] >= y) {
				printf("%d %d\n", mapa[sum%x], i-1);
				return 0;
			}
		} else {
			mapa[sum%x] = i;
		}

		int bit = a;
		for (int j = 1; j < t; j++) {
			bit = bit^(a>>(v[j]));
		}
		bit &= 1;	
		a = (a>>1) | (bit<<(n-1));
	} while (1);

	return 0;
}
