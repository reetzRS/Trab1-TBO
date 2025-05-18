#ifndef _GRAPH_H
#define _GRAPH_H

#include "../point/point.h"

typedef struct edge Edge;
typedef struct graph Graph;

/**
 * @brief Constrói a estrutura de grafo com os vértices.
 *
 * @param vertices Vetor de pontos, que representam os vértices do grafo
 * @param size Quantidade de vértices do grafo.
 * @return Grafo inicializado com os vértices
 */
Graph *graph_construct(Point **vertices, int size);

/**
 * @brief Preenche a matriz com as distâncias entre os pontos
 *
 * @param g Estrutura que contém o conjunto de pontos para calcular a matriz
 */
void set_edges_matrix(Graph *g);

/**
 * @brief Retorna uma aresta entre os vértices i e j
 *
 * @param e Vetor contendo as arestas
 * @param i Vértice i
 * @param j Vértice j
 * @return Distância entre os pontos i e j
 */
double get_edge_weight(Edge *e, int i, int j, int size);

/**
 * @brief Retorna o vetor com as arestas ordenadas.
 *
 * @param g Estrutura que contém o vetor de arestas ordenadas
 * @return Vetor de arestas ordenadas
 */
Edge *get_sorted_edges(Graph *g);

/**
 * @brief Retorna o peso de uma aresta ordenada
 *
 * @param g Estrutra que contém o vetor de arestas ordenadas
 * @param i Índice da aresta buscada
 * @return double
 */
double get_sorted_edge_weight(Graph *g, int i);

/**
 * @brief Mapeia uma matriz de arestas em um índice de um vetor unidimensional
 *
 * @param i Índice da linha da matriz
 * @param j Índice da coluna da matriz
 * @param size Quantidade de linhas/colunas da matriz quadrada
 * @return Retorna o valor do elemento (i,j) chaveado em um vetor
 *
 * A ideia dessa função é possibilitar o armazenamento das arestas em um vetor
 * unidimensional, visto que em uma matriz size * size, as arestas só ocupariam
 * o equivalente a uma matriz triangular sem a diagonal principal. Então,
 * mapeando esses valores em um vetor menor, economizamos em número de alocações
 * e possível custo de acesso.
 */
int map_edge_matrix(int i, int j, int size);

/**
 * @brief Função para ordenação das arestas
 *
 * @param g Estrutura que contém o vetor de arestas
 */
void sort_edges(Graph *g);

/**
 * @brief Inicializa o vetor de arestas ordenado
 *
 * @param g Estrutura com o vetor de arestas ordenado
 */
void set_sorted_edges(Graph *g);

/**
 * @brief Função que libera o espaço da estrutura
 *
 * @param g Estrura contendo os vértices e arestas para ser desalocada
 */
void graph_destroy(Graph *g);

#endif