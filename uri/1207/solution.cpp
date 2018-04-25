#include <bits/stdc++.h>
#define maxn 609
#define maxm 409

using namespace std;

int custo[maxn];
int tipo[maxm];

vector<int> g[maxn];

int main () {
	
	ios_base::sync_with_stdio(false);
	
	int n, m;
	
	while (cin >> n >> m) {
		for (int i = 0; i < n; i++) cin >> custo[i]; 
		for (int i = 0; i < m; i++) cin >> tipo[i];
		
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < tipo[i]; j++) {
				
			}
		}
		
	}
	
	return 0;
}
