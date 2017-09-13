#include <bits/stdc++.h>
#define maxm 100010
#define maxt 10010
using namespace std;

int musica[maxm];
int trecho[maxt];

int m, t;


bool kmp(const vector<int> &needle, const vector<int> &haystack) {
  // Precompute border function
  int m = needle.size();
  vector<int> border(m);
  border[0] = 0;
  for (int i = 1; i < m; ++i) {
    border[i] = border[i - 1];
    while (border[i] > 0 and needle[i] != needle[border[i]]) {
       border[i] = border[border[i] - 1];
    }
    if (needle[i] == needle[border[i]]) border[i]++;
  }

  // Now the actual matching
  int n = haystack.size();
  int seen = 0;
  for (int i = 0; i < n; ++i){
    while (seen > 0 and haystack[i] != needle[seen]) {
      seen = border[seen - 1];
    }
    if (haystack[i] == needle[seen]) seen++;

    if (seen == m) {
      return true;
      seen = border[m - 1];
    }
  }
  return false;
}


int main () {

	map<string, char> nota;
	map<int, char> mapa;

	nota["A"] = 0;
    nota["A#"] = 1;
    nota["Bb"] = 1;
	nota["B"] = 2;
	nota["Cb"] = 2;
	nota["B#"] = 3;
	nota["C"] = 3;
	nota["Db"] = 4;
	nota["C#"] = 4;
	nota["D"] = 5;
	nota["Eb"] = 6;
	nota["D#"] = 6;
	nota["E"] = 7;
	nota["Fb"] = 7;
	nota["F"] = 8;
	nota["E#"] = 8;
	nota["F#"] = 9;
	nota["Gb"] = 9;
	nota["G"] = 10;
	nota["Ab"] = 11;
	nota["G#"] = 11;


	mapa[0] = 'a';
	mapa[1] = 'b';
	mapa[2] = 'c';
	mapa[3] = 'd';
	mapa[4] = 'e';
	mapa[5] = 'f';
	mapa[6] = 'g';
	mapa[7] = 'h';
	mapa[8] = 'i';
	mapa[9] = 'j';
	mapa[10] = 'k';
	mapa[11] = 'l';
	mapa[-1] = 'm';
	mapa[-2] = 'n';
	mapa[-3] = 'o';
	mapa[-4] = 'p';
	mapa[-5] = 'q';
	mapa[-6] = 'r';
	mapa[-7] = 's';
	mapa[-8] = 't';
	mapa[-9] = 'u';
	mapa[-10] = 'v';
	mapa[-11] = 'x';

	while(scanf("%d %d", &m, &t)) {

		if ( m + t == 0 ) {
			break;
		} 

		string s;

		for (int i = 0; i < m; i++) {
			cin >> s;
			musica[i] = nota[s];
		}
		for (int i = 0; i < t; i++) {
			cin >> s;
			trecho[i] = nota[s];	
		}

		for (int i = 1; i < m; i++) {
			mus += mapa[musica[i]-musica[i-1]];
		}
		mus += mapa[musica[0]-musica[m-1]];

		for (int i = 1; i < t; i++) {
			tre += mapa[trecho[i]-trecho[i-1]];
		}

		mus += mus;

		if ( mus.find(tre) != -1 ) {
			printf("S\n");
		}else {
			printf("N\n");
		}

	}

	return 0;
}