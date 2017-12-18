#include <bits/stdc++.h>

using namespace std;

int main () {

	int n; scanf("%d", &n);

	int act = 1;
	vector<int> v;
	int cont = act;
	while (cont <= n) {
		v.push_back(act);
		act++;
		cont += act;
	}
	v[v.size()-1] += n-(cont-act);

	printf("%d\n", v.size());
	for (int i = 0; i < v.size(); i++) {
		printf("%d ", v[i]);
	}
	puts("");

	return 0;
}
