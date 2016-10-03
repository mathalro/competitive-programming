#include <bits/stdc++.h>
#define maxn 40331
#define inf 0x3f3f3f3f

using namespace std;

vector<int> ini, fim, heap;

vector<pair<int, int> > grafo[maxn];
map<vector<int>, int> ida;
map<int, vector<int> > volta;

int id, finalId;
int c1[] = {0,0,1,1,2,2,3,4,5,6}, c2[] = {1,4,2,5,3,6,7,5,6,7}, distancia[maxn];

bool comp(int u, int v){
    return distancia[u] > distancia[v];
} 
 
void makeSet(){
    for(int i = 0; i < maxn; i++)
        distancia[i]=inf;
}

int djkstra(){
    int x,i=0;  
    makeSet();
    heap.push_back(1);
    distancia[1]=0;
    make_heap(heap.begin(),heap.end(),comp);
     
    while(!heap.empty()) {
        x=heap[0];
        pop_heap(heap.begin(), heap.end(), comp);
        heap.pop_back();
        if (x == finalId) return distancia[finalId];
        for(i=0; i < grafo[x].size();i++) {
             if(distancia[grafo[x][i].first] > grafo[x][i].second + distancia[x]) {
                distancia[grafo[x][i].first] = grafo[x][i].second + distancia[x];
                heap.push_back(grafo[x][i].first);
                push_heap(heap.begin(), heap.end(), comp);                
             }
        }
    }
}

void cria(vector<int> v, int idAtual) {
	int peso, adj;
	for (int i = 0; i < 10; i++) {
		if (v[c1[i]] != v[c2[i]]) {
			int peso = v[c1[i]] + v[c2[i]];
			vector<int> aux = v;
			swap(aux[c1[i]], aux[c2[i]]);
			if (ida.find(aux) == ida.end()) {
				ida[aux] = id;
				volta[id] = aux;
				if (aux == fim) {
					finalId = id;
				}
				adj = id++;
			}else {
				adj = ida[aux];
			}

			grafo[idAtual].push_back(make_pair(adj, peso));
		}
	}
}

int main() {
	int x; id = 1;

	for (int i = 0; i < 8; i++) {
		scanf("%d", &x);
		ini.push_back(x);
	}
	
	for (int i = 0; i < 8; i++) {
		scanf("%d", &x);
		fim.push_back(x);
	}

	if (ini == fim) {
		printf("0\n");
		return 0;
	}
	ida[ini] = 1;
	volta[1] = ini;
	id=2;
	for (int i = 1; i < id; i++) {
		cria(volta[i], i);
	}

	int res = djkstra();
	res == inf ? printf("0\n") : printf("%d\n", djkstra());

	return 0;
}