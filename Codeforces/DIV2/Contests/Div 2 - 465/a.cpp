#include <bits/stdc++.h>

using namespace std;

int main () {
	
	int n; scanf("%d", &n);
	int cont = 0;

	for (int i = 1; i <= n/2; i++) {
		if ((n-i)%i == 0) cont++;
	}
	printf("%d\n", cont);
	return 0;
}
