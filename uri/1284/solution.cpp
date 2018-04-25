#include <bits/stdc++.h>
#define maxn 2000050

using namespace std;

int tr[maxn][30];

int sz = 1;

int search(string s) {
	int cont = 0, node = 0, c;
	for (int i = 0; i < s.size(); i++) {
		int tmp = 0;
		if (s[i] != '#') {
			for (int j = 0; j < 27; j++) {
				if (tr[node][j] != -1) {
					tmp++;
				}
			}
		}
		if (tmp > 1 || (tmp == 1 && node == 0)) {
			cont++;	
		}
		if (s[i] == '#') c = 26;
		else c = s[i]-'a';		
		node = tr[node][c];
	}

	return cont;
}

void insert(string s) {
	int node = 0;
	for (int i = 0; i < s.size(); i++) {
		int c;
		if (s[i] == '#') c = 26;
		else c = s[i]-'a';
		if (tr[node][c] == -1) {
			tr[node][c] = sz;
			memset(tr[sz], -1, sizeof tr[sz]);
			sz++;
		}
		node = tr[node][c];
	}
}

int main () {
	
	int n; 
	vector<string> D;
		
	while (scanf("%d", &n) != EOF) {	
		sz = 1;
		memset(tr[0], -1, sizeof tr[0]);
		for (int i = 0; i < n; i++) {
			string s; cin >> s;
			s += "#";
			D.push_back(s);
			insert(s);
		}

		int sum = 0;
		for (int i = 0; i < D.size(); i++) {
			int aux = search(D[i]);
			sum += aux;
		}
		
		printf("%.2lf\n", sum/(double)n);
		D.clear();
	}

	return 0;
}
