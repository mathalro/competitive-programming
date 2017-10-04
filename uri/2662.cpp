#include <bits/stdc++.h>
#define maxn 100001

using namespace std;

map<int, string> notas;
int escala[] = {2, 2, 1, 2, 2, 2, 1};
set<string> S[13];
vector<string> v;

int main () {

	notas[1] = "do";
	notas[2] = "do#";
	notas[3] = "re";
	notas[4] = "re#";
	notas[5] = "mi";
	notas[6] = "fa";
	notas[7] = "fa#";
	notas[8] = "sol";
	notas[9] = "sol#";
	notas[10] = "la";
	notas[11] = "la#";
	notas[12] = "si";	

	int n; scanf("%d", &n);

	for (int i = 1; i < 13; i++) {
		int nota = i;
		for (int j = 0; j < 7; j++) {
			S[i].insert(notas[nota]);
			nota += escala[j];
			nota = nota%13 + nota/13;
		}
	}

	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		v.push_back(notas[(a%13)+a/13]);
	}

	for (int i = 1; i < 13; i++) {
		bool desafinado = false;
		for (int j = 0; j < v.size(); j++) {
			if (S[i].find(v[j]) == S[i].end()) {
				desafinado = true;
				break;
			}
		}
		if (!desafinado) {
			printf("%s\n", notas[i].c_str());
			return 0;
		}
	}

	printf("desafinado\n");
	return 0;
}
