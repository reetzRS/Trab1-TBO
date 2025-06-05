#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../point/point.h"
#include "graph.h"

/**
 * @struct edge
 * @brief Estrutura que armazena vértice/distância e os 2 pontos que conecta
 */
struct edge {
    double edge_weight;
    int p1;
    int p2;
};

/**
 * @struct graph
 * @brief Estrutura que vai representar o grafo, com os vetices e arestas
 */
struct graph {
    int size;
    int edge_size;
    Point **vertices;
    Edge *edges_matrix;
};

/**
 * @brief Função interna do tipo pra comparar o peso das arestas.
 *
 * @param a Aresta 1
 * @param b Aresta 2
 * @return Valor da comparação entre as arestas
 */
int comp_edge_weight(const void *a, const void *b)
{
    Edge *e1 = (Edge *)a;
    Edge *e2 = (Edge *)b;
    if (e1->edge_weight < e2->edge_weight)
        return -1;
    if (e1->edge_weight > e2->edge_weight)
        return 1;
    return 0;
}

/**
 * @brief Função interna para ordenação das arestas
 *
 * @param g Estrutura que contém o vetor de arestas
 */
void sort_edges(Graph *g)
{
    qsort(g->edges_matrix, g->edge_size, sizeof(Edge), comp_edge_weight);
}

/**
 * @brief Função interna para mapear as arestas em um vetor de tamanho
 * (n*(n-1))/2
 *
 * @param i Índice do ponto i
 * @param j Índice do ponto j
 * @param size Valor n, onde n é a quantidade de pontos
 * @return Retorna o índice do vetor para a aresta entre i e j
 */
int map_edge_matrix(int i, int j, int size)
{
    /**
     * Precisamos considerar que os elementos de nosso vetor são mapeados de uma
     * matriz triangular superior, sem a diagonal principal. Ou seja, somente
     * valores de i < j são válidos. Como o grafo é não direcionado, a matriz
     * correspondente é simétrica e um elemento em (i,j) é igual ao de (j,i).
     *
     */
    if (i > j) {
        int aux = i;
        i = j;
        j = aux;
    }

    /**
     * Somatório de uma PA, onde cada termo depende de i (número de iterações do
     * laço externo ao preencher o vetor). O valor representa a quantidade de
     * elementos da matriz percorridos.
     */
    int key = i * size - ((i * (i + 1)) / 2) + (j - i - 1);

    return key;
}

Graph *graph_construct(Point **vertices, int size)
{
    Graph *g = (Graph *)malloc(sizeof(Graph));

    clock_t start, end;
    double time_elapsed;
    /**
     * A quantidade de arestas está em relação para n vértices da seguinte
     * forma: n = número de vértices => m =(n*(n-1))/2 = numero de arestas
     */
    g->size = size;                         // Número de vértices
    g->edge_size = (size * (size - 1)) / 2; // Número de arestas

    /**
     * Uso de um vetor com o número de arestas, onde cada uma vai ser mapeada
     * através dos índices dos vértices associados.
     */
    g->edges_matrix = (Edge *)calloc(g->edge_size, sizeof(Edge));

    g->vertices = vertices;

    /**
     * Ordena os vértices antes de fazer o kruskal pra simplificar o processo de
     * separação dos grupos de forma ordenada (Economiza a ordenação dos k
     * grupos). Mais explicações na função de clustering.
     */
    start = clock();
    sort_points(g->vertices, g->size);
    end = clock();
    time_elapsed = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Ordenação dos vértices: %f\n", time_elapsed);

    set_edges_matrix(g);

    return g;
}

int edge_get_src(Graph *g, int i)
{
    Edge e = get_graph_edge(g, i);
    return e.p1;
}

int edge_get_dest(Graph *g, int i)
{
    Edge e = get_graph_edge(g, i);
    return e.p2;
}

double get_edge_weight(Graph *g, int i)
{
    double weigth = g->edges_matrix[i].edge_weight;
    return weigth;
}

Point **get_graph_vertices(Graph *g)
{
    return g->vertices;
}

Edge get_graph_edge(Graph *g, int i)
{
    Edge e = g->edges_matrix[i];

    return e;
}

int get_graph_num_vertices(Graph *g)
{
    return g->size;
}

int get_graph_num_edges(Graph *g)
{
    return g->edge_size;
}

void set_edges_matrix(Graph *g)
{
    Point **p = g->vertices;
    double time_elapsed;
    clock_t start, end;
    /**
     * Percorre todas as possibilidades de conexão entre os vértices,
     * armazenando cada aresta com sua distância e o índice dos seus vértices
     * associados na "Matriz", que nesse caso será um vetor unidimensional.
     */
    start = clock();
    for (int i = 0; i < g->size - 1; i++) {
        for (int j = i + 1; j < g->size; j++) {
            double d = two_points_distance(p[i], p[j]);
            int key = map_edge_matrix(i, j, g->size);

            g->edges_matrix[key].edge_weight = d;
            g->edges_matrix[key].p1 = i;
            g->edges_matrix[key].p2 = j;
        }
    }
    end = clock();
    time_elapsed = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Cálculo das distâncias: %f\n", time_elapsed);

    start = clock();
    sort_edges(g);
    end = clock();
    time_elapsed = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Ordenação das arestas: %f\n", time_elapsed);
}

void graph_destroy(Graph *g)
{
    free(g->edges_matrix);
    free(g);
}