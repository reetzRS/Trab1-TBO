#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "../graph/graph.h"

typedef struct tree Tree;
typedef struct mst Mst;
typedef struct clusters Clusters;

Mst *kruskal(Graph *g, int k);

#endif
