/*

	struct no {
		int val, qtd; 
	};

	-1 -1  1  1  1  1  3 10 10 10


	 2  2  4  4  4  4  1  3  3  3
	 1  1  3  3  3  3  6  7  7  7

	 

                                                                 (1,10)
                                                                 [1,4]
                                (1,5)                                                      (6,10)
									              [1,2]                                                      [10,3]
					          (1,3)                  (4,5)                               (6,8)                   (9,10)
                    [-1,2]                 [2,1]                               [10,1]                  [10,2]   
                (1,2)    (3,3)        (4,4)     (5,5)                     (6,7)     (8,8)         (9,9)      (10,10)        
                [-1,2]   [1,1]        [1,1]     [1,1]                     [3,1]     [10,1]        [10,1]     [10,1]
 	          (1,1)   (2,2)                                            (6,6)     (7,7)
            [-1,1]  [-1,1]                                           [1,1]     [3,1]

*/


#include <bits/stdc++.h>
#define maxn 100009

using namespace std;

struct no {
	int val, qtd;
};

no st[4*maxn];
int v[maxn];
int start[maxn];
int count[maxn];	

void build(int no, int l, int r) {
	if (l == r) {
		st[no].val = v[i];
		st[no].qtd = 1;
		return;
	}
	int mid = (l+r)/2;
	build(2*no, l, mid);
	build(2*no+1, mid+1, r);

	no esq = st[2*no], dir = st[2*no+1];
	
	if (esq.val +  )
	
	
}

void query() {

}

int main () {
	
	int n, q;

	while (scanf("%d %d", &n, &q) > 1) {
		for (int i = 1; i <= n; i++) {
			scanf("%d", &v[i]);
		}

		
	}
	
	return 0;
}

















