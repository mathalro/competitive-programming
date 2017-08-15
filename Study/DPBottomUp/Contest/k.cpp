#include <bits/stdc++.h>
#define maxn 60

using namespace std;

int n;
int v[maxn], ans;

void input() {
	scanf("%d", &n);
}

void solve() {

	for (int i = 0; i < n; i++) {
		v[i] = 0;
	}

	int i; bool foo = true;
	for (i = 1; foo; i++) {
		foo = false;
		for (int j = 0; j < n; j++) {
			if (v[j] == 0) {
				v[j] = i;
				foo = true;
				break;
			} else {
				int a = sqrt(v[j]+i);				
				if (a*a == v[j]+i) {
					v[j] = i;
					foo = true;
					break;
				}
			}
		}
	}

	ans = i-2;
}

void print() {
	printf("%d\n", ans);
}

int main () {

	int t; scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		input();
		solve();
		print();
	}

	return 0;
}
