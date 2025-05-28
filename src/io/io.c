// io.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "io.h"
#include "point.h"

Point **read_points(const char *filename, int *num_points) {
    FILE *file = fopen(filename, "r");
    if(!file) {
        perror("Erro ao abrir arquivo");
        exit(1);
    }

    Point **points = NULL;
    char *line = NULL;
    size_t len = 0;
    *num_points = 0;
    int dimension = -1;

    while(getline(&line, &len, file) != -1) {
        char *id = strtok(line, ",");
        char *coord_str;
        double *coords = NULL;
        int dim = 0;

        while((coord_str = strtok(NULL, ",\n"))) {
            coords = realloc(coords, (dim + 1) * sizeof(double));
            coords[dim++] = atof(coord_str);
        }

        if(dimension == -1) dimension = dim;
        else if(dim != dimension) {
            fprintf(stderr, "Dimensões inconsistentes!\n");
            exit(1);
        }

        points = realloc(points, (*num_points + 1) * sizeof(Point *));
        points[*num_points] = point_construct(dimension, coords, id, strlen(id));
        free(coords);
        (*num_points)++;
    }

    free(line);
    fclose(file);
    return points;
}

void write_clusters(Point **points, int *components, int n, FILE *output) {
    char ***clusters = calloc(n, sizeof(char **));
    int *sizes = calloc(n, sizeof(int));
    int cluster_count = 0;

    for(int i = 0; i < n; i++) {
        int found = 0;
        for(int j = 0; j < cluster_count; j++) {
            if(components[i] == components[(int)clusters[j][0][1]]) {
                clusters[j] = realloc(clusters[j], (sizes[j] + 1) * sizeof(char *));
                clusters[j][sizes[j]++] = get_id_point(points[i]);
                found = 1;
                break;
            }
        }
        if(!found) {
            clusters[cluster_count] = malloc(sizeof(char *));
            clusters[cluster_count][0] = get_id_point(points[i]);
            sizes[cluster_count++] = 1;
        }
    }

    for(int i = 0; i < cluster_count; i++)
        qsort(clusters[i], sizes[i], sizeof(char *), strcmp);

    qsort(clusters, cluster_count, sizeof(char **), 
        (int (*)(const void *, const void *))strcmp);

    for(int i = 0; i < cluster_count; i++) {
        for(int j = 0; j < sizes[i]; j++)
            fprintf(output, "%s%s", clusters[i][j], (j < sizes[i]-1) ? ", " : "");
        fprintf(output, "\n");
        free(clusters[i]);
    }

    free(clusters);
    free(sizes);
}

void free_points(Point **points, int n) {
    for(int i = 0; i < n; i++)
        point_destroy(points[i]);
    free(points);
}