#include <bits/stdc++.h>

using namespace std;

list<char> l;
list<char>::iterator it;
bool verify(char a, char b) {
	for (it = l.begin(); it != l.end(); it++) {
		if (*it == a) return true;
		if (*it == b) return false;
	}
}

int main () {
	int n, k; scanf("%d %d", &n, &k);
	vector<string> v;
	set<char> S;
	int maior = 0;

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		v.push_back(s);		
		int a = s.size();
		maior = max(maior, a);
	}

	for (int k = 0; k < maior && v.size(); k++) {
		map<char, int> mapa;
		vector<char> w;
		char last = '#';

		for (int i = 0; i < v.size(); i++) {
			if (v[i].size()-1 >= k)	{
				char c = v[i][k];
				w.push_back(c);
				if (mapa.find(c) != mapa.end() && last != c) {
					printf("Impossible\n");
					return 0;
				} else {
					mapa[c]++;
					if (S.find(c) == S.end()) {
						S.insert(c);
						l.push_back(c);
					}
					last = c;
				}
			}
		}

		vector<int> toRem;
		for (int i = 0; i < v.size(); i++) {
			if (v[i].size()-1 >= k) {
				char c = v[i][k];
				if (mapa[c] < 2) {
					toRem.push_back(i);
				}
			}
		}

		for (int i = 0; i < toRem.size(); i++) {
			v.erase(v.begin()+toRem[i]);
		}
	}

	for (int i = 0; i < 26; i++) {
		if (S.find((char)('a'+i)) == S.end()) {
			printf("%c", (char)('a'+i));
		}
	}

	for (it = l.begin(); it != l.end(); it++) {
		printf("%c", *it);
	}puts("");

	return 0;
}
