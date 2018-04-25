#include <bits/stdc++.h>

using namespace std;

int n;
long long ans;

int main () {
	scanf("%d", &n);
	int prevNum;
	long long prevAns;
 	map<int, long long> mapa;

	scanf("%d", &prevNum);
	prevAns = 0;
	mapa[prevNum]++;
	
	for (int i = 1; i < n; i++) {
		int cur; scanf("%d", &cur);

		long long currentCalc = prevAns + (cur-prevNum)*i;
		long long tmp;
		if (currentCalc > 0) tmp = currentCalc - mapa[cur+1];
		else tmp = currentCalc + mapa[cur-1];
		ans += tmp;

		prevAns = currentCalc;
		prevNum = cur;
		mapa[cur]++;
	}

	printf("%lld\n", ans);
}
