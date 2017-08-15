#include <bits/stdc++.h>

using namespace std;

multiset<int> S;

int main () {

	int sum = 0;
	for (int i = 0; i < 5; i++) {
		int a; scanf("%d", &a);
		S.insert(a);
		sum += a; 
	}

	int maior = 0;
	for (auto it : S) {
		int aux = S.count(it);
		if (aux >= 3) {
			maior = max(maior, 3*it);
		} else if (aux == 2) {
			maior = max(maior, 2*it);
		}
	}

	printf("%d\n", sum-maior);
	
	return 0;
}
