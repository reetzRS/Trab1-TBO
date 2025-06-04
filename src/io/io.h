#ifndef IO_H
#define IO_H

#include "../point/point.h"
#include "../kruskal/kruskal.h"

Point **read_points(const char *filename, int *num_points);
void write_clusters(const char *filename, Clusters *c);

#endif