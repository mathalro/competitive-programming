# Finit or not

	Este é um problema de teoria dos números, por isso, precisamos refletir sobre diversas propriedades antes de resolvê-lo. 

Primeiro, devemos definir a condição para que uma fraçao p / q seja finita. Se considerarmos apenas base 10, a fração p / q é finita, sse seu denominador "q" puder ser fatorado nos mesmos fatores primos de 10 (base), isto é, 2 e 5. Por exemplo:

A fração 8/40 pode ser escrita no formato 8 / (2^3 * 5^1) = 8 / (2^2 * (2^1 * 5^1)) = 8 * 5^2 / ((2^2 * 5^2) * (2^1 * 5^1)) = 
8 * 25 / 10^3 = 0.2. 

Generalizando: se conseguimos reduzir uma fração para o formato p / (2^n * 5^n), essa fração possui finitas casas decimais, pois no fim estaremos fazendo uma divisão por uma potência de base 10, que sempre possui limite. 

Para outras bases, a representação de frações segue o mesmo padrão. Por exemplo, para base 3, se queremos representar o número 1 / 9 podemos visualizá-lo como 1 / 3^2, o que na base 3 pode ser escrito como 0.01. Portanto, verificar se uma fração é finita em base b, é o mesmo que verificar se é possível fatorar seu denominador utilizando exatamente os mesmos fatores primos da base b em questão.

Agora que sabemos qual a condição para verificar se uma fração em qualquer base é ou não finita, devemos então encontrar uma forma de comparar os fatores primos da base b com os fatores primos do denominador q. Se os fatores primos forem os mesmos, é possível reduzir q a 1 utilizando apenas estes fatores. Por exemplo:

q = 50
b = 10
50 = 2^1 * 5^2 => 50/2 = 25 => 25/5 = 5 => 5 / 5 = 1. 

q = 45
b = 10
45 = 3^2 * 5^1 => 45/5 = 15 => a partir deste momento não conseguimos mais reduzir o denominador q.

Portanto, podemos fazer uso desta propriedade e, caso consigamos reduzir o denominador q a 1 utilizando os fatores primos da base, a resposta é finite. Caso contrário, a resposta é infinite. Agora precisamos de uma maneira rápida de fazer isto! Podemos então utilizar um método simples e eficiente, nosso conhecido GCD, que nos dirá qual o maior divisor comum entre q e b. Desta forma, podemos reduzir drasticamente o valor de q se o dividirmos pelo GCD(q, b), e devemos fazer isto até que o GCD(q, b) seja 1, situação em que q poderá ou não ser 1. Quando dividimos pelo GCD estamos a procura do maior fator comum entre q e b, no entanto, quando quebramos q em pedaços menores, estamos inplicitamente utilizando os fatores primos de b para realizar a divisão de q.



