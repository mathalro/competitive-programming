#include <iostream>

using namespace std;

int gcd(int a, int b) {
	while (a%b != 0) {
		int tmp = a;
		a = b;
		b = tmp%b;
	}
	return b;
}

int main () {

	int a, b; scanf("%d %d", &a, &b);

	printf("%d\n", gcd(a, b));
	
	return 0;
}
