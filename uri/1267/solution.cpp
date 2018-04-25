#include <bits/stdc++.h>
#define maxn 101

using namespace std;

int ans[maxn];

int main () {
	ios_base::sync_with_stdio(false);
	
	int n, d;
	
	while (cin >> n >> d) {
		if (!n && !d) break;
		
		for (int i = 0; i < n; i++) ans[i] = 1;
		for (int i = 0; i < d; i++) {
			for (int j = 0; j < n; j++) {
				int aux;
				cin >> aux;
				ans[j] &= aux;
			}
		}
		
		bool aluno = false;
		for (int i = 0; i < n; i++) {
			if (ans[i]) {
				cout << "yes" << endl;
				aluno = true;
				break;
			}
		}
		
		if (!aluno) cout << "no" << endl;
	}
	
	return 0;
}
