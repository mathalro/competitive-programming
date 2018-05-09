#include <bits/stdc++.h>

using namespace std;

int main () {

	int n; scanf("%d", &n);
	string s;
	cin >> s;

	int cont = 0;
	for (int i = 0; i < n; i++) {
		if (cont == 0 && s[i] == '0') {
			printf("0");
		} else if (s[i] == '0') {
			printf("%d", cont);
			cont = 0;
		}else {
			cont++;
		}
	}

	printf("%d\n", cont);

	return 0;
}
