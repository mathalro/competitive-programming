#include <bits/stdc++.h>
#define maxn 50

using namespace std;

int tiro[maxn];
char pos[maxn];

int main () {
	
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	for (int k = 0; k < n; k++) {
		int t, cont = 0;
		cin >> t;
		
		for (int i = 0; i < t; i++) cin >> tiro[i];
		for (int i = 0; i < t; i++) cin >> pos[i];
		
		for (int i = 0; i < t; i++) {
			if (pos[i] == 'J' && tiro[i] > 2 || pos[i] == 'S' && tiro[i] < 3) cont++;
		}
		
		cout << cont << endl;
	}
	
	return 0;
}