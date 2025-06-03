#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "../graph/graph.h"

typedef struct tree Tree;
typedef struct mst Mst;
typedef struct clusters Clusters;

int get_cluster_size(Clusters *c, int i);

int get_clusters_k(Clusters *c);

char *get_cluster_id_point(Clusters *c, int i, int j);

Mst *kruskal(Graph *g, int k);

void cluster_point_destroy(Clusters *c, int i, int j);

void clusters_destroy(Clusters *c);

#endif
