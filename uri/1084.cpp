#include <bits/stdc++.h>
#define DEL '*'

using namespace std;

int main () {
	
	int n, d, qtd;
	char ans[100009], num[100009];
	while (scanf("%d %d", &n, &d) && n) {
		scanf("%s", num);
		qtd = n-d;
		int p = 0;
		for (int i = 0; i < n && qtd; i++) {
			bool pega = true;
			int cont = 0;
			for (int j = i+1, k=n-qtd; j <= k && d > 0; j++, k--) {
				if ((num[i] < num[k] || num[i] < num[j]) && d > 0) {
					pega = false;
					d--;
					break;
				}
			}			
			if (pega) {
				ans[p++] = num[i];
				qtd--;
			}
		}
		for (int i = 0; i < p; i++) printf("%c", ans[i]);
		puts("");	
	}
	
	return 0;
}