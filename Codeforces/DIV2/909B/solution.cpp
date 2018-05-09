#include <bits/stdc++.h>
#define maxn 101
#define inf 0x3f3f3f3f

using namespace std;

int v[maxn], n;

int solution1() {
	v[1] = 1;
	v[2] = 2;

	for (int i = 3; i <= n; i++) {
		v[i] = v[i-2] + i;
	}

	return v[n];
}

int solution2() {
	int maior = -inf;
	for (int i = 0; i <= n; i++) {
		maior = max(maior, (i+1)*(n-i));
	}
	return maior;
}

int solution3() {
	return (n/2+1)*ceil(n/2.0);
}

int main () {

	scanf("%d", &n);
	//printf("%d\n", solution1());
	//printf("%d\n", solution2());
	printf("%d\n", solution3());
}
