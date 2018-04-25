#include <bits/stdc++.h>
#define maxn 1001

using namespace std;

int v[maxn];
int ini[maxn];
string s;
int cont = 0;

int sentido(int i) {
	if (v[i] == ini[i]) return 0;
	int normal, contrario;
	if (v[i] > ini[i]) {
		normal = (25-v[i]) + ini[i];
		contrario = v[i]-ini[i];
	} else if (v[i] < ini[i]){
		normal = ini[i]-v[i];
		contrario = v[i] + 26-ini[i];
	}

	if (normal <= contrario) return 1;
	return -1;
}

void f(int i) {
	if (i == s.size()) return;
	int tmp = sentido(i);
	if (tmp == 1) {
		v[i]++;		
	} else if (tmp == -1) {
		v[i]--;
		if (v[i] == -1) v[i] = 25;
	} else {
		f(i+1);
		return;
	}

	int j = i+1;
	while (sentido(j) == tmp && j != s.size()) {
		if (tmp == 1) {
			v[j]++;		
		} else if (tmp == -1) {
			v[j]--;
			if (v[j] == -1) v[j] = 25;
		}
		j++;
	}

	cont++;
	f(i);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	while (cin >> s && s != "*") {
		for (int i = 0; i < s.size(); i++) {
			ini[i] = s[i]-'a';
			v[i] = 0;
		}

		cont = 0;
		f(0);
		printf("%d\n", cont);
	}
}
