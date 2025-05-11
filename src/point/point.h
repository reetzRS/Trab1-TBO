#ifndef _PONTO_H
#define _PONTO_H

typedef struct point Point;

/**
 * @brief Função que aloca a memória e recebe os dados do ponto.
 *
 * @param dimension Valor da dimensão do ponto.
 * @param coordinate Vetor com as coordenadas do ponto.
 * @param id Identificador único do ponto.
 * @param id_len Tamanho do identificador do ponto.
 * @returns Ponteiro para o ponto com coordenada e identificador atribuídos
 */
Point *point_construct(int dimension, int *coordinate, char *id, int id_len);

/**
 * @brief Função que libera o espaço alocado para o ponto.
 *
 * @param p: Ponteiro para o ponto a ser liberado.
 *
 * Aqui serão liberados o vetor de coordenadas, o identificador único e o
 * ponto propriamente dito.
 */
void point_destroy(Point *p);

#endif