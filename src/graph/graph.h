#ifndef _GRAPH_H
#define _GRAPH_H

#include "../point/point.h"

typedef struct graph Graph;

/**
 * @brief Constrói a estrutura de grafo com os vértices.
 *
 * @param vertices Vetor de pontos, que representam os vértices do grafo
 * @param size Quantidade de vértices do grafo.
 * @return Grafo inicializado com os vértices
 */
Graph *graph_construct(Point **vertices, int size);

#endif