#include <bits/stdc++.h>
#define maxn 100005

using namespace std;

int v[maxn];

int main () {

	int n; scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", v+i);
	}

	sort(v, v+n, greater<int>());
	bool ans = false;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			int k = j+1;
			if (v[i] < v[j]+v[k] && v[j] < v[i]+v[k] && v[k] < v[i]+v[j]) {
					ans = true;
					goto label;
			}
		}
	}

	label: if (ans) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}

	return 0;
}
