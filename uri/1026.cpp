/**
	Problema: Carrega ou não carrega
	accepted: 0.40 ms
	Solução: A operação de "soma" em questão é um XOR, que ja é implementado pelo processador. 
**/
#include <iostream>
#include <cstdio>

int main () {
  	unsigned int n, m;
	while(scanf("%u %u", &n, &m) != EOF)
		printf("%u\n", (n ^ m));
	return 0;
}