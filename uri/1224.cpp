#include <bits/stdc++.h>
#define maxn 10010

using namespace std; 

int cartao[maxn];
int n;
    
long long pd[maxn][2];

long long f2() {
	for (int i = 0; i < n-1; i++) {
		pd[i][1] = max( pd[i][0], pd[i+1][0] );
	}

	for (int j = 2; j < n; j++) {
		int l = j%2;
 		for (int i = 0; i < n - j; i++) {
 			int k = j + i;
 			pd[i][l] = max( min( pd[i][l], pd[i+1][l] ) + cartao[k], min( pd[i+2][l], pd[i+1][l] ) + cartao[i] );
 		}
 	}

 	return pd[0][1];
}


int main () {
    while (scanf("%d", &n)  != EOF) {
		for (int i = 0; i < n; i++) {
		    scanf("%lld", &cartao[i]);
			pd[i][0] = cartao[i];
		}
		
		printf("%lld\n", f2());
    }

    return 0;
}