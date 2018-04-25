#include <bits/stdc++.h>

using namespace std;

class OrAndSumEasy {
	public:
	string isPossible(long long pairOr, long long pairSum); 
};

string OrAndSumEasy::isPossible(long long pairOr, long long pairSum) {
	int cont = 0;

	while (pairSum >= 1) {
		cont++;
		pairSum /= 2;
	}

	cout << cont << endl;

	if (pow(2, cont) < pairOr) return "Impossible";
	return "Possible";
}

int main () {

	OrAndSumEasy A;

	cout << A.isPossible(7,11) << endl;

}
