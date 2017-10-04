/*
	accepted
*/

#include <bits/stdc++.h>

using namespace std;

string a, b;

bool search(int size) {
	int j = 0;
	for (int i = 0; i < b.size(); i++) {
		int cont = 0;
		bool foo = false;
		for (; j < a.size(); j++) {
			if (a[j] == b[i]) {
				cont++;
			}
			if (cont == size) {
				j++;
				foo = true;
				break;
			}
		}
		if (!foo) return false;
	}

	return true;
}

int main () {

	ios_base::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;

	while (t--) {
		cin >> a >> b;
		int l = 0, r = ceil(a.size()/b.size();
		int ans = 0;
		while (l <= r) {
			int mid = (l+r)/2;
			if (search(mid)) {
				ans = mid;
				l = mid+1;
			} else {
				r = mid-1;
			}
		}

		cout << ans << endl;
	}

	return 0;
}
