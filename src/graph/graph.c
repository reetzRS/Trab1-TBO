#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "graph.h"

typedef struct {
    double edge_weight;
    Point *vertex_1;
    Point *vertex_2;
} Edge;

/**
 * @brief Estrutura que vai representar o grafo, com os vetices e arestas
 *
 */
struct graph {
    int size;
    int edge_size;
    int matrix_size;
    Point **vertices;
    Edge **edges_matrix;
    Edge **sorted_edges;
};

Graph *graph_construct(Point **vertices, int size)
{
    Graph *g = (Graph *)malloc(sizeof(Graph));

    /**
     * A quantidade de arestas está em relação para n vértices da seguinte
     * forma: n = número de vértices => m =(n*(n+1))/2 = numero de arestas
     */
    g->size = size;                         // Número de vértices
    g->edge_size = (size * (size - 1)) / 2; // Número de arestas
    /**
     * Tamanho da matriz que vai guardar as arestas, onde as coordenadas são os
     * valores dos vértices associados
     */
    g->matrix_size = size * size;

    g->vertices = (Point **)calloc(g->size, sizeof(Point *));
    g->edges_matrix = (Edge **)calloc(g->matrix_size, sizeof(Edge *));
    g->sorted_edges = (Edge **)calloc(g->edge_size, sizeof(Edge *));

    g->vertices = vertices;

    return g;
}