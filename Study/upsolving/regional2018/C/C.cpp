#include <bits/stdc++.h>

using namespace std;

struct line {
	int c1, c2;
	bool operator<(line o) const {
		return c1 < o.c1;
	}
};

vector<line> lh, lv;

long long ans;

vector<line> mergeSort(vector<line> v) {
	if (v.size() == 1) return v;
	
	vector<line> aux1, aux2;

	for (int i = 0; i < v.size(); i++) {
		if (i < v.size()/2) {
			aux1.push_back(v[i]);
		} else {
			aux2.push_back(v[i]);
		}
	}

	aux1 = mergeSort(aux1);
	aux2 = mergeSort(aux2);

	vector<line> aux3;
	
	int i = 0, j = 0;
	while (aux3.size() < aux1.size() + aux2.size()) {
		if (i == aux1.size() || (j < aux2.size() && aux2[j].c2 < aux1[i].c2)) {
			aux3.push_back(aux2[j]);
			j++;
			ans += aux1.size()-i;
		} else {
			aux3.push_back(aux1[i]);
			i++;
		}
	}

	return aux3;
}

int main () {

	int x, y; scanf("%d %d", &x, &y);
	long long h, v; scanf("%lld %lld", &h, &v);

	for (int i = 0; i < h; i++) {
		int y1, y2; scanf("%d %d", &y1, &y2);
		lh.push_back({y1, y2});
	}

	for (int i = 0; i < v; i++) {
		int x1, x2; scanf("%d %d", &x1, &x2);
		lv.push_back({x1, x2});
	}

	
	ans = 0;
	sort(lh.begin(), lh.end());
	mergeSort(lh);
	sort(lv.begin(), lv.end());
	mergeSort(lv);

	printf("%lld\n", ans + h*v + h + v + 1);

	return 0;
}
