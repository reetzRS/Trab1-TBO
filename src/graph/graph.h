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
 * @brief Retorna uma aresta entre os vértices i e j
 *
 * @param e Vetor contendo as arestas
 * @param i Vértice i
 * @param j Vértice j
 * @return Distância entre os pontos i e j
 */
double get_edge_weight(Edge *e);

/**
 * @brief Retorna o índice do vértice de partida dessa aresta
 *
 * @param e Aresta
 * @return Valor do índice dentro do array ordenado de vértices
 */
int edge_get_src(Edge *e);

/**
 * @brief Retorna o índice do vértice de chegada dessa aresta
 *
 * @param e Aresta
 * @return Valor do índice dentro do array ordenado de vértices
 */
int edge_get_dest(Edge *e);

/**
 * @brief Retorna o valor do peso/distância que a aresta representa
 *
 * @param e Aresta
 * @return Valor do peso/distância da aresta
 */
double edge_get_weight(Edge *e);

/**
 * @brief Retorna a lista de vértices do grafo
 *
 * @param g Grafo com a lista de vértices
 * @return Lista em array dos pontos do gráfico, já ordenados
 */
Point **get_graph_vertices(Graph *g);

/**
 * @brief Retorna o valor de uma aresta do grafo
 *
 * @param g Grafo com as arestas
 * @param i Índice da aresta buscada
 * @return Estrutura da aresta
 */
Edge *get_graph_edge(Graph *g, int i);

/**
 * @brief Retorna a quantidade de vértices do grafo
 *
 * @param g Grafo que contém os vértices
 * @return Quantidade de vértices
 */
int get_graph_num_vertices(Graph *g);

/**
 * @brief Retorna a quantidade de arestas do grafo
 *
 * @param g Grafo que contém as arestas
 * @return Quantidade de arestas
 */
int get_graph_num_edges(Graph *g);

/**
 * @brief Preenche a matriz com as distâncias entre os pontos
 *
 * @param g Estrutura que contém o conjunto de pontos para calcular a matriz
 */
void set_edges_matrix(Graph *g);

/**
 * @brief Função que libera o espaço da estrutura
 *
 * @param g Estrura contendo os vértices e arestas para ser desalocada
 */
void graph_destroy(Graph *g);

#endif