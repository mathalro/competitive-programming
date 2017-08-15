#include <bits/stdc++.h>
#define maxn 1000009
#define inf 0x3f3f3f3f

using namespace std;

int lps[maxn];
string pat;

int dfs() {
	int n = pat.size()-1;
	return n-lps[n]+1;
}

void preProcess() {
	lps[0] = 0;
	int pt = 0;

	for (int i = 1; i < pat.size(); i++) {
		if (pat[i] == pat[pt]) {
			lps[i] = ++pt;
		} else if (pt != 0) {
			pt = lps[pt-1]; i--;
		} else {
			lps[i] = 0;
		}
	}
}

void pt() {
	for (int i = 0; i < pat.size(); i++) {
		printf("%d ", lps[i]);
	}puts("");
}

int main () {

	while (getline(cin, pat) && pat != ".") {
		if (pat == "") {
			printf("1\n");
			continue;
		}
		preProcess();
		printf("%d\n", pat.size()/dfs());
	}

	return 0;
}
