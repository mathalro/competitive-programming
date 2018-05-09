#include <bits/stdc++.h>

using namespace std;

int main () {

	string s; cin >> s;

	vector<string> v;

	v.push_back("Danil");
	v.push_back("Olya");
	v.push_back("Slava");
	v.push_back("Ann");
	v.push_back("Nikita");

	int ans = 0;
	for (int i = 0; i < v.size(); i++) {
		int cont = 0;
		long long nPos = -1;
		while(1) {
      nPos = s.find(v[i], nPos+1);
			if (nPos == string::npos) break;
			cont++;
    }
		if (cont == 1) ans++;
		else if (cont > 1) {
			printf("NO\n");
			return 0;
		}
	}

	if (ans == 1) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	return 0;
}
