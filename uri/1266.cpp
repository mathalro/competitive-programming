#include <bits/stdc++.h>

using namespace std;

int conta(int zeros){
    return (zeros/2);
}

int main() {
	
	ios_base::sync_with_stdio(false);
	
    int n, atual, ans, k, f, primeira;

    while(cin >> n && n!= 0){
        ans = 0; k = 0;
        f = 0; primeira = 1;

        for (int i = 0; i < n; i++) {
            cin >> atual;
            if( atual ){
                if(primeira){
                    f = k;
                    primeira = 0;
                } else {  
					ans += conta(k);
				}
				k = 0;
            } else k++;
        }
        
        ans += conta(k+f);

        if(primeira) ans += k%2;
        cout << ans << endl;
    }
}