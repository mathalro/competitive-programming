/*
 ================================
| uri 1252 - accept              |  
| theme: ordenacao personalizada |
| complexity: O(NlogN)           |
| time: 0.152s                   |	
 ================================
*/

#include <bits/stdc++.h>

using namespace std;

int n, m;

bool compare (long long a, long long b) {
  int ma = a%m, mb = b%m;
  if (ma == mb) {
    if ((a&1) && !(b&1)) {
      return true;
    } else if (!(a&1) && (b&1)) {
      return false;
    } else if (a&1 && b&1) {
      return a > b;
    } else if (!(a&1) && !(b&1)) {
      return a < b;
    }
  } else {
    return ma < mb;
  }
}

int main () {

  while (scanf("%d %d", &n, &m) && n) {
     vector<long long> v;
     for (int i = 0; i < n; i++) {
      long long a; scanf("%lld", &a);
      v.push_back(a);
    }

    sort(v.begin(), v.end(), compare);

    printf("%d %d\n", n, m);
    for (int i = 0; i < v.size(); i++) {
      printf("%lld\n", v[i]);
    }
  }

  printf("0 0\n");

	return 0;
}
