#include <bits/stdc++.h>
#define maxn 21
#define inf 0x3f3f3f3f

using namespace std;

map<int, int> sequencia;
int aluno[maxn];
int pd[maxn];

int ssc(int n) {
	for (int m = 1; m <= n; m++) {
		pd[m] = 1;
		for(int i = m-1; i > 0; i--) {
			if (sequencia[aluno[i]] <= sequencia[aluno[m]] && pd[i] + 1 > pd[m]) {
				pd[m] = pd[i] + 1;
			}
		}
	}
	
	int maior = -inf;
	for (int i = 1; i <= n; i++) {
		maior = max(maior, pd[i]);
	}

	return maior;
}

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		sequencia[i] = x;
	}

	int x;
	while (scanf("%d", &x) != EOF) {
		aluno[x] = 1;
		for (int i = 2; i <= n; i++) {
			scanf("%d", &x);
			aluno[x] = i;
		}

		memset(pd, -1, sizeof pd);
		printf("%d\n", ssc(n));
	}

	return 0;
}