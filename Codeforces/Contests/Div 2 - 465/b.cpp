#include <bits/stdc++.h>

using namespace std;

struct point {
	int x, y, qd, cont;
	point() {}
	point(int _x, int _y) : x(_x), y(_y), qd(-1), cont(0) {}
};

int verifyQd(point p) {
	if (p.x < p.y) return 1;
	else if (p.y < p.x) return 0;
	else return -1;
} 

point inc(point p, char c) {
	if (c == 'R') p.x++;
	else p.y++;
	int tmp = verifyQd(p);

	if (p.qd == -1) {
		p.qd = tmp;
	} else if (tmp != -1 && tmp != p.qd) {
		p.cont++;
		p.qd = tmp;
	}

	return p;
}

int main () {
	
	int n; scanf("%d", &n);
	string s; cin >> s;

	point p = inc(point(0, 0), s[0]);

	for (int i = 1; i < s.size(); i++) {
		p = inc(p, s[i]);
	}

	printf("%d\n", p.cont);
	return 0;
}
