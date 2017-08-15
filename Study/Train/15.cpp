#include <bits/stdc++.h>
#define maxn 100009

using namespace std;

int v[maxn];

int main () {
	int n, m; scanf("%d %d", &n, &m);
	vector<int> toys;
	int ans = 0;	

	for (int i = 0; i < n; i++) {
		scanf("%d", v+i);
	}

	sort(v, v+n);

	int i = 1, j = 0;
	while (m > 0) {
		if (i == v[j]) {
			i++;
			j++;
		} else {
			m -= i;
			if (m >= 0)	{
				toys.push_back(i);
				ans++;
			}
			i++;
		}
	}

	printf("%d\n", ans);
	for (int i = 0; i < toys.size(); i++) {
		if (i) printf(" %d", toys[i]);
		else printf("%d", toys[i]);
	}puts("");

	return 0;	
}
