#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define L 28

using namespace std;

int S[L];

bool find(char a) {
	int pos = a-'a';
	for (int i = pos+1; i < L; i++) {
		if (S[i] == 1) return true;
	}
	return false;
}

char upper(char a) {
	int pos = a-'a';
	for (int i = pos+1; i < L; i++) {
		if (S[i] == 1) return (char) ('a'+i);
	}
}

char menor() {
	for (int i = 0; i < L; i++) {
		if (S[i] == 1) return (char) ('a'+i);
	}
}

int main () {

	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, k; cin >> n >> k;
	string s; cin >> s;
	string ans;	

	for (int i = 0; i < s.size(); i++) {
		S[s[i]-'a'] = 1;
	}

	int pos = 0;

	if (k <= s.size()) {
		for (int i = min(k-1, (int)(s.size()-1)); i >= 0; i--) {
			if (find(s[i])) {
				pos = i;
				break;
			}
		}
	} else {
		pos = s.size();
	}
	
	for (int i = 0; i < pos; i++) {
		ans += s[i];
	}

	if (k <= s.size())
		ans += upper(s[pos]);

	while (ans.size() != k) {
		ans += menor();
	}

	cout << ans << endl;

	return 0;
}
