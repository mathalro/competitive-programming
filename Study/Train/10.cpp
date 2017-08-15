	#include <bits/stdc++.h>

	using namespace std;

	int main () {
		int n; scanf("%d", &n);
		vector<int> v;
	
		for (int i = 0; i < n; i++) {
			bool good = true;
			for (int j = 0; j < n; j++) {
				int a; scanf("%d", &a);
				if (a == 1 || a == 3) good = false;
			}
			if (good) v.push_back(i+1);
		}

		printf("%d\n", v.size());
		for (int i = 0; i < v.size(); i++) {
			if (i) printf(" %d", v[i]);
			else printf("%d", v[i]);
		}puts("");

		return 0;
	}
