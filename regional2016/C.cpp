#include <bits/stdc++.h>
#define maxn 40331
#define inf 0x3f3f3f3f

using namespace std;

struct aresta {
	int v, w;
	aresta(int a, int b) : v(a), w(b) {}
	bool operator < (const aresta &outro) const { return v > outro.v; }
};

vector<pair<int, int> > grafo[maxn];
vector<int> ini, fim;

int id, finalId;
int c1[] = {0,0,1,1,2,2,3,4,5,6}, c2[] = {1,4,2,5,3,6,7,5,6,7}, distancia[maxn];
map<vector<int>, int> ida;
map<int, vector<int> > volta;

int djkstra() {
	priority_queue<aresta> q;
	memset(distancia, inf, sizeof distancia);
	distancia[1] = 0;
	q.push(aresta(1, 0));

	while (!q.empty()) {
		aresta topo = q.top(); q.pop();
		int u = topo.v;
		
		for (int i = 0; i < grafo[u].size(); i++) {
			int v = grafo[u][i].first;
			if (distancia[v] > distancia[u] + grafo[u][i].second) {
				distancia[v] = distancia[u] + grafo[u][i].second;
				q.push(aresta(v, distancia[u] + grafo[u][i].second));
 			}
		}
	}

	return distancia[finalId];
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