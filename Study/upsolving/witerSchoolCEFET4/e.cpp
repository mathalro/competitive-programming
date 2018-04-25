#include <bits/stdc++.h>
#define maxn 100001

using namespace std;

int v[maxn];

int main () {

	ios_base::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	bool foo = true;
	int maior = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (v[i] != v[0]) foo = false; 
		maior = max(maior, v[i]);
	}

	sort(v, v+n);

	
	return 0;
}
