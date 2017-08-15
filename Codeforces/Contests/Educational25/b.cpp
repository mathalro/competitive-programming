#include <bits/stdc++.h>
#define maxn 10

using namespace std;

int mat[maxn][maxn];

int main () {

	int n = 10;

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			char c;
			scanf("%c", &c);
			if (c != '\n') {
				mat[i][j] = c;
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) { 
			int cont = 0, foo = false; 
			for (int k = 0; k < 5; k++) {
				if (mat[i][j+k] == 'X') {
					cont++;
				}else if (mat[i][j+k] != '.') {
					foo = true;
				}
			}
			if (!foo && cont >= 4) {
				printf("YES\n");
				return 0;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			int cont = 0, foo = false;  
			for (int k = 0; k < 5; k++) {
				if (mat[k+j][i] == 'X') {
					cont++;
				}else if (mat[k+j][i] != '.') {
					foo = true;
				}
			}
			if (!foo && cont >= 4) {
				printf("YES\n");
				return 0;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int cont = 0, foo = false; 
			for (int k = 0; k < 5 && i+k < n && j+k < n; k++) {	
				//cout << i+k << ' ' << j+k << ' ' << mat[i+k][j+k] << endl;
				if (mat[i+k][j+k] == 'X') {
					cont++;
				} else if (mat[i+k][j+k] != '.') {
					foo = true;
				}
			}
			//cout << "Cont: " << cont << endl << endl;
			if (!foo && cont >= 4) {
				printf("YES\n");
				return 0;	
			}
			cont = 0; foo = false; 
			for (int k = 0; k < 5 && i-k > 0 && j-k > 0; k++) {
				if (mat[i-k][j-k] == 'X') {
					cont++;
				} else if (mat[i-k][j-k] != '.') {
					foo = true;
				}
			}
			if (!foo && cont >= 4) {
				printf("YES\n");
				return 0;	
			}
		}
	}

	printf("NO\n");

	return 0;
}
