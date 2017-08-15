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

int l[1000];
int r,k;

int pd[110][1010];

bool f(int x,int sum){
	if(sum ==k) return true;
	if(x >r) return false;
	if(pd[x][sum] !=-1) return pd[x][sum];

	if(sum + l[x]>k) return pd[x][sum] = f(x+1,sum);
	return pd[x][sum] = (f(x+1,sum) || f(x+1,sum+l[x]));
}

bool g(){
	for(int i = 0;i<k;i++){
		pd[r+1][i] = 0;
	}
	for(int i=1;i<=r+1;i++){
		pd[i][k] = 1;
	}
	for(int i =r;i>0;i--){
		for(int j=k-1;j>=0;j--){
			if(j+l[i] > k) pd[i][j] = pd[i+1][j];
			else pd[i][j] = (pd[i+1][j] || pd[i+1][j+l[i]]);
		}
	}
	return pd[1][0];
}

int main(){
	while(scanf("%d %d",&r,&k) != EOF){
		memset(l,0,sizeof l);
		for(int i=0;i<k;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			l[a]++;
			l[b]++;
		}
		printf(g()?"S\n":"N\n");
	}
}
