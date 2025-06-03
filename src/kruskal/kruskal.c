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
};

Tree *tree_construct()
{
    Tree *t = (Tree *)malloc(sizeof(Tree));
    t->vertices = (Point **)calloc(1, sizeof(Point *));
    t->vertices[0] = NULL;

    t->size = 0;

    return t;
}

Mst *mst_construct(Tree *t, UnionFind *uf, int n, Point **vertices)
{
    Mst *mst = (Mst *)malloc(sizeof(Mst));
    mst->t = t;
    mst->t->vertices = vertices;
    mst->uf = uf;
    mst->size = n;
    mst->t->size = mst->size;

    return mst;
}

Clusters *clusters_construct(int k)
{
    Clusters *c = (Clusters *)malloc(k * sizeof(Clusters));
    c->cluster = (Tree **)malloc(sizeof(Tree *));

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

int get_cluster_component_id(Tree *t, int i)
{
    return get_id_point(t->vertices[i]);
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
    t->vertices[i] = vertex;
}

// Modificar a funcao kruskal para retornar arestas ordenadas
Mst *kruskal(Graph *g, int k)
{
    int n = get_graph_num_vertices(g);
    int total_edges = get_graph_num_edges(g);
    UnionFind *uf = uf_create(n);
    Mst *mst = mst_construct(tree_construct(), uf, n, get_graph_vertices(g));

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

Clusters *clustering(Mst *m, int k)
{
    int cluster_count = 0;

    Clusters *c = clusters_construct(k);
    for (int i = 0; i < m->size; i++) {
        int found = 0;
        int component = uf_find(m->uf, m->t->vertices[i]);

        for (int j = 0; j < cluster_count; j++) {
            int cluster_root = get_cluster_component_id(c->cluster[j], 0);

            // Poderia otimizar finds criando um vetor com os k roots
            if (component == uf_find(m->uf, cluster_root)) {
                c->cluster[j]->size++;
                realloc(c->cluster[j], c->cluster[j]->size * sizeof(Tree));
                set_cluster_component(c->cluster[j], m->t->vertices[i],
                                      c->cluster[j]->size - 1);
                found = 1;
            }
        }

        if (!found) {
            set_cluster_component(c->cluster[cluster_count], m->t->vertices[i],
                                  0);
            m->t->size++;
            cluster_count++;
        }
    }
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
    free(c);
}
