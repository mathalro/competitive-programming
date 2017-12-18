#include <bits/stdc++.h>

using namespace std;

int main () {

	long long m, n; scanf("%lld %lld", &m, &n);

	int a1 = 1, a2 = 0;
	long long sum = 0;
	vector<int> v;
	for (int i = 0; i < 65; i++) {
		sum += a2;
		v.push_back(sum%10);
		//printf("%d ", sum%10);
		int tmp = a2;
		a2 = a1;
		a1 = (tmp + a1)%10;
	}//puts("");

	int r1 = m%60;
	int r2 = n%60;

	if (r1 > r2) swap(r1, r2);

	int ans = v[r2]-v[r1-1] >= 0 ? v[r2]-v[r1-1] : v[r2]-v[r1-1] + 10;

	printf("%d\n", ans);

}
