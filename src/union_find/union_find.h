#ifndef UNION_FIND_H
#define UNION_FIND_H

typedef struct union_find UnionFind;

UnionFind *uf_create(int n);
void uf_free(UnionFind *uf);
int uf_find(UnionFind *uf, int i);
void uf_union(UnionFind *uf, int i, int j);

#endif