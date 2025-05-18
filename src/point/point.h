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
 * @returns Ponteiro para o ponto com coordenada e identificador atribuídos.
 */
Point *point_construct(int dimension, double *coordinate, char *id, int id_len);

/**
 * @brief Retorna a dimensão do ponto.
 *
 * @param p Ponto que vai ter a dimensão retornada.
 * @returns Dimensão do ponto.
 */
int get_dimension_point(Point *p);

/**
 * @brief Retorna as coordenadas do ponto.
 *
 * @param p Ponto que vai ter as coordenadas retornadas.
 * @return Coordenadas do ponto.
 */
double *get_coordinate_point(Point *p);

/**
 * @brief Retorna o ID único do ponto
 *
 * @param p Ponto que vai ter o ID retornado.
 * @return ID único do ponto.
 */
char *get_id_point(Point *p);

/**
 * @brief Retorna o tamanho do ID único do ponto.
 *
 * @param p Ponto que vai ter o tamanho do ID retornado.
 * @return Tamanho do ID do ponto.
 */
int get_id_len_point(Point *p);

/**
 * @brief Retorna a distância euclidiana entre dois pontos
 *
 * @param p1 Ponto 1.
 * @param p2 Ponto 2.
 * @return Distância euclidiana entre os dois pontos passados como parâmetro
 */
double two_points_distance(Point *p1, Point *p2);

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