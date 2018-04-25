#include <bits/stdc++.h>
#define MAX 1000
#define inf 0x3f3f3f3f


using namespace std;

int g;
int c[12];
int n[12];

int pd[1100];
int vis[MAX], dis[MAX];

int bfs(int p) {
	queue<int> q; q.push(p);
	memset(vis, 0, sizeof vis);
	memset(dis, inf, sizeof dis);
	dis[p] = 0;	
	vis[p] = 1;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (u == 0) return dis[u];
		for (int i = 0; i < g; i++) {
			if (u-c[i] == 0) return dis[u]+1;
			int v = u-c[i]+n[i];
			if (v >= 0 && v <= MAX && c[i] <= u && !vis[v]) {
				q.push(v);
				dis[v] = dis[u] + 1;
				vis[v] = 1;
			}
		}
	}

	return dis[0];
}

int f(int cabecas){
    if(pd[cabecas] != -1) return pd[cabecas];   
    if(cabecas > MAX) return inf;
		pd[cabecas] = inf;
    for(int i=0;i<g;i++){
        if(c[i] == cabecas) return pd[cabecas]=1;
        else if(c[i]<cabecas) pd[cabecas] = min(pd[cabecas],f(cabecas-c[i]+n[i])+1);
    }
    return pd[cabecas];
}


int main () {
    while(scanf("%d",&g) && g){
        for(int i=0;i<g;i++){
            scanf("%d",c+i);        
        } 
        for(int i=0;i<g;i++){
            scanf("%d",n+i);        
        }
        memset(pd,-1,sizeof pd);
        int ans = f(100);
        if(ans >=inf)printf("cavaleiro morreu\n");
        else printf("%d\n",ans);
    }    
}
