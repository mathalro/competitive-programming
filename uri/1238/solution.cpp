#include <bits/stdc++.h>

using namespace std;

int main () {
	ios_base::sync_with_stdio(0);
	int t; cin >> t;
	string a, b; 

	while (t--) {
		cin >> a >> b;
		string ans;

		int i;
		for (i = 0; i < b.size() && i < a.size(); i++) {
			ans += a[i];
			ans += b[i];
		}

		if (i == a.size()) 
			for (i = a.size(); i < b.size(); i++) 
				ans += b[i];
		if (i == b.size()) 
			for (i = b.size(); i < a.size(); i++) 
				ans += a[i];
	
		cout << ans << endl;
	}

	return 0;
}
