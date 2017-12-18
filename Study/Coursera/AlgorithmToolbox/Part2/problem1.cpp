#include <iostream>

using namespace std;

int main () {

	int n; scanf("%d", &n);

	if (n == 0 || n == 1) printf("%d\n", n);
	else {
		int a1 = 0, a2 = 1;
		for (int i = 2; i <= n; i++) {
			int aux = a1;
			a1 = a2;
			a2 = a2+aux;
		}
		printf("%d\n", a2);
	}	
	
	return 0;
}
