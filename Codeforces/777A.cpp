#include <iostream>
#include <cstdio>

typedef long long ll;

using namespace std;

int main () {
	
	ll n;
	int x;
	scanf("%lld %d", &n, &x);
	
	int resto = n%6;
	int v[3] = {0, 0, 0};
	v[x] = 1;
	
	while (resto) {
		int aux;
		if (resto&1) {
			aux = v[0];
			v[0] = v[1];
			v[1] = aux;
		} else {
			aux = v[2];
			v[2] = v[1];
			v[1] = aux;
		}
		resto--;
	}
	
	for (int i = 0; i < 3; i++) {
		if (v[i]) {
			printf("%d\n", i);
			break;
		}
	}
	
	return 0;

}