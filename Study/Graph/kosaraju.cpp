/*

*/

#include <bits/stdc++.h>
#define maxn 100009

using namespace std;

vector<long long> g1[maxn], g2[maxn], divs, S;
int visitado[maxn];
int grauEntrada[maxn];

void dfs(int pai) {
	visitado[pai] = 1;
	for (int i = 0; i < g1[pai].size(); i++) {
		if (!visitado[g1[pai][i]]) {
			dfs(g1[pai][i]);
		}
	}
	S.insert(S.begin(), pai);
}

long long dfsInv(int pai) {
	visitado[pai] = 1;
	long long cont = 1;
	for (int i = 0; i < g2[pai].size(); i++) {
		if (!visitado[g2[pai][i]]) {
			cont += dfsInv(g2[pai][i]);
		}
	}

	return cont;
}

long long lcm(long long a, long long b) {    
	return (a*b)/_gcd(a, b);
}

int main () {

	int n; scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		int a; scanf("%d", &a);
		g1[i].push_back(a);
		g2[a].push_back(i);
		grauEntrada[a]++;

		if (grauEntrada[a] > 1) {
			printf("-1\n");
			return 0;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (!visitado[i]) {
			dfs(i);
		}
	}

	memset(visitado, 0, sizeof visitado);
	for (int i = 0; i < S.size(); i++) {
		if (!visitado[S[i]]) {
			divs.push_back(dfsInv(S[i]));
		}
	}

	long long ans;
	if (divs.size() > 1) {
		ans = lcm(divs[0], divs[1]);
		for (int i = 2; i < divs.size(); i++) {
			ans = lcm(ans, divs[i]);
		}
	} else {
		ans = divs[0];
	}

	printf("%llu\n", ans);
	
	return 0;
}	
