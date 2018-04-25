# URI 1325 - Mapas Bolha

# Descrição

	O problema descreve um sistema de zoom que é representado por uma quadtree. Cada aproximação de zoom representa um nível a mais que se busca na quadtree. Para isso o problema informa que o aprofundamento por quadrante é representado pelos simbolos: p (quadrante noroeste), q (quadrante nordeste), r (quadrante sudeste) e s(quadrante sudoeste). Desta forma, se quisermos representar, por exemplo, um zoom de 4 vezes no canto superior esquerdo, podemos utilizar o simbolo mpppp, em que m representa o quadrante inicial e cada p representa um zoom no quadrante noroeste do subquadrante seguinte. 

	Dado isto, o problema pede para que seja dito quais os vizinhos (cima, baixo, esquerda, direita) de um dado quadrante em um certo nível de zoom. 

## Solução

	A solução do problema requer um pouco de imaginação, do ponto de vista estrutural da quadtree. Observando a maneira com que os quadrantes vão se subdividindo, é possível verificar se um determinado quadrante possui um vizinho direto. Caso este não possua um visinho direto, podemos regredir quadrantes até que um quadrante anterior possua tal vizinho, e então procuramos pelo extremo contrário (ao que estamos procurando no vizinho utilizado). Por exemplo:
	
	Se estivermos procurando pelos vizinhos de "mspq". Podemos começar buscando pelo vizinho de cima. Como o ultimo quadrante de zoom é do tipo q, sabemos, por definição que este quadrante não possui um vizinho superior, pois q ja está na parte superior do quadrante. Portanto, devemos regredir um zoom, passando para o simbolo "msp", que também não possui um vizinho superior, pois p também está na parte superior. Regredimos novamente o zoom para "ms". Neste caso o quadrante possui um vizinho superior, pois s está na parte de baixo. O vizinho superior de "ms" é "mp", encontramos então o quadrante maior onde o vizinho superior do quadrante inicial estará. No entanto, precisamos voltar com o zoom do visinho ao nível do zoom inicial. Para isto, podemos analisar a simetria dos casos. Como queremos o visinho superior de um quadrante que está abaixo do quadrante maior atual, devemos buscar o subquadrante mais abaixo neste quadrante maior e devemos levar em conta que neste caso (vertical) todas os caminhos que foram tomados pelo quadrante inicial são tomados aqui, mas de maneira contrária. Portanto, caminhamos a partir de "mp" com base em "mspq" e temos o seguinte caminho: "mp" -> "mps" (s é simétrico do p) -> "mpsr" (r é simétrico do q). 

	O caso analisado foi para encontrar apenas o vizinho de cima. No entanto, os outros vizinhos seguem o mesmo padrão, sendo possível até mesmo generalizar a função de busca. Deve-se ter atenção também ao caso em que a resposta é none, neste caso o simbolo de busca é modificado até "m" e nunca há vizinho possível. 
