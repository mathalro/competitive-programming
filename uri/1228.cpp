#include <bits/stdc++.h>
#define maxn 26

using namespace std;

int n, ans;
int ini[maxn], fim[maxn];

int main () {
	
	ios_base::sync_with_stdio(false);

	while(cin >> n) {
		for (int i = 0; i < n; i++) cin >> ini[i];
		for (int i = 0; i < n; i++) {
			int aux;
			cin >> aux;
			fim[aux] = i;
		}
		
		ans = 0;
		for (int i = 0; i < n; i++) {
			int x = ini[i];
			for (int j = i+1; j < n; j++) {
				int y = ini[j];
				if (fim[x] > fim[y]) ans++;
			}
		}
		
		cout << ans << endl;
	}
	
	return 0;
}