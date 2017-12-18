#include <bits/stdc++.h>

using namespace std;

struct item {
	int valor, peso;
};

vector<item> v;

int getIndex() {
	int indice = 0;

	while (v[indice].peso == 0 && indice < v.size()) indice++;
	if (indice == v.size()) return -1;
	for (int i = indice+1; i < v.size(); i++) {	
		if (v[i].peso) {
			if (v[i].valor/(double)v[i].peso > v[indice].valor/(double)v[indice].peso) {
				indice = i;
			}
		}
	}

	return indice;
}

double f(int W) {
	if (W <= 0) return 0;

	int safe = getIndex();

	if (safe == -1) return 0;

	int peso = v[safe].peso;
	int val = v[safe].valor;

	int a = min(peso, W);
	v[safe].peso = 0;
	double ans = a*(val/(double)peso) + f(W-a); 
	return ans;
}


int main () {

	int n, W; scanf("%d %d", &n, &W);

	for (int i = 0; i < n; i++) {
		int a, b; scanf("%d %d", &a, &b);
		v.push_back({a, b});
	}

	/* problem (Maximize the value in a knapsack with W capacity) --------> Safe Choice (Choice the item that have the great value per unit)
								/\																															||
								||																															\/
								 ------------------------ subproblem (W - the quatity of the safe item that fit in the knapsck)
	*/																												

	printf("%.4lf\n", f(W));

	return 0;
}	
