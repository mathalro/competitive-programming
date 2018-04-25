#include <bits/stdc++.h>
#define maxn 	100009
#define inf 0x3f3f3f3f

using namespace std;

int v[2*maxn];
int n, s, f;

int getHr(int ind) {
	int tmp = s-ind;
	return tmp > 0 ? tmp : tmp+n;
}

int main () {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
 
	scanf("%d %d", &s, &f);
	int jan = f-s;
	int ind = 0, cum = 0, maior = 0;
	
	for (int i = 0; i < jan; i++) {
		cum += v[i];
		if (i < jan-1) {
			v[i+n] = v[i];
		}
	}

	maior = cum;
	int minHr = getHr(0);
	for (int i = 1; i < n; i++) {
		int sum = cum - v[i-1] + v[i+jan-1];
		cum = sum;

		if (sum > maior) {
			maior = sum;
			ind = i;
			minHr = getHr(i);
		} else if (sum == maior && getHr(i) < minHr) {
			maior = sum;
			ind = i;
			minHr = getHr(i);
		}
	}

	printf("%d\n", minHr);

	return 0;
}
