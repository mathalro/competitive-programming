#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
 
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef set<int> si;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<string,int> msi;
typedef map<int,int> mi;
 
string s1[110],s2[110];
int pd[110][110],camada;
 
 
 
int edit(int m,int n){
    if(!m) return n*150;
    if(!n) return m*30;
    
		//if(pd[m][n] != -1) return pd[m][n];
    if(s1[m-1] == s2[n-1]) return pd[m][n]= edit(m-1,n-1);
    int insert = edit(m,n-1)+150;
    int remove = edit(m-1,n)+30;
    int replace = edit(m-1,n-1)+60;
    return pd[m][n]=(min(min(remove,replace),insert));
}
 
int main(){
    int t;
    scanf("%d",&t);
    getchar();
    for(int caso =1;caso<=t;caso++){
        int n,m,r;
        scanf("%d",&r);
        scanf("%d",&m);
        getchar();
        for(int i =0;i<m;i++){
            string aux;
            cin >> aux;
            s1[i] = aux;
        }
        scanf("\n%d",&n);
        getchar();
        for(int i =0;i<n;i++){
            string aux;
            cin >> aux;
            s2[i] = aux;
        }
	
        memset(pd,-1,sizeof pd);
        double res= (double)edit(m,n);
        res /= 60;
        res *= r;
        camada =0;
        printf("Caso #%d: R$%.2f\n",caso,res );
        //printf("Caso #%d: %.2f\n",caso, (((double)edit(m,n))/60)  );
    }
}
