#include <bits/stdc++.h>

#define inf 0x3f3f3f3f
#define mod 1e9+7
#define debug(var) cerr << #var << ':' << var << ' '
#define pb push_back
#define maxn 1009

typedef long long ll;
typedef long double ld;

using namespace std;

int bit[maxn][maxn];
int xDim, yDim, p, q;

void update(int x, int y, int val) {
    int y1;
    while (x <= xDim) {
        y1 = y;
        while (y1 <= yDim) {
            bit[x][y1] += val;
            y1 += (y1 & -y1);
		}

        x += (x & -x);
    }
}


int query(int x, int y) {
    int ans = 0;
    while (x > 0) {
        int y1 = y;
        while (y1 > 0) {
            ans += bit[x][y1];
            y1 -= (y1 & -y1);
        }
        x -= (x & -x); 
    }
    return ans;
}

int consulta(int x2, int y2, int x1, int y1) {
    return query(x2, y2) - query(x2, y1-1) -
            query(x1-1, y2) + query(x1-1, y1-1);
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    char a;

    while (cin >> xDim >> yDim >> p && xDim) {
        memset(bit, 0, sizeof bit);
        cin >> q;
        for (int i = 0; i < q; i++) {
            cin >> a;
            if (a == 'A') {
                int n, a, b;
                cin >> n >> a >> b;
                update(a+1, b+1, n);          
            } else {
                int a, b, c, d;
                cin >> a >> b >> c >> d;
                cout << consulta(max(c, a)+1, max(d, b)+1, min(a, c)+1, min(b, d)+1)*p << endl;
            }
        }

			cout << '\n';
    }

    return 0;
}

