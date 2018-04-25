#include <bits/stdc++.h>
#define N 26

using namespace std;

struct op {
	char a, b;
};

int k, m, n, tmpSum, maxSum;
int name[N], fav[N];
char pai[N];
string ans;

void input() {
	for (int i = 0; i < N; i++) pai[i] = (char)('a'+i);
	scanf("%d %d %d", &k, &m, &n);
	getchar();
	
	for (int i = 0; i < N; i++) pai[i] = '#';

	for (int i = 0; i < k; i++) {
		char c; scanf("%c", &c);
		fav[c-'a']++;
	}
	getchar();
	for (int i = 0; i < m; i++) {
		char c; scanf("%c", &c);
		name[c-'a']++;
		pai[c-'a'] = c;
		ans += c;
		tmpSum += (fav[c-'a'] != 0);
	}
	maxSum = tmpSum;
}

void solve() {
	getchar();
	int greater = -1;
	vector<op> operations;
	for (int i = 0; i < n; i++) {
		char a, b; scanf("%c %c", &a, &b);
		getchar();
		operations.push_back({a, b});
		int countA = (fav[a-'a'] != 0)*name[b-'a']  - (fav[b-'a'] != 0)*name[b-'a'];
		int countB = (fav[b-'a'] != 0)*name[a-'a']  - (fav[a-'a'] != 0)*name[a-'a'];

		tmpSum += countA + countB;

		swap(name[a-'a'], name[b-'a']);

		if (tmpSum > maxSum) {
			maxSum = tmpSum;
			greater = i;
		}
	}

	for (int i = 0; i <= greater; i++) {		
		char a = operations[i].a, b = operations[i].b;
		char tmpA = a, tmpB = b;

		while (pai[a-'a'] != tmpA && pai[a-'a'] != '#') a = pai[a-'a'];
		while (pai[b-'a'] != tmpB && pai[b-'a'] != '#') b = pai[b-'a'];

		pai[a-'a'] = tmpB;
		pai[b-'a'] = tmpA;
	}
	
	for (int i = 0; i < ans.size(); i++) {
		if (pai[ans[i]-'a'] != '#') {
			ans[i] = pai[ans[i]-'a'];
		}
	}
}

void print() {
	printf("%d\n", maxSum);
	printf("%s\n", ans.c_str());
}

int main () {
	input();
	solve();
	print();
}

