	#include <bits/stdc++.h>
#define maxn 520
#define inf 0x3f3f3f3f
 
using namespace std;
 
struct point {
    int x, y;
    bool operator <(const point &outro) const {
        if (y < outro.y) return true;
        if (y == outro.y && x < outro.x) return true;
        return false;
    }
};
 
point v[maxn];

double dist(point p, point q) {
    return (p.x-q.x)+(p.y-q.y);
}
 
int orientation(point p, point i, point q) {
    int val = (q.y-i.y)*(i.x-p.x) - (i.y-p.y)*(q.x-i.x);
    if (!val) {
				int d1 = dist(p, i);
				int d2 = dist(p, q);

				if (d1 < d2) {
					return 3;
				}
				return 0;      
    }
    return (val > 0) ? 1 : 2;
}
 
int main () {
    int k; scanf("%d", &k);
    printf("%d\n", k);
    while (k--) {
        int n; scanf("%d", &n);
        vector<int> hull;
        scanf("%d %d", &v[0].x, &v[0].y);
        int l = 0;
        for (int i = 1; i < n; i++) {
            scanf("%d %d", &v[i].x, &v[i].y);
            if (v[l].y > v[i].y || (v[l].y == v[i].y && v[l].x > v[i].x)) {
                l = i;
            }
        }
 
        int p = l;
        while (1) {
						if (hull.size() > 1) {
								int a = hull.size()-1;
								int val = orientation(v[hull[a-1]], v[hull[a]], v[p]);
								if (val == 3) {
									hull.pop_back();
									hull.push_back(p);
								} else if (val == 2) {
									hull.push_back(p);
								} 
						} else  {
           			hull.push_back(p);
						}
            int q = (p+1)%n;
            for (int i = 0; i < n; i++) {
                int val = orientation(v[p], v[i], v[q]);
                if (val == 2) q = i;
            }
 
            p = q;
            if (p == l) break;
        }

        hull.push_back(l);
        printf("%ld\n", hull.size() );
        for (int i = hull.size()-1; i >= 0; i--) {
					if (hull[i] != -1) {
        		printf("%d %d\n", v[hull[i]].x, v[hull[i]].y);
					}        
				}
       
        if (k) {
            int a;
            scanf("%d", &a);
            printf("-1\n");
        }
    }
 
    return 0;
}
