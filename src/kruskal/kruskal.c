#include <stdlib.h>
#include "kruskal.h"
#include "../graph/graph.h"

static int compare_edges(const void *a, const void *b) {
    const Edge *ea = (const Edge *)a;
    const Edge *eb = (const Edge *)b;
    double w1 = edge_get_weight(ea);
    double w2 = edge_get_weight(eb);

    if (w1 < w2) return -1;
    if (w1 > w2) return 1;
    return 0;
}

// Inicializa estrutura de union-find
UnionFind *uf_create(int n) {
    UnionFind *uf = malloc(sizeof(UnionFind));
    uf->parent = malloc(n * sizeof(int));
    uf->rank = calloc(n, sizeof(int));
    uf->size = n;
    for (int i = 0; i < n; ++i)
        uf->parent[i] = i;
    return uf;
}

void uf_free(UnionFind *uf) {
    free(uf->parent);
    free(uf->rank);
    free(uf);
}

// Busca com compressão de caminho
int uf_find(UnionFind *uf, int i) {
    if (uf->parent[i] != i)
        uf->parent[i] = uf_find(uf, uf->parent[i]);
    return uf->parent[i];
}

// União por rank
void uf_union(UnionFind *uf, int i, int j) {
    int root_i = uf_find(uf, i);
    int root_j = uf_find(uf, j);
    if (root_i == root_j) return;

    if (uf->rank[root_i] < uf->rank[root_j]) {
        uf->parent[root_i] = root_j;
    } else if (uf->rank[root_i] > uf->rank[root_j]) {
        uf->parent[root_j] = root_i;
    } else {
        uf->parent[root_j] = root_i;
        uf->rank[root_i]++;
    }
}

// Funcao de comparacao para ordenar arestas em ordem decrescente
static int compare_edges_desc(const void *a, const void *b) {
    const Edge *ea = (const Edge *)a;
    const Edge *eb = (const Edge *)b;
    double w1 = edge_get_weight(ea);
    double w2 = edge_get_weight(eb);

    if (w1 > w2) return -1;
    if (w1 < w2) return 1;
    return 0;
}

// Modificar a funcao kruskal para retornar arestas ordenadas
Edge **kruskal(Graph *g, int *mst_size) {
    int n = graph_get_num_vertices(g);
    int total_edges = graph_get_num_edges(g);

    UnionFind *uf = uf_create(n);
    Edge **mst = malloc((n - 1) * sizeof(Edge*)); 
    int count = 0;

    for (int i = 0; i < total_edges && count < n - 1; ++i) {
        Edge *e = graph_get_sorted_edge(g, i);
        int u = edge_get_src(e);
        int v = edge_get_dest(e);

        if (uf_find(uf, u) != uf_find(uf, v)) {
            mst[count++] = e; 
            uf_union(uf, u, v);
        }
    }

    *mst_size = count;
    return mst;
}