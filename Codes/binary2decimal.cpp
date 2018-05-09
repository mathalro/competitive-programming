#include <iostream>
#include <string>

using namespace std;

int main () {

	string s; 

	// using duplication method
	while (cin >> s && s != "q") {
		int cum = 0;
		int pow = 2;
		for (int i = 0; i < s.size(); i++) {
			cum = pow*cum + (s[i] == '1');
		}
		cout << cum << endl;
	}

	return 0;
}
