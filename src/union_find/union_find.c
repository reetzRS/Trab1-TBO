#include <stdlib.h>
#include "union_find.h"

struct union_find {
    int *parent;
    int *rank;
    int size;
};

UnionFind *uf_create(int n) {
    UnionFind *uf = malloc(sizeof(UnionFind));
    uf->parent = malloc(n * sizeof(int));
    uf->rank = calloc(n, sizeof(int));
    uf->size = n;
    for(int i = 0; i < n; i++) uf->parent[i] = i;
    return uf;
}

void uf_free(UnionFind *uf) {
    free(uf->parent);
    free(uf->rank);
    free(uf);
}

int uf_find(UnionFind *uf, int i) {
    if(uf->parent[i] != i)
        uf->parent[i] = uf_find(uf, uf->parent[i]);
    return uf->parent[i];
}

void uf_union(UnionFind *uf, int i, int j) {
    int root_i = uf_find(uf, i);
    int root_j = uf_find(uf, j);
    if(root_i == root_j) return;

    if(uf->rank[root_i] < uf->rank[root_j]) {
        uf->parent[root_i] = root_j;
    } else {
        uf->parent[root_j] = root_i;
        if(uf->rank[root_i] == uf->rank[root_j])
            uf->rank[root_i]++;
    }
}