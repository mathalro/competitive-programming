#include <bits/stdc++.h>

using namespace std;

int v[] = {1, 5, 10};

int f(int problem) {
	if (problem <= 0) return 0;

	int safe = 0;
	for (int i = 0; i < 3; i++) {
		if (v[i] <= problem) {
			safe = max(safe, v[i]);
		}
	}

	int qtd = problem/safe;
	return qtd + f(problem-qtd*safe);
}

int main () {

	int n; scanf("%d", &n);

	/* 
		problem - minimize the number of coins
		problem (N) --------> Safety Choice (Get the Great coin that fit in the problem)
        /\                                              ||
        ||                                              \/
				 ----------------	Subproblem (N - Quantity of the great coin that fit in the problem)
	*/	
	int i = 0;
	printf("%d\n", f(n));
	return 0;
}
