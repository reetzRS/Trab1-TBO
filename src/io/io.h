#ifndef IO_H
#define IO_H

#include "../point/point.h"
#include "../kruskal/kruskal.h"

/**
 * @brief Faz a leitura do arquivo de entrada e retorna a lista de pontos
 * 
 * @param filename Nome do arquivo de entrada contendo os pontos
 * @param num_points Número de pontos lidos
 * @return Lista de pontos, com seus IDs e valores
 * 
 * A função lê linha a linha, atribuindo os valores para um elemento da lista
 * de pontos e no final retorna a estrutura completa.
 */
Point **read_points(const char *filename, int *num_points);

/**
 * @brief Escreve os clusters no arquivo de saída
 * 
 * @param filename Nome do arquivo de saída
 * @param c Lista com os clusters a serem escritos no arquivo
 */
void write_clusters(const char *filename, Clusters *c);

#endif