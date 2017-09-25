#include <bits/stdc++.h>	
#define maxn 100009


using namespace std;
string s; 

struct noInicial {
	vector <no*> filhos;
	char letra;
};

struct no {
	no* filhos;
	char letra;
};

bool lido[27];
no* inicios[26];
bool pesos[maxn*26];
int contador;

no* build(int i);



no* continuar(int i){
	printf("C1: %d\n", i); 
	no* novo = (no*)malloc(sizeof (no) * 1);
	novo->letra = s[i];
	i++;
	printf("C2: %d\n", i); 
	if(i >= s.size()){
		printf("C2.1: %d\n", i); 
 		return novo;
	}
	printf("C3: %d\n", i); 
	if(lido[s[i]-'a']){
		printf("C4: %d\n", i); 
		no* filho = continuar(i);
		printf("C4.1: %d\n", i); 
		if(filho->filhos.size()){
			inicios[s[i]-'a']->filhos.push_back(filho->filhos[0]);
		}
		printf("C4.2: %d %c\n", i, filho->letra);
		novo->filhos = filho;
	}else{
		printf("C5: %d\n", i); 
		no* filho = build(i);
		printf("C5.1: %d\n", i); 
		novo->filhos = filho;
	}
	printf("C6: %d\n", i); 
	return novo;
}

no* build(int i) {
	printf("B1: %d\n", i); 
	lido[s[i]-'a'] = true;
	noInicial* raiz = (noInicial*)malloc(sizeof (noInicial) * 1);	
	inicios[s[i]-'a']=raiz;
	raiz->letra = s[i];
	i++;
	printf("B2: %d\n", i); 
	if(i >= s.size()){
 		return raiz;
	}
	printf("B3: %d\n", i); 
	if(lido[s[i]-'a']){
		printf("B4: %d\n", i); 
		no* filho = continuar(i);
		printf("B4.1: %d\n", i); 
		if(filho->filhos.size()){
			inicios[s[i]-'a']->filhos.push_back(filho->filhos[0]);	
		}
		raiz->filhos = filho;
	}else{
		printf("B5: %d\n", i); 
		no* filho = build(i);
		printf("B5.1: %d\n", i); 
		raiz->filhos = filho;
	}
	printf("B6: %d\n", i); 
	return raiz;
}


void percorrerRec(no* atual, int soma){
	int i = atual->filhos.size();
	soma += atual->letra-'a'+1;
	if(!pesos[soma]){
		pesos[soma]=true;
		contador++;	
	}
	if(i)
		percorrerRec(atual->filhos[i-1], soma);
}

void percorrer(){
	for(int i=0; i < 26; i++){
			if(lido[i]){
				no* atual = inicios[i];
				for(int j = 0; j < atual->filhos.size(); j++) {
					if(!pesos[atual->letra-'a'+1]){
						pesos[atual->letra-'a'+1]=true;
						contador++;	
					}
					percorrerRec(atual->filhos[j], (int)(atual->letra-'a'+1));
				}					
			}
	}
}


int main () {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	no* comeco = (no*)malloc(sizeof (no) * 1);	
	cin >> s;

	for(int i = 0; i < 26; i++)	
		inicios[i] = (noInicial*)malloc(sizeof (noInicial) * 1);
	if(s.size()){
		comeco->filhos.push_back(build(0));
	}
	percorrer();
	cout<<contador<<endl;	
	return 0;
}
