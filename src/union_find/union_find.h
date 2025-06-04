#ifndef UNION_FIND_H
#define UNION_FIND_H

typedef struct union_find UnionFind;

/**
 * @brief Inicializa a estrutura de Union-Find
 * 
 * @param n Quantidade de elementos a serem lidos
 * @return Estrutura inicializada para receber as operações de union/find
 */
UnionFind *uf_create(int n);

/**
 * @brief Função que busca a raíz de um elemento
 * 
 * @param uf Estrutura de Union-Find
 * @param i Índice do elemento que terá a raiz retornada
 * @return Retorna o valor do índice da raiz do ponto i
 */
int uf_find(UnionFind *uf, int i);

/**
 * @brief Une dois elementos não conectados
 * 
 * @param uf Estrutura de Union-Find
 * @param i Elemento i a ser unido
 * @param j Elemento j a ser unido
 */
void uf_union(UnionFind *uf, int i, int j);

/**
 * @brief Desaloca a estrutura de Union-Find
 * 
 * @param uf Estrutura de Union-Find a ser liberada
 */
void uf_destroy(UnionFind *uf);

#endif