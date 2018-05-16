#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+2;
int bit[N];

void update(int id, int val) {
	while (id <= N) {
		bit[id] += val;
		id += (id & -id);
	}
}

int query(int id) {
	int sum = 0;
	while (id > 0) {
		sum += bit[id];
		id -= (id & -id);
	}
	return sum;
}

int main () {
	int n;
	while (scanf("%d", &n) && n) {
		memset(bit, 0, sizeof bit);
		string s = "MENSAGEM: [";
		bool end = false;
		for (int i = 0; i < n; i++) {
			int op; scanf("%d", &op);
			if (!end) {
				if (op == 18) {
					int a, b, c; scanf("%d %d %d", &a, &b, &c);
					a++; b++;
					update(a, c);
					update(b+1, -c);
					i+=3;
				} else if (op == 42) {
					int a; scanf("%d", &a);
					a++;
					int val = query(a) - query(a-1);
					if (val >= 0) s += ('A'+val%26);
					else s += " ";
					i++;
				} else {
					end = true;
				}
			}
		}
		s += "]";
		cout << s << endl;
	}

	return 0;
}
