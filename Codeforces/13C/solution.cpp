#include <bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3fLL
#define maxn 1000000001

using namespace std;

int n;
long long ans;
long long sm, gt;
vector<long long> v;

void input() {
	scanf("%d", &n);
	sm = inf;
	gt = -inf;
	for (int i = 0; i < n; i++) {
		long long a; scanf("%lld", &a);
		sm = min(sm, a);
		gt = max(gt, a);
		v.push_back(a);
	}
}

void solution() {
	ans = inf;

	int k = 0, l = n-1;
	while (v[k] == sm && k < n) k++;
	while (v[l] == gt && l >= 0) l--;	

	if (k > l) ans = 0;

	for (int i = k; i <= l; i++) {
		long long count = 0;
		for (int j = k; j < l; j++) {
			count += abs(v[i]-v[j]);
		}
		ans = min(ans, count);
	}
}

void print() {
	printf("%lld\n", ans);
}

int main () {
	input();
	solution();
	print();
}
