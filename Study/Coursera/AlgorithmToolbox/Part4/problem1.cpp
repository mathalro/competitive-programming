#include <bits/stdc++.h>
#define maxn 100009

using namespace std;

int v[maxn];

int bs(int val, int n) {
	int l = 0, r = n;
	while (l <= r) {
		int mid = (l+r)/2;
		if (v[mid] == val) {
			return mid;
		} else if (v[mid] > val) {
			r = mid-1;
		} else {
			l = mid+1;
		}
	}
	return -1;
}

int main () {

	int n; scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", v+i);
	}

	int k; scanf("%d", &k);

	for (int i = 0; i < k; i++) {
		int a; scanf("%d", &a);
		printf("%d ", bs(a, n-1));
	} puts("");

	return 0;
}
