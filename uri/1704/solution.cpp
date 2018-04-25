/**
	Problema: Uri 1704
	accepted - 19/09/2016. Time 0.120ms
	Solução: 
			A ideia da solução é criar uma lista de tarefas ordenada decrescente com base no valor da tarefa. 
			Dpois a lista deve ser percorrida de forma a armazenar as tarefas a medida do possível. Para saber
			se é possível armazenar a tarefa é usado um vetor que salva uma tarefa de x horas em alguma posicao 
			vazia menor ou igual a x, caso não exista posição, soma-se o valor dessa tarefa no prejuizo.   
**/
#include <bits/stdc++.h>
#define maxn 1001

using namespace std;

struct tarefa {
	int v, t;
	tarefa() {}
	tarefa(int a, int b) : v(a), t(b) {}
	bool operator < (const tarefa &p) const {
		return v > p.v;
	}
};

vector<tarefa> q;
int vetor[maxn];

int main() {
	int n, h, qtd, v, t, i,j,total,contador;
	bool podeUsar;
	while (scanf("%d %d", &n, &h) != EOF) {
		for (i = 1; i <= h; i++) vetor[i] = 0;
		qtd = 0;
		total = 0;
		contador=0;
		for (i = 0; i < n; i++) {
			scanf("%d %d", &v, &t);
			total+=v;
			q.push_back(tarefa(v, t));
		}

		sort(q.begin(), q.end());
		for (i = 0; i < n; i++) {
			if (vetor[q[i].t]) {
				for (j = q[i].t-vetor[q[i].t]; j > 0; j-=vetor[j]) {
					if (!vetor[j]) {
						contador++;
						qtd += q[i].v;
						vetor[j]=1;
						break;
					}
					vetor[q[i].t]+=vetor[j];
					vetor[j]+=vetor[j-vetor[j]];
				}			

			}else {
				contador++;
				qtd += q[i].v;
				vetor[q[i].t]=1;
			}
			if(contador==h)
				break;

		}

		q.clear();
		printf("%d\n", total-qtd);
	}

	return 0;
}