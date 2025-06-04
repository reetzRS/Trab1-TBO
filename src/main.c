#include <stdio.h>
#include <string.h>

#define DIM 3

#include "point/point.h"

int main()
{
    int dimension = DIM;
    float coordinates1[] = {0, 0, 0};
    float coordinates2[] = {1, 2, 3};
    int id_len = 1;
    char id1[] = "A";
    char id2[] = "B";
        
    Point *p1 = point_construct(dimension, coordinates1, id1, id_len);
    Point *p2 = point_construct(dimension, coordinates2, id2, id_len);

    double dist = two_points_distance(p1, p2);

    printf("%f\n", dist);

    point_destroy(p1);
    point_destroy(p2);
    
    return 0;
}