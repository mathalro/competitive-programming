#include <iostream>
#include <string>
#define N 66LL
#define N0 77LL	
#define inf 1000000000000000010LL

using namespace std;

string s[2][3] = {{"\"What are you doing at the end of the world? Are you busy? Will you save us?\"", 
									 "\"What are you doing at the end of the world? Are you busy? Will you save us?\"", 
									 "\"What are you doing at the end of the world? Are you busy? Will you save us?\""}, 
									{"\"What are you doing while sending ", "? Are you busy? Will you send ", "?\""}};

int n;
long long k;

long long exp(long long b, int e) {
	long long sum = 1;
	while (e > 0) {
		if (e&1) {
			sum *= b;
			if (sum <= 0 || sum > inf) {
				sum = inf;
				break;
			}
		}
		b *= b;
		e >>= 1;
	}
	return sum;
}

long long countChar(int n) {
	if (n < 0) return 0;
	long long p = exp(2, n);
	if (p == inf) return inf;
	long long ans = (p-1)*N + p*N0;
	return (ans <= 0 || ans > inf) ? inf : ans;
}

char getChar(long long cont, string s, int ini) {
	char c;
	for (int i = ini; i < s.size(); i++) {
		if (++cont == k) {
			c = s[i];
			break;
		}
	}
	return c;
}

char f(long long cont, int n) {
	char c;

	if (cont + s[n>0][0].size() >= k) {
		c = getChar(cont, s[n>0][0], 0);
	} else {
		cont += s[n>0][0].size();
		if (cont + countChar(n-1) >= k) {
			c = f(cont, n-1);
		} else {
			cont += countChar(n-1);
			if (cont + s[n>0][1].size() >= k) {
				c = getChar(cont, s[n>0][1], 0);
			} else {
				cont += s[n>0][1].size();
				if (cont + countChar(n-1) >= k) {
					c = f(cont, n-1);
				} else {
					cont += countChar(n-1);
					c = getChar(cont, s[n>0][2], 0);
				}
			}
		}
	}

	return c;
}

int main () {
	int q; scanf("%d", &q);
	while (q--) {
		scanf("%d %lld", &n, &k);
		if ((countChar(n)-2) < k) {
			cout << ".";
			continue;
		}
		long long cont = 0;
		char c;
		if (cont + s[n>0][0].size()-1 >= k) {
			c = getChar(cont, s[n>0][0], 1);
		} else {
			cont += s[n>0][0].size()-1;
			if (cont + countChar(n-1) >= k) {
				c = f(cont, n-1);
			} else {
				cont += countChar(n-1);
				if (cont + s[n>0][1].size() >= k) {
					c = getChar(cont, s[n>0][1], 0);
				} else {
					cont += s[n>0][1].size();
					if (cont + countChar(n-1) >= k) {
						c = f(cont, n-1);
					} else {
						cont += countChar(n-1);
						c = getChar(cont, s[n>0][2], 0);
					}
				}
			}
		}
		cout << c;
	}

	return 0;
}
