#include <bits/stdc++.h>
#define maxn 45009
#define inf 0x3f3f3f3f
#define maxp 109
#define maxt 450

using namespace std;

int v[maxp], sum, n;
int dp[maxn+maxt], l[maxn+maxt], u[maxn+maxt];

void f() {
	dp[0] = 1;			// eu consigo o peso zero
  l[0] = 0;				// o menor para o peso zero e 0

  for (int i = 0; i < n; i++) {									// para todas as quantidades de pessoas
    for (int j = sum/2 + maxt; j >= 0; j--) {	  // considerando essa quantidade de pessoas, para todas as possiveis somas
      if (dp[j]) {												
        dp[j+v[i]] = 1;
				if (l[j+v[i]] > l[j]) {
          l[j+v[i]] = l[j];
        }
				if (u[j+v[i]] < u[j]) {
          u[j+v[i]] = u[j];
				}
      }
    }
	}
}


int main() {
	int t; scanf ("%d", &t);
	int aux = t;

  while (t--) {
    sum = 0; scanf("%d", &n);

    for (int i = 0; i < n; i++) { 
			scanf ("%d", v+i); 
			sum += v[i];
		}

    memset(dp, 0, sizeof dp);
    for (int i = 0; i < maxn/2 + maxt; i++ ) { 
			l[i] = inf; 
			u[i] = 0;
		}
	
		f();

    for (int i = sum/2; i >= 0; i--) {
        if (dp[i] && ((l[i] <= n/2 && u[i] >= n/2) || (l[i] <= n/2 + n%2 && u[i] >= n/2 + n%2))) {
          printf("%d %d\n", i, sum - i); break;
        }
    }

    if (t != aux && t) {
			puts("");
		}
  }

  return 0;
}

