#include <bits/stdc++.h>

using namespace std;

int main () {
	int t; scanf("%d", &t);
	
	set<int> S;

	for (int i = 3; i <= 360; i++) { 
		if ( (double)((i-2)*180)/(double)i  - ((i-2)*180)/i == 0.0) {
			S.insert(((i-2)*180)/i);
		}
	}

	while (t--) {
		int n; scanf("%d", &n);
		
		if (S.find(n) != S.end()) {
			printf("YES\n");
		}	else {
			printf("NO\n");
		}
	}
	
	return 0;
}
