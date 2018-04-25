#include <bits/stdc++.h>

using namespace std;

vector<string> fib;

string convert(int n) {
	int cont = 0;
	string aux = "", numero = "";
	while (cont != 3 && n >= 1) {
		char c = (n%10)+'0';
		aux += c;
		n/=10;
		cont++;
	}

	while (cont != 3) {
		aux += "0";
		cont++;
	}

	for (int i = aux.size()-1; i >= 0; i--) {
		numero += aux[i];
	}

	return numero;
}

int crivo() {

	int j = 0;
	fib.push_back("001");
	long long i = 1, anterior = 1, prox;
	while (j < 1600) {
		fib.push_back(convert(i));
		prox = (anterior + i)%1000;
		anterior = i;
		i = prox;
		j++;
	}
}

int main () {

	crivo();
	int t = 1;
	string n;
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;
		int ans = 0, ciclo = 1500;
		for(int i = 0; i < s.size(); i++) {
		   ans *= 2;
		   ans += (s[i]-'0');
		   ans %= ciclo;
		}

		cout << fib[ans-1] << endl;

	}

	return 0;
}