#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "io.h"
#include "../point/point.h"

Point **read_points(const char *filename, int *num_points)
{
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Erro ao abrir arquivo");
        exit(1);
    }

    Point **points = NULL;
    char *line = NULL;
    size_t len = 0;
    int dimension = -1;
    int n_points = 0;

    while (getline(&line, &len, file) != -1) {
        char *id = strtok(line, ",");
        char *coord_str;
        double *coords = NULL;
        int dim = 0;

        while ((coord_str = strtok(NULL, ",\n"))) {
            dim++;
            coords = realloc(coords, dim * sizeof(double));
            coords[dim - 1] = atof(coord_str);
        }

        if (dimension == -1)
            dimension = dim;
        else if (dim != dimension) {
            perror("Dimensões inconsistentes!\n");
            exit(1);
        }

        n_points++;
        points = realloc(points, n_points * sizeof(Point *));
        points[n_points - 1] =
            point_construct(dimension, coords, id, strlen(id));
        free(coords);
    }

    *num_points = n_points;
    free(line);
    fclose(file);
    return points;
}

void write_clusters(const char *filename, Clusters *c)
{
    FILE *file = fopen(filename, "w");
    for (int i = 0; i < get_clusters_k(c); i++) {
        for (int j = 0; j < get_cluster_size(c, i); j++) {
            fprintf(file, "%s%s", get_cluster_id_point(c, i, j),
                    (j < get_cluster_size(c, i) - 1) ? "," : "\n");
            cluster_point_destroy(c, i, j);
        }
    }

    fclose(file);
}
