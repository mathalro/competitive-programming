#include <bits/stdc++.h>
#define manx 1001

using namespace std;

int v[maxn];
int n;

int c1(int i) {
	int cont1 = 0, cont2 = 0;
	if (i == n) return cont1;
	while (i < n && v[i] != 2) {
		i++;
		cont1++;
	}
	if (i == n) return cont1;
	while (i < n && v[i] != 1) {
		i++;
		cont1++;
	}
	if (i == n) return cont1;
	while (i < n && v[i] != 2) {
		i++;
		cont2++;
	}
	if (i == n) return cont1;
	while (i < n && v[i] != 1) {
		i++;
		cont2++;
	}
	return cont1 + cont2;
}

int c2(int i) {
	int cont1 = 0, cont2 = 0;
	if (i == n) return cont1;
	while (i < n && v[i] != ) {}
}

int main () {

	scanf("%d", &n);

	for (int = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	int ans1 = 0;
	for (int i = 0; i < n; ) {
		while (i < n && v[i] != 1) i++;
		ans1 = max(ans1, c1(i));
		while (i < n && v[i] != 2) i++;
	}

	int ans2 = 0;
	
	
	return 0;
}
