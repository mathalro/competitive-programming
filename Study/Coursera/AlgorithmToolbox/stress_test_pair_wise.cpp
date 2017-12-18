#include <iostream>		// input and output
#include <cstdlib> 		// random numbers
#include <vector>			// uso de vectors
#include <algorithm>  // uso do max
#include <unistd.h>   // uso do sleep

using namespace std;

long long slow(vector<int> v) {
	long long ans = -1;
	for (int i = 0; i < v.size(); i++) {
		for (int j = i+1; j < v.size(); j++) {
			ans = max(ans, (long long)v[i]*v[j]);
		}
	}
	return ans;
}

long long fast(vector<int> v) {
	int i1 = -1;
	for (int i = 0; i < v.size(); i++) {
		if (i1 == -1 || v[i1] < v[i]) {
			i1 = i;
		}
	}
	int i2 = -1;
	for (int i = 0; i < v.size(); i++) {
		if (i != i1 && (i2 == -1 || v[i2] < v[i])) {
			i2 = i;
		}
	}

	return (long long)v[i1] * v[i2];
}

int main () {
	while (1) {
		int n = rand() % 10 + 2;
		cout << n << endl;
		vector<int> a;
	
		for (int i = 0; i < n; i++) {
			int ai = rand() % 100000;
			cout << ai << ' ';
			a.push_back(ai);
		} cout << endl;
 
		long long ans1 = slow(a);
		long long ans2 = fast(a);

		if (ans1 != ans2) {
			cout << "Wrong answer: " << ans1 << ' ' << ans2 << endl;
			break;
		} else {
			cout << "OK\n";
		}
	}	

	return 0;
}
