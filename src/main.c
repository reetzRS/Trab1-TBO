#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "point/point.h"
#include "graph/graph.h"
#include "kruskal/kruskal.h"
#include "io/io.h"
#include "union_find/union_find.h"

int main(int argc, char *argv[])
{
    if (argc < 4) {
        perror("Uso: ./trab1 <entrada> <k> <saida>\n");
        exit(1);
    }

    int k = atoi(argv[2]);
    int num_points;
    double general_time_taken = 0;
    clock_t start, stop;
    start = clock();
    Point **points = read_points(argv[1], &num_points);
    if (k < 1 || k > num_points) {
        perror("Valor de k inválido!\n");
        exit(1);
    }
    stop = clock();
    double time_taken = ((double)stop - start) / CLOCKS_PER_SEC;
    general_time_taken += time_taken;
    printf("Tempo de leitura: %f\n", time_taken);

    start = clock();
    Graph *g = graph_construct(points, num_points);
    stop = clock();
    time_taken = ((double)stop - start) / CLOCKS_PER_SEC;
    general_time_taken += time_taken;
    printf("Tempo de cálculo de distâncias e ordenações: %f\n", time_taken);

    start = clock();
    Mst *m = kruskal(g, k);
    stop = clock();
    time_taken = ((double)stop - start) / CLOCKS_PER_SEC;
    general_time_taken += time_taken;
    printf("Tempo de kruskal: %f\n", time_taken);

    start = clock();
    Clusters *c = clustering(m, k);
    stop = clock();
    time_taken = ((double)stop - start) / CLOCKS_PER_SEC;
    general_time_taken += time_taken;
    printf("Tempo de clustering: %f\n", time_taken);

    start = clock();
    write_clusters(argv[3], c);
    stop = clock();
    time_taken = ((double)stop - start) / CLOCKS_PER_SEC;
    general_time_taken += time_taken;
    printf("Tempo de escrita: %f\n", time_taken);

    start = clock();
    graph_destroy(g);
    mst_destroy(m);
    clusters_destroy(c);
    stop = clock();
    time_taken = ((double)stop - start) / CLOCKS_PER_SEC;
    general_time_taken += time_taken;
    printf("Tempo de destroy: %f\n", time_taken);

    printf("Tempo geral: %f\n", general_time_taken);

    return 0;
}