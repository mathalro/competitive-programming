#include <bits/stdc++.h>

using namespace std;

struct seg {
	int a, b;
	bool operator < (seg o) const {
		if (a == o.a) return b < o.b;
		return a < o.a;
	}
};

vector<seg> v;

int main () {

	int n; scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int a, b; scanf("%d %d", &a, &b);
		v.push_back({a, b});
	}

	sort(v.begin(), v.end());

	int i = 0;
	int cont = 0;
	vector<int> coords;
	while (i < n) {
		cont++;
		int right = v[i].b;
		i++;
		while (v[i].a <= right && i < n) {
			right = min(right, v[i].b);
			i++;
		}
		coords.push_back(right);
	}

	printf("%d\n", cont);
	for (int i = 0; i < coords.size(); i++) printf("%d ", coords[i]);
	puts("");

	return 0;
}
