#ifndef IO_H
#define IO_H

#include "point.h"

Point **read_points(const char *filename, int *num_points);
void write_clusters(Point **points, int *components, int n, FILE *output);
void free_points(Point **points, int n);

#endif