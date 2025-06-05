# Relatório

## Introdução

**breve descrição do conteúdo do documento e dos resultados obtidos.**

> O objetivo deste trabalho  ́e implementar um algoritmo de agrupamento, chamado de agrupamento de espaçamento
máximo, utilizando uma MST (Minimum Spanning Tree). A ideia central é analisar um conjunto de pontos no Rm e
agrupá-los por uma semelhança, que nesse caso será a distância euclidiana entre os pontos: 
- Pontos que estiverem dentro de um determinado raio de distância de um outro ponto vão ser parte do mesmo grupo;
- Pontos que estiverem fora desse raio vão formar outro grupo
> A distância mínima entre dois grupos vai variar de acordo com a quantidade de grupos que desejamos formar.
> O programa se divide em leitura, ordenação, cálculo de distâncias, criação da MST, agrupamento e escrita dos resultados no arquivo. No decorrer desse relatório serão informadas as principais decisões para a construção do código, uma breve análise de complexide e uma análise empírica com casos de testes e medição do tempo gasto na execução. O código foi testado e resolveu o problema apresentado sem apresentar vazamentos de memória. A maior parte do tempo de execução gasto se dá por conta do cálculo de distâncias, passo que envolve operações em ordem quadrática. 

## Metodologia

> A ideia central da execução do programa se baseia em criar uma estrutura básica, o tipo Point, que será manipulado em forma de ponteiro no decorrer das nossas estruturas mais abstratas. O ponto armazena o ID e um vetor de m valores que representa as suas coordenadas em Rm. Com o conjunto de pontos lidos, foram calculadas e armazenadas todas distâncias possíveis, em um array, onde cada elemento é um Edge, tipo que armazena o valor da distância em ponto flutuante e o valor inteiro que representa o índice dos dois pontos que são conectados por essa aresta. Como a estrutura só armazena tipos simples, a ideia foi de manipulá-la diretamente ao invés de alocar/desalocar uma quantidade enorme de valores na memória. Tanto o ponto quanto a distância são armazenados em um array dentro de uma estrutura maior, o Graph. É nessa estrutura que será rodado o algoritmo de Kruskal. Como a saída no arquivo espera que os valores estejam ordenados lexicograficamente em termos dos ID's de cada ponto, a ordenação dos pontos é feita logo na criação do grafo. A partir dos pontos ordenados, a lista de distâncias é criada e então ordenada para ser usada no Kruskal. 

## Estrutura do Projeto

- `src/`: arquivos-fonte do trabalho (`.c` e `.h`)
- `build/`: arquivos de compilação (Ignorados pelo .gitignore a principio)


## Compilação

> A compilação final deve ser
```bash
make
./trab1 entrada.txt k saida.txt
```

## Links úteis

- https://en.wikipedia.org/wiki/Kruskal%27s_algorithm


### Ao final para transformar em pdf

```bash
pandoc seu_arquivo.md -o saida.pdf --highlight-style=tango
```
