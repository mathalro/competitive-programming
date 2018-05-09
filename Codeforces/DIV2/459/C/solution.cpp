#include <bits/stdc++.h>
#define maxn 5001

using namespace std;

string s;

int main () {
	
	cin >> s;
	int stack, it, ans = 0;

	for (int i = 0; i < s.size(); i++) {
		stack = it = 0;
		for (int j = i; j < s.size(); j++) {
			stack += s[j] == '(';
			stack -= s[j] == ')';
			it += s[j] == '?';

			if (stack < 0) break;

			if (it > stack) {
				it--;
				stack++;
			}

			if ((j-i+1)%2 == 0 && it >= stack && stack >= 0) {
				ans++;
			}
		}
	}

	cout << ans << endl;
}
