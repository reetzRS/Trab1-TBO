#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "point.h"
#include "graph.h"
#include "kruskal.h"
#include "io.h"
#include "union_find.h"

void testeInput(char *arg1, int *num_points);

void testeOutput(void *v);

void testeOrdenacao(void *points, int num_points);

void testeKruskal(void *points, int *mst_size);

void testeCluster(void *mst);

void testeFree(void *uf, void *edges, void *graph, void *points);

void testeGeral(char *arg1, char *arg2, char *arg3);



int main(int argc, char *argv[]) {
    if(argc != 4) {
        fprintf(stderr, "Uso: %s <entrada> <k> <saida>\n", argv[0]);
        return 1;
    }

    int num_points;
    Point **points = read_points(argv[1], &num_points);
    int k = atoi(argv[2]);

    if(k < 1 || k > num_points) {
        fprintf(stderr, "Valor de k inválido!\n");
        exit(1);
    }

    Graph *graph = graph_construct(points, num_points);
    int mst_size;
    Edge **mst = kruskal(graph, &mst_size);

    UnionFind *uf = uf_create(num_points);
    for(int i = k-1; i < mst_size; i++) {
        Edge *e = mst[i];
        uf_union(uf, edge_get_p1(e), edge_get_p2(e));
    }

    int *components = malloc(num_points * sizeof(int));
    for(int i = 0; i < num_points; i++)
        components[i] = uf_find(uf, i);

    FILE *output = fopen(argv[3], "w");
    write_clusters(points, components, num_points, output);

    free(components);
    uf_free(uf);
    free(mst);
    graph_destroy(graph);
    free_points(points, num_points);
    fclose(output);

    return 0;
}