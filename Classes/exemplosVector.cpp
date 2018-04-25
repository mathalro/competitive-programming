#include <bits/stdc++.h>

using namespace std;

int main () {

	ios_base::sync_with_stdio(0); cin.tie(0);

	// criando e inicializando vector de 10 posicoes com 1s
	vector<int> v(10, 1);

	// percorrendo e acessando posicoes de um vector
	cout << "Percorrendo vector com indices: " << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}	cout << endl;

	// utilizando iterator para percorrer
	cout << "Percorrendo vector com iterators: " << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << ' ';
	} cout << endl;

	// inserindo no final do vector
	v.push_back(10);
	// inserindo no inicio do vector
	v.insert(v.begin(), 5);
	// percorrendo e acessando posicoes de um vector
	cout << "Percorrendo vector com indices: " << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}	cout << endl;

	return 0;
}
