#include <bits/stdc++.h>
#define maxn 1001
#define inf 0x3f3f3f3f

using namespace std;

int v[maxn];
set<int> Smax, Smin;
queue<int> q;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;

	while (t--) {
		int e, p, j; cin >> e >> p >> j;
		string s = "";
		string maiorS = s;
		long long maior = -1;
		for (int k = 0; k < e; k++) {
			cin >> s;
			for (int i = 0; i < j; i++) {
				int a; cin >> a;
				q.push(a);
				Smin.insert(a);
				Smax.insert(-a);
				v[a]++;
			}

			long long cont = 0;
			for (int i = j; i < p; i++) {
				cont += *(Smin.begin()) + (*(Smax.begin()))*(-1);
				int a; cin >> a;
				v[q.front()]--;
				if (v[q.front()] <= 0) {
					Smin.erase(q.front()); 
					Smax.erase(-q.front());
				}
				q.push(a);
				q.pop();
				Smin.insert(a);
				Smax.insert(-a);
				v[a]++;
			}
				
			cont += *(Smin.begin()) + (*(Smax.begin()))*(-1);
			if (cont > maior) {
				maiorS = s;
				maior = cont;
			} else if (cont == maior && maiorS > s) {
				maiorS = s;
				maior = cont;
			}

			memset(v, 0, sizeof v);
			Smax.clear(); Smin.clear();
			while(!q.empty()) q.pop();
		}
		cout << maiorS << ' ' << maior << endl;
	}

	return 0;
}
