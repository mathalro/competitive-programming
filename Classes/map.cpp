#include <bits/stdc++.h>

using namespace std;

int main () {

	ios_base::sync_with_stdio(0); cin.tie(0);

	map<int, int> mapa;

	mapa.insert({10, 10}); cout << mapa[10] << endl;

	mapa[1] = 1;
	cout << mapa[1] << endl;
	mapa.erase(1);
	cout << mapa[1] << endl;

	mapa[1] = 1;
	cout << mapa[1] << endl;
	mapa.erase(mapa.begin());
	cout << mapa[1] << endl;

	return 0;
}
