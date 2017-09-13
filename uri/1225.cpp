#include <bits/stdc++.h>
#define maxn 10009

using namespace std;

int n;
vector<int> coral;

int main () {
	
	ios_base::sync_with_stdio(false);
	
	while (cin >> n) {
		int cont = 0, coral[n];
		
		for (int i = 0; i < n; i++) {
			cin >> coral[i];
			cont += coral[i];
		}
		
		if (cont%n) {
			cout << "-1" << endl;
		} else {
			int individual = cont / n, comp = 1, i = 0;
			
			while (coral[i] < individual) {
				comp += (individual-coral[i]);
				i++;
			}
			
			cout << comp << endl;
		}
	}
	
	return 0;
}
