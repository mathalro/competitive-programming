#include <bits/stdc++.h>

using namespace std;

int main () {
 
    ios_base::sync_with_stdio(false);
  
    string base = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./", s;
		
    while(getline(cin, s)) {
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ') cout << " ";
			for (int j = 0; j < base.size(); j++) {
				if (base[j] == s[i]) {
					cout << base[j-1];
					break;
				}
			}
		}
		
		cout << endl;
    }
  
	return 0;
}
