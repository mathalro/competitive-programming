#include <bits/stdc++.h>

using namespace std;

int main () {

	int n; scanf("%d", &n);

	int espectador = 3;
	
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		if (a == espectador) {
			printf("NO\n");
			return 0;
		} else {
			if (a == 1 && espectador == 2) espectador = 3;
			else if (a == 1 && espectador == 3) espectador = 2;
			else if (a == 2 && espectador == 1) espectador = 3;
			else if (a == 2 && espectador == 3) espectador = 1;
			else if (a == 3 && espectador == 1) espectador = 2;
			else if (a == 3 && espectador == 2) espectador = 1;	
		}
	}

	printf("YES\n");


	return 0;
}
