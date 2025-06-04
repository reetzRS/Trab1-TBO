#include <stdio.h>
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
    int size;
};

struct clusters {
    Tree **cluster;
    int k;
    int *cluster_root;
};

Tree *tree_construct()
{
    Tree *t = (Tree *)malloc(sizeof(Tree));
    t->vertices = NULL;

    t->size = 0;

    return t;
}

Mst *mst_construct(UnionFind *uf, int n, Point **vertices)
{
    Mst *mst = (Mst *)malloc(sizeof(Mst));
    mst->t = tree_construct();
    mst->t->vertices = vertices;
    mst->uf = uf;
    mst->size = n;
    mst->t->size = mst->size;

    return mst;
}

Clusters *clusters_construct(int k)
{
    Clusters *c = (Clusters *)malloc(sizeof(Clusters));
    c->cluster = (Tree **)malloc(k * sizeof(Tree *));
    c->cluster_root = (int *)malloc(k * sizeof(int));

    c->k = k;

    for (int i = 0; i < k; i++) {
        c->cluster[i] = tree_construct();
    }

    return c;
}

int get_cluster_size(Clusters *c, int i)
{
    return c->cluster[i]->size;
}

int get_clusters_k(Clusters *c)
{
    return c->k;
}

char *get_cluster_id_point(Clusters *c, int i, int j)
{
    char *id = get_id_point(c->cluster[i]->vertices[j]);
    return id;
}

Point *get_cluster_point(Clusters *c, int i, int j)
{
    return c->cluster[i]->vertices[j];
}

void set_cluster_component(Tree *t, Point *vertex, int i)
{
    t->vertices[i - 1] = vertex;
}

// Modificar a funcao kruskal para retornar arestas ordenadas
Mst *kruskal(Graph *g, int k)
{
    int n = get_graph_num_vertices(g);
    int total_edges = get_graph_num_edges(g);
    UnionFind *uf = uf_create(n);
    Mst *mst = mst_construct(uf, n, get_graph_vertices(g));

    int count = 0;

    for (int i = 0; i < total_edges && count < n - k; ++i) {
        int u = edge_get_src(g, i);
        int v = edge_get_dest(g, i);

        if (uf_find(uf, u) != uf_find(uf, v)) {
            uf_union(uf, u, v);
            count++;
        }
    }

    return mst;
}

Clusters *clustering(Mst *m, int k)
{
    int cluster_count = 0;

    Clusters *c = clusters_construct(k);
    for (int i = 0; i < m->size; i++) {
        int found = 0;
        int component = uf_find(m->uf, i);

        for (int j = 0; j < cluster_count; j++) {
            if (component == uf_find(m->uf, c->cluster_root[j])) {
                c->cluster[j]->size++;
                c->cluster[j]->vertices =
                    realloc(c->cluster[j]->vertices,
                            c->cluster[j]->size * sizeof(Point *));
                set_cluster_component(c->cluster[j], m->t->vertices[i],
                                      c->cluster[j]->size);
                found = 1;
            }
        }

        if (!found) {
            c->cluster[cluster_count]->vertices = malloc(sizeof(Point *));
            set_cluster_component(c->cluster[cluster_count], m->t->vertices[i],
                                  1);
            c->cluster_root[cluster_count] = uf_find(m->uf, i);
            c->cluster[cluster_count]->size++;
            m->t->size++;
            cluster_count++;
        }
    }

    return c;
}

int get_root_mst(Mst *m, int i)
{
    return uf_find(m->uf, i);
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

void cluster_point_destroy(Clusters *c, int i, int j)
{
    point_destroy(c->cluster[i]->vertices[j]);
}

void clusters_destroy(Clusters *c)
{
    for (int i = 0; i < c->k; i++) {
        tree_destroy(c->cluster[i]);
    }
    free(c->cluster);
    free(c->cluster_root);
    free(c);
}
