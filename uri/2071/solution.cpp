#include <bits/stdc++.h>
#define maxn 100001
#define inf 0x3f3f3f3f

using namespace std;

struct No {
	long long intervalSum, preffixSum, suffixSum, maxSum;
	long long intervalQtd, preffixQtd, suffixQtd, maxQtd;
	No() {}
	No(int _1, int _2, int _3, int _4, int _5, int _6, int _7, int _8) {
		intervalSum = _1;
		preffixSum = _2;
		suffixSum = _3;
		maxSum = _4;
		intervalQtd = _5;
		preffixQtd = _6;
		suffixQtd = _7;
		maxQtd = _8;
	}

	No friend operator+(No lhs, No rhs) {
		
		No novo;

		novo.intervalSum = lhs.intervalSum + rhs.intervalSum;
		novo.intervalQtd = lhs.intervalQtd + rhs.intervalQtd;

		if (lhs.preffixSum > lhs.intervalSum + rhs.preffixSum) {
			novo.preffixSum = lhs.preffixSum;
			novo.preffixQtd = lhs.preffixQtd;
		} else if (lhs.preffixSum == lhs.intervalSum + rhs.preffixSum) {
			if (lhs.preffixQtd > lhs.intervalQtd + rhs.preffixQtd) {
				novo.preffixSum = lhs.preffixSum;
				novo.preffixQtd = lhs.preffixQtd;
			} else {
				novo.preffixSum = lhs.intervalSum + rhs.preffixSum;
				novo.preffixQtd = lhs.intervalQtd + rhs.preffixQtd;				
			}
		} else {
			novo.preffixSum = lhs.intervalSum + rhs.preffixSum;
			novo.preffixQtd = lhs.intervalQtd + rhs.preffixQtd;
		}

		if (rhs.suffixSum > rhs.intervalSum + lhs.suffixSum) {
			novo.suffixSum = rhs.suffixSum;
			novo.suffixQtd = rhs.suffixQtd;
		} else if (rhs.suffixSum > rhs.intervalSum + lhs.suffixSum) {
			if (rhs.suffixQtd > rhs.intervalQtd + lhs.suffixQtd) {
				novo.suffixSum = rhs.suffixSum;
				novo.suffixQtd = rhs.suffixQtd;
			} else {
				novo.suffixSum = rhs.intervalSum + lhs.suffixSum;
				novo.suffixQtd = rhs.intervalQtd + lhs.suffixQtd;
			}
		} else {
			novo.suffixSum = rhs.intervalSum + lhs.suffixSum;
			novo.suffixQtd = rhs.intervalQtd + lhs.suffixQtd;
		}

		if (lhs.maxSum > rhs.maxSum) {
			if (lhs.maxSum > rhs.preffixSum + lhs.suffixSum) {
				novo.maxSum = lhs.maxSum;
				novo.maxQtd = lhs.maxQtd;
			} else if (lhs.maxSum == rhs.preffixSum + lhs.suffixSum) {
				if (lhs.maxQtd > rhs.preffixQtd + lhs.suffixQtd) {
					novo.maxSum = lhs.maxSum;
					novo.maxQtd = lhs.maxQtd;
				} else {
					novo.maxSum = rhs.preffixSum + lhs.suffixSum;
					novo.maxQtd = rhs.preffixQtd + lhs.suffixQtd;
				}
			} else {
				novo.maxSum = rhs.preffixSum + lhs.suffixSum;
				novo.maxQtd = rhs.preffixQtd + lhs.suffixQtd;
			}
		} else if (lhs.maxSum == rhs.maxSum) {
			if (lhs.maxQtd > rhs.maxQtd) {
				if (lhs.maxSum > rhs.preffixSum + lhs.suffixSum) {
					novo.maxSum = lhs.maxSum;
					novo.maxQtd = lhs.maxQtd;
				} else if (lhs.maxSum == rhs.preffixSum + lhs.suffixSum) {
					if (lhs.maxQtd > rhs.preffixQtd + lhs.suffixQtd) {
						novo.maxSum = lhs.maxSum;
						novo.maxQtd = lhs.maxQtd;
					} else {
						novo.maxSum = rhs.preffixSum + lhs.suffixSum;
						novo.maxQtd = rhs.preffixQtd + lhs.suffixQtd;
					}
				} else {
					novo.maxSum = rhs.preffixSum + lhs.suffixSum;
					novo.maxQtd = rhs.preffixQtd + lhs.suffixQtd;
				}
			} else {
				if (rhs.maxSum > rhs.preffixSum + lhs.suffixSum) {
					novo.maxSum = rhs.maxSum;
					novo.maxQtd = rhs.maxQtd;
				} else if (rhs.maxSum == rhs.preffixSum + lhs.suffixSum) {
					if (rhs.maxQtd > rhs.preffixQtd + lhs.suffixQtd) {
						novo.maxSum = rhs.maxSum;
						novo.maxQtd = rhs.maxQtd;
					} else {
						novo.maxSum = rhs.preffixSum + lhs.suffixSum;
						novo.maxQtd = rhs.preffixQtd + lhs.suffixQtd;
					}
				} else {
					novo.maxSum = rhs.preffixSum + lhs.suffixSum;
					novo.maxQtd = rhs.preffixQtd + lhs.suffixQtd;
				}
			}
		} else {
			if (rhs.maxSum > rhs.preffixSum + lhs.suffixSum) {
				novo.maxSum = rhs.maxSum;
				novo.maxQtd = rhs.maxQtd;
			} else if (rhs.maxSum == rhs.preffixSum + lhs.suffixSum) {
				if (rhs.maxQtd > rhs.preffixQtd + lhs.suffixQtd) {
					novo.maxSum = rhs.maxSum;
					novo.maxQtd = rhs.maxQtd;
				} else {
					novo.maxSum = rhs.preffixSum + lhs.suffixSum;
					novo.maxQtd = rhs.preffixQtd + lhs.suffixQtd;
				}
			} else {
				novo.maxSum = rhs.preffixSum + lhs.suffixSum;
				novo.maxQtd = rhs.preffixQtd + lhs.suffixQtd;
			}
		}

		return novo;	
	}
};


int v[maxn];
No st[4*maxn];

void build(int no, int l, int r) {
	if (l == r) {
		st[no] = No(v[l], v[l], v[l], v[l], 1, 1, 1, 1);
		return;
	}
	int mid = (l+r)/2;
	build(2*no, l, mid);
	build(2*no+1, mid+1, r);
	
	st[no] = st[2*no] + st[2*no+1];
}

No query(int no, int l, int r, int ql, int qr) {
	if (l > qr || r < ql) return No(-inf, -inf, -inf, -inf, -inf, -inf, -inf, -inf);
	if (l >= ql && r <= qr) return st[no];
	int mid = (l+r)/2;

	No a = query(2*no, l, mid, ql, qr);
	No b = query(2*no+1, mid+1, r, ql, qr);
	return a + b;
}

int main () {
	int t; scanf("%d", &t);

	while (t--) {
		int n; scanf("%d", &n);

		for (int i = 1; i <= n; i++) {
			scanf("%d", &v[i]);
		}

		for (int i = 0; i <= 4*n; i++) st[i] = No(0, 0, 0, 0, 0, 0, 0, 0);
		build(1, 1, n);

		int q; scanf("%d", &q);
	
		for (int i = 0; i < q; i++) {
			int a, b; scanf("%d %d", &a, &b);
			No  ans = query(1, 1, n, a, b);
			printf("%d %d\n", ans.maxSum, ans.maxQtd);
		}
	}

	return 0;
}
