#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	while(scanf("%d", &n) != EOF) {
		int cont = 0;
		int a = 10%n;

		cont++;
		int atual = a;
		cont += atual;

		int i = 2;
		while (cont%n) {
			atual = (atual*a)%n;
			cont += atual;
			i++;
		}

		printf("%d\n", i);
	}

	return 0;
}