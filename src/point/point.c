#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "point.h"

/**
 * @struct point
 * @brief Estrutura que armazena um ponto e seu identificador.
 *
 */
struct point {
    int dimension;
    float *coordinate;
    char *id;
    int id_len;
};

Point *point_construct(int dimension, float *coordinate, char *id, int id_len)
{
    Point *p = malloc(sizeof(Point));

    p->dimension = dimension;
    p->id_len = id_len;

    p->coordinate = calloc(p->dimension, sizeof(float));
    p->id = calloc(p->id_len, sizeof(char));

    memcpy(p->coordinate, coordinate, p->dimension * sizeof(float));
    memcpy(p->id, id, p->id_len * sizeof(char));

    return p;
}

int get_dimension_point(Point *p)
{
    return p->dimension;
}

float *get_coordinate_point(Point *p)
{
    return p->coordinate;
}

char *get_id_point(Point *p)
{
    return p->id;
}

int get_id_len_point(Point *p)
{
    return p->id_len;
}

double two_points_distance(Point *p1, Point *p2)
{
    double distance;
    double sum = 0;

    for(int i = 0; i < p1->dimension; i++)
        sum += pow((p2->coordinate[i] - p1->coordinate[i]), 2);

    distance = sqrt(sum);

    return distance;
}

void point_destroy(Point *p)
{
    free(p->coordinate);
    free(p->id);
    free(p);
}