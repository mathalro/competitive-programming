#include <bits/stdc++.h>
#define maxn 1000009

using namespace std;

int tr[maxn][26];

int sz = 1;

int pesquisa(string s) {
	int node = 0;
	int cont = 1;
	for (int i = 0; i < s.size(); i++) {
		int tmp = 0;
		for (int j = 0; j < 26; j++) {
			if (tr[node][j] != -1) {
				tmp++;
			}
		}
		if (tmp > 1) {
			cont++;	
		}
		node = tr[node][s[i]];
	}

	return cont;
}

void inserir(string s) {
	int node = 0;
	for (int i = 0; i < s.size(); i++) {
		if (tr[node][s[i]] == -1) {
			tr[node][s[i]] = sz++;
		}
		node = tr[node][s[i]];
	}
}

int main () {
	
	int n; 

	while (scanf("%d", &n)) {	
		set<string> D;
		memset(tr, -1, sizeof tr);
		for (int i = 0; i < n; i++) {
			string s; cin >> s;
			D.insert(s);
			insert(s);
		}

		int sum = 0;
		for (string it : D) {
			sum += pesquisa(it);
		}

		printf("%lf\n", sum/D.size());
		
	}

	return 0;
}
