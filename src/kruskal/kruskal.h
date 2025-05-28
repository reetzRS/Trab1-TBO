#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "../graph/graph.h"

// Estrutura para Union-Find
typedef struct {
    int *parent;
    int *rank;
    int size;
} UnionFind;

UnionFind *uf_create(int n);
void uf_free(UnionFind *uf);
int uf_find(UnionFind *uf, int i);
void uf_union(UnionFind *uf, int i, int j);

Edge **kruskal(Graph *g, int *mst_size);

#endif
