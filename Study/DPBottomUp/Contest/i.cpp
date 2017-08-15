#include <bits/stdc++.h>
#define maxn 2009

using namespace std;

int v[maxn], c[maxn], dp[maxn][maxn], mem[maxn][maxn];
int N, I, M, P;

void read() {
	for (int i = 0; i < M; i++) {
		scanf("%d", c+i);
	}

	for (int i = 1; i <= M; i++) {
		scanf("%d", v+i);
	}
}

void init() {
	for (int i = 0; i <= M; i++) {
		dp[N+1][i] = 0;
	}
}

void solve() {
  for (int i = N; i > 0; i--) {
		for (int j = 0; j <= M; j++) {
			if (j < M) {
				int a = c[j] + dp[i+1][j+1], b = P + c[0] - v[j] + dp[i+1][1];
				if (a < b) {
					dp[i][j] = a;
					mem[i][j] = 0;
				} else {
					dp[i][j] = b;
					mem[i][j] = 1;
				}
			} else {
				dp[i][j] = P + c[0] - v[j] + dp[i+1][1];
				mem[i][j] = 1;
			}
		}
	}
}

void print() {
	printf("%d\n", dp[1][I]);

	int j = I;
	bool foo = false;
	for (int i = 1; i <= N; i++) {
		if (mem[i][j]) {
			if (foo) {
				printf(" %d", i);
			} else {
				printf("%d", i);
			}
			foo = true;
			j = 1;
		} else {
			j++;
		}
	}

	if (!foo) {
		printf("0");
	}
	
	puts("");
}

int main () {

	while (scanf("%d %d %d %d", &N, &I, &M, &P) != EOF) {
		read();
		init();
		solve();
		print();
	}

	return 0;
}
