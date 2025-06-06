# Relatório

## Introdução

**breve descrição do conteúdo do documento e dos resultados obtidos.**

> O objetivo deste trabalho é implementar um algoritmo de agrupamento, chamado de agrupamento de espaçamento
máximo, utilizando uma MST (Minimum Spanning Tree). A ideia central é analisar um conjunto de pontos no Rm e
agrupá-los por uma semelhança, que nesse caso será a distância euclidiana entre os pontos: 
- Pontos que estiverem dentro de um determinado raio de distância de um outro ponto vão ser parte do mesmo grupo;
- Pontos que estiverem fora desse raio vão formar outro grupo
> A distância mínima entre dois grupos vai variar de acordo com a quantidade de grupos que desejamos formar.
> O programa se divide em leitura, ordenação, cálculo de distâncias, criação da MST, agrupamento e escrita dos resultados no arquivo. No decorrer desse relatório serão informadas as principais decisões para a construção do código, uma breve análise de complexide e uma análise empírica com casos de testes e medição do tempo gasto na execução. O código foi testado e resolveu o problema apresentado sem apresentar vazamentos de memória. A maior parte do tempo de execução gasto se dá por conta do cálculo de distâncias, passo que envolve operações em ordem quadrática. 

## Metodologia

**descrição das principais decisões de implementacão, incluindo uma justificativa para os algoritmos e estruturas de dados escolhidos.**

Os principais algoritmos

> A ideia central da execução do programa se baseia em criar uma estrutura básica, o tipo Point, que será manipulado em forma de ponteiro no decorrer das nossas estruturas mais abstratas. O ponto armazena o ID e um vetor de m valores que representa as suas coordenadas em $\R^m$. Com o conjunto de pontos lidos, foram calculadas e armazenadas todas distâncias possíveis, em um array, onde cada elemento é um Edge, tipo que armazena o valor da distância em ponto flutuante e o valor inteiro que representa o índice dos dois pontos que são conectados por essa aresta. Como a estrutura só armazena tipos simples, a ideia foi de manipulá-la diretamente ao invés de alocar/desalocar uma quantidade enorme de valores na memória. Tanto o ponto quanto a distância são armazenados em um array dentro de uma estrutura maior, o Graph. É nessa estrutura que será rodado o algoritmo de Kruskal. Como a saída no arquivo espera que os valores estejam ordenados lexicograficamente em termos dos ID's de cada ponto, a ordenação dos pontos é feita logo na criação do grafo. A partir dos pontos ordenados, a lista de distâncias é criada e então ordenada para ser usada no Kruskal. Como retorno da função que realiza o algoritmo de Kruskal, foi criado um novo tipo, Mst, com a referência pra lista de pontos e a estrutura de Union-find. A ideia aqui foi agrupar somente as estruturas necessárias para fazer o agrupamento, e ao mesmo tempo manter uma modularidade com uma estrutura que represente de forma adequada a árvore geradora. O agrupamento se beneficia da ordenação prévia dos pontos em termos dos ID's e itera sobre cada um dos pontos, até preencher os K grupos desejados, comparando a raiz do ponto atual com a raiz do primeiro ponto de cada grupo já existente. Se a raiz desse ponto não é igual a de algum dos grupos, então um novo grupo é formado. Assim cada um dos k grupos é preenchido. Para armazenar o conjunto de pontos a ser imprimidos, foi criada a estrutura Clusters, contendo o array onde cada elemento é a referência para um cluster, já ordenado. Então essa estrutura é passada para a função de escrita no arquivo, que simplesmente itera sobre os k grupos, escrevendo cada elemento até o fim do grupo e então inserindo o caracter \n.





### Ao final para transformar em pdf

```bash
pandoc README.md -o saida.pdf --highlight-style=tango
```
