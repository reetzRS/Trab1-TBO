#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "graph/graph.h"
#include "point/point.h"

#include "../inputs/test.h"

int main()
{
    int dim = 10;
    int id_len = 1;
    char id = 'a';
    int k = 0;
    int size = 50000;
    /*double d[30] = {
        1.23, 4.56, 7.89, // bloco 0
        0.12, 3.45, 6.78, // bloco 1
        9.01, 2.34, 5.67, // bloco 2
        8.90, 1.23, 4.56, // bloco 3
        7.65, 0.98, 3.21, // bloco 4
        2.46, 5.79, 8.13, // bloco 5
        6.42, 1.57, 3.68, // bloco 6
        9.99, 0.01, 2.02, // bloco 7
        4.44, 5.55, 6.66, // bloco 8
        7.77, 8.88, 9.99  // bloco 9
    };*/

        double *d = (double *)malloc(size * sizeof(double));

    matriz(d);

    Point **p = (Point **)malloc((size / dim) * sizeof(Point *));
    double *v = (double *)malloc(dim * sizeof(double));
    char *id_ = (char *)malloc(sizeof(char));

    for (int i = 0; i < size / dim; i++) {
        for (int j = 0; j < dim; j++) {
            v[j] = d[k];
            k++;
        }

        id_[0] = id;
        p[i] = point_construct(dim, v, id_, id_len);

        // id++;
    }

    Graph *g = graph_construct(p, size / dim);

    for (int i = 0; i < 12497500; i++) {
        printf("%f\n", get_sorted_edge_weight(g, i));
    }

    for (int i = 0; i < size / dim; i++) {
        point_destroy(p[i]);
    }
    free(p);

    free(d);

    free(v);
    free(id_);
    // graph_destroy(g);
    return 0;
}