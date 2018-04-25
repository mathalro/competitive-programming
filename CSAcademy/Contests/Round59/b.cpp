#include <bits/stdc++.h>
#define EPS 0.00000000000000000000000001

using namespace std;

int getNum(int g, int p) {
	int aux = 0;
	cout << p*g << endl;
	while (aux*100 <= p*g) {
		aux++;
	}
	aux--;
	return aux;
}

int getNum2(int g, int p) {
	int aux = 0;
	while (aux*100 < p*g) {
		aux++;
	}
	return aux;
}

int main () {

	int g1, p1, g2, p2; scanf("%d %d %d %d", &g1, &p1, &g2, &p2);

	int w1, w2;

	w1 = getNum2(g1, p1);
	w2 = getNum(g2, p2);

	cout << w1 << ' ' << w2 << endl;

	printf("%d\n", w2-w1);

	return 0;
}
