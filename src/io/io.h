#ifndef IO_H
#define IO_H

#include "point.h"

Point **read_points(const char *filename, int *num_points);
void write_clusters(const char *filename, Clusters *c);

#endif