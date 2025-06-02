#include <stdlib.h>
#include "kruskal.h"
#include "../graph/graph.h"
#include "../union_find/union_find.h"

struct tree {
    int size;
    Point **vertices;
};
struct mst {
    UnionFind *uf;
    Tree *t;
};

struct clusters {
    Tree **cluster;
    int k;
};

Tree *tree_construct()
{
    Tree *t = (Tree *)malloc(sizeof(Tree));

    return t;
}

Mst *mst_construct(Tree *t, UnionFind *uf)
{
    Mst *mst = (Mst *)malloc(sizeof(Mst));
    mst->t = t;
    mst->uf = uf;

    return mst;
}

Clusters *clusters_construct(int k)
{
    Clusters *c = (Clusters *)malloc(k * sizeof(Clusters));

    c->k = k;

    for (int i = 0; i < k; i++) {
        c->cluster[i] = tree_construct();
    }

    return c;
}

// Modificar a funcao kruskal para retornar arestas ordenadas
Mst *kruskal(Graph *g, int k)
{
    int n = get_graph_num_vertices(g);
    int total_edges = get_graph_num_edges(g);
    UnionFind *uf = uf_create(n);
    Mst *mst = mst_construct(get_graph_vertices(g), uf);

    int count = 0;

    for (int i = 0; i < total_edges && count < n - k; ++i) {
        int u = edge_get_src(get_graph_edge(g, i));
        int v = edge_get_dest(get_graph_edge(g, i));

        if (uf_find(uf, u) != uf_find(uf, v)) {
            uf_union(uf, u, v);
        }
    }

    return mst;
}

void tree_destroy(Tree *t)
{
    free(t->vertices);
    free(t);
}

void mst_destroy(Mst *m)
{
    uf_destroy(m->uf);
    tree_destroy(m->t);
    free(m);
}

void clusters_destroy(Clusters *c)
{
    for (int i = 0; i < c->k; i++) {
        tree_destroy(c->cluster[i]);
    }

    free(c);
}
