#include <bits/stdc++.h>

#define inf 0x3f3f3f3f
#define mod 1e9+7
#define debug(var) cerr << #var << ':' << var << ' '

typedef long long ll;
typedef long double ld;

using namespace std;

int n, k;

vector<string> aluno, ordenado;
vector<int> work;

void f() {
	int menor, temp;
	for (int i = 0; i < n && k; i++) {
		menor = i;
		for (int j = i+1; j < n && j-i <= k; j++) {
			if (work[j] < work[menor]) {
				menor = j;
			}
		}
		k = k - (menor-i);

		temp = work[menor];
		work.erase(work.begin()+menor);
		work.insert(work.begin()+i, temp);
	}
}

int main () {
	ios_base::sync_with_stdio(false);

	string s;
	int caso = 0;
	
	while (cin >> n >> k) {
		if (!n && !k) break;
		
		for (int i = 0; i < n; i++) {
			cin >> s;
			aluno.push_back(s);
			ordenado.push_back(s);
		}
		
		sort(ordenado.begin(), ordenado.end());
		
		for (int i = 0; i < n; i++) {
			work.push_back((int)(find(ordenado.begin(), ordenado.end(), aluno[i])-ordenado.begin() ));
		}
		
		f();
		
		cout << "Instancia " << (++caso) << endl;
		for (int i = 0; i < n; i++) {
			auto it = find(aluno.begin(), aluno.end(), ordenado[work[i]]);
			cout << aluno[it-aluno.begin()] << ' ';
		}
		cout << endl << endl;
		
		work.clear(); aluno.clear(); ordenado.clear();
		
	}
	
	return 0;
} 
