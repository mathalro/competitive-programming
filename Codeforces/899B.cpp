#include <bits/stdc++.h>

using namespace std;

int main () {

	int n; scanf("%d", &n);
	vector<int> v; 
	vector<int> ano, anoB, anos;

	ano.push_back(31);
	ano.push_back(28);
	ano.push_back(31);
	ano.push_back(30);
	ano.push_back(31);
	ano.push_back(30);
	ano.push_back(31);
	ano.push_back(31);
	ano.push_back(30);
	ano.push_back(31);
	ano.push_back(30);
	ano.push_back(31);

	anoB = ano;
	anoB[1] = 29;

	anos.insert(anos.end(), ano.begin(), ano.end());
	anos.insert(anos.end(), ano.begin(), ano.end());
	anos.insert(anos.end(), anoB.begin(), anoB.end());
	anos.insert(anos.end(), ano.begin(), ano.end());
	anos.insert(anos.end(), ano.begin(), ano.end());

	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		v.push_back(a);
	}

	
	for (int i = 0; i+n < anos.size(); i++) {
		bool tmp = true;
		for (int j = 0; j < n; j++) {
			if (v[j] != anos[j+i]) {
				tmp = false;
				break;
			}
		}	
		if (tmp) {
			printf("yes\n");
			return 0;
		}
	}

	printf("no\n");
	return 0;
}	
