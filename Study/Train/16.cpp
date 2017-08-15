#include <bits/stdc++.h>
#define maxn 109

using namespace std;

int sMax[maxn];
int student[maxn][maxn];

int main () {

	string s;
	int a, b, c;
	getline(cin, s);
	stringstream ss(s);
	ss >> a >> b >> c;
	cout << a << ' ' << b << ' ' << c << endl;


	return 0;
	int n, m; scanf("%d %d", &n, &m);
	getchar();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c; scanf("%c", &c);
			int val = c-'0';
			student[i][j] = val;
			sMax[j] = max(sMax[j], val);
		}
		getchar();
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (sMax[j] == student[i][j]) {
				ans ++;
				break;
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}
