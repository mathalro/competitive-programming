#include <bits/stdc++.h>
#define mod 1000000007 
#define maxn 10001
 
using namespace std;

long long fat[maxn]; 
long long alpha[26];

int egcd(long long a, long long b) {
	long long x = 1, y = 0, xx = 0, yy = 1;
	while (b != 0) {
		long long q = a/b, r = a%b;
		long long m = x - q*xx, n = y - q*yy;
		a = b;
		b = r;
		x = xx; y = yy;
		xx = m; yy = n;
	}
	return x >= 0 ? x : x+mod;
}


int main() {
    
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    
		fat[0] = fat[1] = 1;
		for (int i = 2; i <= maxn; i++) {
			fat[i] = (fat[i-1]*i)%mod;
		}

    while (cin >> s) {
      int n = s.size();
			memset(alpha, 0, sizeof alpha);
			for (int i = 0; i < n; i++) alpha[s[i]-'A']++;
			long long num = fat[n];
			long long den = 1;
			for (int i = 0; i <= 26; i++) den = (den*fat[alpha[i]])%mod;
			
			cout << (num*egcd(den, mod))%mod << endl;
    }
 
    return 0;
}
