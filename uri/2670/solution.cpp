#include <bits/stdc++.h>

using namespace std;

int main () {
	int a, b, c; scanf("%d %d %d", &a, &b, &c);
	printf("%d\n", 2*min(b + c*2, min(a + c, b + 2*a)));
}
