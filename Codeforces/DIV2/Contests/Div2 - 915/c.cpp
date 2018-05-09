#include <bits/stdc++.h>
#define inf 0x3f3f3f3f

using namespace std;

int vis[30];
string s, u;

bool pode(int p, int x) {
	string subU = u.substr(p+1, u.size()-p-1);
	string subS;
	for (int i = 0; i < s.size(); i++) {
		if (!vis[i] && i != x) {
			subS += s[i];
		}
	}
	sort(subS.begin(), subS.end());
	return subS <= subU;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> s >> u;
	string ans;

	if (s.size() < u.size()) {
		sort(s.begin(), s.end(), greater<char>());
		cout << s << endl;
		return 0;
	}

	while (s.size() != u.size()) {
		u = '0' + u;
	}

	for (int i = 0; i < u.size(); i++) {
		char tmp = (char)('0'-1);
		int id;		
		for (int j = 0; j < s.size(); j++) {
			if (!vis[j] && s[j] <= u[i]) {	
				bool foo = true;
				if (s[j] == u[i]) foo = pode(i, j);
				if (s[j] > tmp && foo) {
					id = j;
					tmp = s[j];
				}
			}
		}
		
		vis[id] = 1;
		ans += tmp;

		if (tmp < u[i]) {
			string c;
			int l = 0;
			for (int k = 0; k < s.size(); k++) {
				if (!vis[k]) c += s[k]; 
			}

			sort(c.begin(), c.end(), greater<char>());
			ans += c;
			break;
		}
	}	

	cout << ans << endl;
	
	return 0;
}
