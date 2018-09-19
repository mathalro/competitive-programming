#include <bits/stdc++.h>

using namespace std;

int main () {
	string a, b;
	cin >> a >> b;
	int ans = 0;
	for (int i = 0; i <= a.size()-b.size(); i++) {
		bool foo = true;
		for (int j = 0; j < b.size(); j++) {
			if (a[i+j] == b[j]) {
				foo = false;
				break;
			}
		}
		ans += foo;
	}
	
	printf("%d\n", ans);

	return 0;
}
