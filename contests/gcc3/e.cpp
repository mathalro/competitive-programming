#include <bits/stdc++.h>
#define maxn 100001

using namespace std;

int vis1[maxn], vis2[maxn];

int main () {

	int n, m; scanf("%d %d", &n, &m);

	if (!m) {
		printf("%d\n", n-1);
		return 0;
	}

	vector<int> v, w;
	set<int> S;

	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		int menor = min(a, b);
		int maior = max(a, b);
		if (!vis1[menor]) {
			v.push_back(menor);
			vis1[menor] = 1;
		}
		if (!vis2[maior]) {
			w.push_back(maior);
			vis2[maior] = 1;
		}
		S.insert(maior);
	}

	sort(v.begin(), v.end());
	sort(w.begin(), w.end());

	/*for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}cout << endl;
	for (int i = 0; i < w.size(); i++) {
		cout << w[i] << ' ';
	}cout << endl;*/
	
	printf("%d\n", max(0, w[0]-v[v.size()-1]));

	return 0;
}
