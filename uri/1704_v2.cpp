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
int indice[maxn];
int n, h, qtd, v, t, i,j,total,contador, aux;
bool podeUsar;
		
void aumentar(int i){
	indice[i]++;
	for(j=i-1;j>0&&indice[j]!=0;j-=indice[j]){
		indice[i]+=(indice[j]);
	}
}

void novoIndice(int i, int v){
	if(i-indice[i]>0){
		if(indice[indice[i]]>0){
			novoIndice(indice[indice[i]], v);
		}
		else{
			contador++;
			qtd += v;
			aumentar(i);
		}
	}
}

int main() {
	while (scanf("%d %d", &n, &h) != EOF) {
		for (i = 1; i <= h; i++) indice[i]= 0;
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
			aux = q[i].t - indice[q[i].t];
			if (aux>=0) {
				contador++;
				qtd += q[i].v;
				aumentar(i);
			}else
				novoIndice(aux,v);
			if(contador==h)
				break;

		}

		q.clear();
		printf("%d\n", total-qtd);
	}

	return 0;
}
