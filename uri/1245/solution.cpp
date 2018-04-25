#include <bits/stdc++.h>
#define maxn 31

using namespace std;

int botaD[maxn];
int botaE[maxn];

int main () {
	
	int n, ans;
	while(scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			int num;
			char pe;
			scanf("%d %c", &num, &pe);
			if (pe == 'D') {
				botaD[num-30]++;
			} else {
				botaE[num-30]++;
			}
		}
		ans = 0;
		for (int i = 0; i < 31; i++) {
			ans += min(botaD[i], botaE[i]);
			botaD[i] = botaE[i] = 0;
		}
		
		printf("%d\n", ans);
	}
	
	return 0;
} 