#include <bits/stdc++.h>

using namespace std;

int main () {
	
	map<string, string> mapa;

	int n, m; scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		string name, ip; cin >> name >> ip;
		ip += ";";
		mapa[ip] = name;
	}

	for (int i = 0; i < m; i++) {
		string com, ip; 
		cin >> com >> ip;
		cout << com << ' ' <<  ip << ' ' << "#" << mapa[ip] << endl;
	}
	
}
