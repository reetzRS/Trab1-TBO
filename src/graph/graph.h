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

int graph_get_num_vertices(Graph *graph);
int graph_get_num_edges(Graph *graph);
Edge *graph_get_edge(Graph *graph, int index);

int edge_get_src(Edge *edge);
int edge_get_dest(Edge *edge);
double edge_get_weight(Edge *edge);

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
 * @brief Preenche a matriz com as distâncias entre os pontos
 *
 * @param g Estrutura que contém o conjunto de pontos para calcular a matriz
 */
void set_edges_matrix(Graph *g);

/**
 * @brief Inicializa o vetor de arestas ordenado
 *
 * @param g Estrutura com o vetor de arestas ordenado
 */
void set_sorted_edges(Graph *g);

/**
 * @brief Função para ordenação das arestas
 *
 * @param g Estrutura que contém o vetor de arestas
 */
void sort_edges(Graph *g);

/**
 * @brief Função que libera o espaço da estrutura
 *
 * @param g Estrura contendo os vértices e arestas para ser desalocada
 */
void graph_destroy(Graph *g);

#endif