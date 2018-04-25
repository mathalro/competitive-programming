#include <bits/stdc++.h>
#define maxn 91

using namespace std;

vector<int> bola;
int possib[maxn];

int main () {

	int n, b;

	while(scanf("%d %d", &n, &b)) {
		if ( n+b == 0 ) {
			break;
		}

		for (int i = 0; i <= n; i++) {
			possib[i] = 0;
		}

		for (int i = 0; i < b; i++) {
			int ball;
			scanf("%d", &ball);
			bola.push_back(ball);
		}

		if ( b == n+1 ) {
			printf("Y\n");
		} else {
			int cont = 1;
			for (int i = 0; i < b; i++) {
				for (int j = i+1; j < b; j++) {
					int val = abs(bola[i]-bola[j]);
					if ( !possib[val] ) {
						cont++;
						possib[val] = 1;
					}
				}
				if ( cont == n+1 ) {
					printf("Y\n");
					break;
				}
				if ( i == b-1 ) {
					printf("N\n");
				}
			}
		}

		bola.clear();

	}


	return 0;
}