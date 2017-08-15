#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

int main () {

	map<char, int> good;
	
	string s; cin >> s;

	for (int i = 0; i < s.size(); i++) {
		good[s[i]] = i;
	}

	cin >> s;

	int t; cin >> t;
	while (t--) {
		string target; cin >> target;
		bool foo = true;

		for (int i = 0, j = 0;;) {
			//cout << i << ' ' << j << endl;
			if (j < target.size() && i < s.size()) {
				if (s[i] != target[j]) {
					if (s[i] == '?' && good.find(target[j]) != good.end()) {
						i++; j++;
					} else if (s[i] == '*' && good.find(target[j]) == good.end()) {					
						while (good.find(target[j]) == good.end() && j < target.size()) j++;
						i++;
					} else if (s[i] == '*' && good.find(target[j]) != good.end()){
						i++;
					} else {
						foo = false;
						break;
					}
				} else {
					i++; j++;
				}
			} else {
			
				if (j >= target.size()) {				
					if (i < s.size() && s[i] != '*') {
						foo = false;
						break;
					} else if (i < s.size()-1){
						i++;
						continue;
					} else {
						break;
					}
				}
	
				if (i >= s.size()) {
					foo = false;
					break;
				} 
			}
		}

		if (foo) {
			printf("YES\n");		
		} else {
			printf("NO\n");
		}

	}

	return 0;
}
