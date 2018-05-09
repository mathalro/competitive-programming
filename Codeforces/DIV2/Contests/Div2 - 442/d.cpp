#include <bits/stdc++.h>

using namespace std;

int main () {

	int n; scanf("%d", &n);
	vector<int> bombs;

	int meio = n/2 + 1;

	for (int i = meio; i > 1; i--) {
		bombs.push_back(i);
	}

	for (int i = 1; i < meio; i++) {
		bombs.push_back(i);
	}

	for (int i = n; i >= meio; i--) {
		bombs.push_back(i);
	} 

	printf("%d\n", bombs.size());
	for (int i = 0; i < bombs.size(); i++) {
		printf("%d ", bombs[i]);
	}

	puts("");
	
	return 0;
}
