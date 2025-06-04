#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "../graph/graph.h"

typedef struct tree Tree;
typedef struct mst Mst;
typedef struct clusters Clusters;

/**
 * @brief Retorna a quantidade de elementos de um dos clusters
 * 
 * @param c Estrutura que agrupa a lista de clusters
 * @param i Índice do cluster a ser acessado
 * @return Quantidade de elementos do cluster
 */
int get_cluster_size(Clusters *c, int i);

/**
 * @brief Retorna o valor k, que representa a quantidade de clusters
 * 
 * @param c Estrutura que agrupa a lista de clusters
 * @return Quantidade de clusters
 */
int get_clusters_k(Clusters *c);

/**
 * @brief Retorna o ID único de um ponto dentro de um cluster
 * 
 * @param c Estrutra que agrupa a lista de clusters
 * @param i Índice que aponta qual cluster será buscado
 * @param j Índice que aponta qual elemento do cluster será buscado
 * @return char* 
 */
char *get_cluster_id_point(Clusters *c, int i, int j);

/**
 * @brief Algoritmo de kruskal para gerar a mst
 * 
 * @param g Grafo contendo os vértices e arestas
 * @param k Quantidade de arestas a serem removidas
 * @return Ponteiro para a estrutura de mst
 * 
 * A função opera o algoritmo de kruskal no grafo, usando um disjoint-set
 * (Union-Find). Ao invés de operar n - 1 conexões, o algoritmo opera n - k,
 * economizando o passo de remover k - 1 arestas.
 */
Mst *kruskal(Graph *g, int k);

/**
 * @brief A função agrupa cada um dos clusters e retorna uma lista 
 * 
 * @param m Árovre contendo o union-find e a lista de pontos
 * @param k Quantidade de clusters a ser gerada
 * @return Clusters* 
 */
Clusters *clustering(Mst *m, int k);

/**
 * @brief Retorna a raiz de um ponto dentro da árvore mínima
 * 
 * @param m Árvore contendo o union-find e a lista de pontos
 * @param i Índice do ponto que terá a raiz retornada
 * @return Valor do índice da raiz do ponto
 */
int get_root_mst(Mst *m, int i);

/**
 * @brief Destrói um ponto dentro de um cluster
 * 
 * @param c Estrutra que agrupa a lista de clusters
 * @param i Índice que indica a posição do cluster na lista
 * @param j Índice que indica a posição do ponto dentro do cluster
 * 
 * Desalocar o ponto dentro do cluster permite a liberação de memória logo
 * após a escrita no arquivo de forma bem simples.
 */
void cluster_point_destroy(Clusters *c, int i, int j);

/**
 * @brief Destrói a lista de clusters e suas estruturas internas
 * 
 * @param c Lista de clusters
 */
void clusters_destroy(Clusters *c);

/**
 * @brief Destrói a mst e suas estruturas internas
 * 
 * @param m Mst
 */
void mst_destroy(Mst *m);

#endif
