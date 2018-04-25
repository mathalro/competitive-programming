/*
	A solucao do problema passa pela verificacao de que sempre existe solucao para as configuracoes de entrada especificadas pelo problema, sempre havera uma distribuicao possivel na qual todas as criancas recebem a mesma quantidade de doces.

	Sabendo que o numero de criancas e igual a C, precisamos de uma soma de doces cujo valor seja multiplo de C, ou seja, um valor X, cujo resto da divisao por X/C seja igual a zero.

	Dado um conjunto S de numeros e um numero C pelo qual queremos dividir tais numeros. Caso a soma dos elementos de S resulta em um número divisível por C, a soma dos restos da divisão de cada numero em S por C é também divisível por C. Essa é uma propriedade de adicao modular: (A+B)modC=(AmodC+BmodC)modC. Pode ser verificado em: https://www.khanacademy.org/computing/computer-science/cryptography/modarithmetic/a/modular-addition-and-subtraction

	Com base na quantidade C de criancas, no conjunto S de vizinhos e na propriedade de soma dos restos, devemos então encontrar uma forma de garantir que teremos solução para nosso problema. Para isso podemos tentar verificar que dentre todas as possibilidades possíveis de soma, uma sempre será divisível por C. Ou seja.

Seja S = {a1, a2, a3, a4, a5 ... aN}

(a1)         				%C = a
(a1 + a2)    				%C = b
(a1 + a3)    				%C = c
(a1 + ... + aN)     %C = d
(a1 + a2 + a3)			%C = e

Se tentarmos todas as possibilidades de soma, veremos que existem N! possibilidades. Ou seja, teremos N! possíveis resultados. No entanto, como estamos utilizando o mod da divisão por C, os únicos resultados possíveis estão entre 0 e C-1. Quer dizer que, caso tenhamos mais do que C possibilidades de soma, um dos resultados irá se repetir (PRINCIPIO DA CASA DOS POMBOS). A repetição de resultados significa que ao subtrairmos um resultado do outro, o resto da divisão será igual a zero. Ou seja, se visitando um grupo de visinhos S1 a quantidade de doces que restam for A e visitando um grupo de visinhos S2 a quantidade de doces restantes também for A, ao subtrairmos um grupo do outro, a quantidade de doces restantes será zero (mais uma vez utilizamos propriedade de mod), e voalá, teremos nossa resposta. 

No entanto, apenas isto não é suficiente para resolver nosso problema. Precisamos encontrar uma forma simples de verificar e subtrair estas somas umas das outras. Para isso, podemos utilizar um dado importantíssimo que o problema nos da: N >= C, ou seja, a quantidade de visinhos é maior ou igual ao número de crianças. Dessa forma, podemos fazer uso apenas do prefixos de soma de restos para tentar encontrar a configuração válida. Logo, no caso limite pra C crianças com N = C temos:

(a1)                  %C = a
(a1 + a2)             %C = b
(a1 + a2 + a3)        %C = c
...
(a1 + a2 + ... + aN)  %C = x

Ou seja, temos no máximo C possíveis resultados, podendo acontecer de nenhum deles de repetir, caso no qual teriamos uma sequencia perfeita de valores 0, 1, 2, ... , C-1. No entanto, sabemos que o valor 0 é sempre possível quando não visitamos um visinho, por isso, garantimos pelo princípio da casa dos pombos que nesse caso em específico, ao menos o zero irá se repetir. Para os outros casos a repetição ja é explícita. 

Lets code;
	
*/

#include <bits/stdc++.h>
#define maxn 100001

using namespace std;

int v[maxn];

int main () {

	int c, n; 

	while (scanf("%d %d", &c, &n) && n) {
		int sum = 0;
		memset(v, 0, sizeof v);
 		bool ans = false;
		v[0] = -1;
		for (int i = 1; i <= n; i++) {
			int a; scanf("%d", &a);
			a %= c;
			sum = (sum+a)%c;
			if (v[sum] && !ans) {
				if (v[sum] == -1) v[sum] = 0;
				for (int j = v[sum]+1; j <= i; j++) {
					printf("%d", j);
					if (j < i) printf(" ");		
				}
				puts("");
				ans = true;
			}
			v[sum] = i;
		}
	}	

	return 0;
}
