#include <bits/stdc++.h>

using namespace std;

vector<int> profit, clicks;

int main () {

	int n; scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		profit.push_back(a);
	}
	
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		clicks.push_back(a);
	}

	sort(profit.begin(), profit.end());
	sort(clicks.begin(), clicks.end());

	// problem (choice a permutation) ---------> safe (choice the great profit with great click)
	long long cont = 0;
	for (int i = 0; i < n; i++) {
		cont += (long long)profit[i]*clicks[i];
	}
	printf("%lld\n", cont);

	return 0;
}
