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
    int *coordinate;
    char *id;
    int id_len;
};

Point *point_construct(int dimension, int *coordinate, char *id, int id_len)
{
    Point *p = malloc(sizeof(Point));

    p->dimension = dimension;
    p->id_len = id_len;

    p->coordinate = calloc(dimension, sizeof(int));
    p->id = calloc(id_len, sizeof(char));
}

void point_destroy(Point *p)
{
    free(p->coordinate);
    free(p->id);
    free(p);
}