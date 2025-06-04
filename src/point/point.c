#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "point.h"

/**
 * @struct point
 * @brief Estrutura que armazena um ponto e seu identificador.
 */
struct point {
    int dimension;
    double *coordinate;
    char *id;
    int id_len;
};

/**
 * @brief Função interna do tipo pra comparar o ID dos pontos.
 *
 * @param a Ponto 1
 * @param b Ponto 2
 * @return Valor da comparação entre os ID's
 */
int comp_point_ID(const void *a, const void *b)
{
    Point *p1 = *(Point **)a;
    Point *p2 = *(Point **)b;

    return strcmp(get_id_point(p1), get_id_point(p2));
}

Point *point_construct(int dimension, double *coordinate, char *id, int id_len)
{
    Point *p = (Point *)malloc(sizeof(Point));

    p->dimension = dimension;
    p->id_len = id_len;

    // Aloca as coordenadas e o id, baseado nos valores do arquivo
    p->coordinate = calloc(p->dimension, sizeof(double));
    p->id = calloc(p->id_len + 1, sizeof(char));

    // Cria uma cópia, já que os valores do parâmetro vão ser reutilizados
    memcpy(p->coordinate, coordinate, p->dimension * sizeof(double));
    memcpy(p->id, id, p->id_len * sizeof(char));

    return p;
}

int get_dimension_point(Point *p)
{
    return p->dimension;
}

double *get_coordinate_point(Point *p)
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

    // O loop faz a somatória do quadrado da diferença das coordenadas
    for (int i = 0; i < p1->dimension; i++)
        sum += pow((p2->coordinate[i] - p1->coordinate[i]), 2);

    // A distância é a raiz do somatório calculado acima
    distance = sqrt(sum);

    return distance;
}

void sort_points(Point **p, int n)
{
    qsort(p, n, sizeof(Point *), comp_point_ID);
}

void point_destroy(Point *p)
{
    free(p->coordinate);
    free(p->id);
    free(p);
}
