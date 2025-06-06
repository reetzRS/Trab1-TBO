#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "point/point.h"
#include "graph/graph.h"
#include "union_find/union_find.h"
#include "kruskal/kruskal.h"
#include "io/io.h"


int main(int argc, char *argv[])
{   // Testa se a linha de comando contém a quantidade de argumentos correta
    if (argc != 4) {
        perror("Uso: ./trab1 <entrada> <k> <saida>\n");
        exit(1);
    }
    // Converte a string da linha de comando para o inteiro k
    int k = atoi(argv[2]);
    int num_points;

    // Leitura dos dados
    Point **points = read_points(argv[1], &num_points);
    if (k < 1 || k > num_points) {
        perror("Valor de k inválido!\n");
        exit(1);
    }

    // Cálculo de distâncias e ordenações
    Graph *g = graph_construct(points, num_points);

    // Algoritmo de Kruskal e obtenção da MST
    Mst *m = kruskal(g, k);

    // Agrupamento
    Clusters *c = clustering(m, k);

    // Escrita do arquivo de saída
    write_clusters(argv[3], c);

    // Desalocação das estruturas restantes
    graph_destroy(g);
    mst_destroy(m);
    clusters_destroy(c);

    return 0;
}