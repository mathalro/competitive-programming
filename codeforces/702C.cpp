#include <bits/stdc++.h>
#define maxn 100001
#define inf 3000000000

using namespace std;

set<long long> torres;
int cidades[maxn]; 

int main() {
	int c, t;
	scanf("%d %d", &c, &t);

	for (int i = 0; i < c; i++) {
		scanf("%d", &cidades[i]);
	}
	for (int i = 0; i < t; i++) {
		long long torre;
		scanf("%lld", &torre);
		torres.insert(torre);
	}

	torres.insert(5);
	torres.insert(7);
	torres.insert(10);
	torres.insert(-inf);
	torres.insert(inf);

	auto inicio = torres.begin();
	auto fim = torres.end();
	auto fim1 = --fim;
	auto fim2 = ++fim;
	fim2++;
	cout << *fim1 << " " << *fim2 << endl;
	long long maior = 0;
	for(int i = 0; i < c; i++) {
		long long raio = inf;
		auto d = torres.lower_bound(cidades[i]); 
		if (d != fim) {
			raio = *d - cidades[i];
			//cout << "direita: " << *d << endl;	
		}
		d--;
		if (d != inicio) {
			//cout << "esquerda: " << cidades[i] << " - " << *d << endl;
			raio = min(raio, cidades[i] - *d);
		}

		//cout << "raio " << i+1 << ": " << raio << endl;

		maior = max(maior, raio);
	}

	printf("%lld\n", maior);

	return 0;
}