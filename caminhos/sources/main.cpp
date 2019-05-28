#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <cstring>
#include <sstream>
#include <fstream>
#include <sys/ioctl.h>
#include "application.h"

/**
 * Executa a aplicação de acordo com os parâmetros de inicialização.
 *
 * <algorithm> <version> <filepath-in> <filepath-out>
 *
 * <algorithm>: algoritmo de execução (Kruskal ou Prim);
 * <version>: versão do algoritmo (um número inteiro, começando em 0);
 * <filepath-in>: arquivo de entrada que contém as informações do grafo;
 * <filepath-out>: arquivo de saída onde será exibida a MST resultante.
 *
 * Exemplos:
 * ./main kruskal 0 dataset/ja9847_in.txt dataset/ja9847_out.txt
 * ./main prim 0 dataset/ja9847_in.txt dataset/ja9847_out.txt
 *
 * @param argc quantidade de parâmetros
 * @param argv valores dos parâmetros
 *
 * @return 0 caso execute com sucesso; outro valor caso ocorra algum erro.
 */
int main(int argc, char *argv[]) {
    if (argc != 5) {
        throw std::invalid_argument("Run: <algorithm> <version> <filepath-in> <filepath-out>");
    }

    Algorithm alg = strcasecmp(argv[1], "bellman-ford") == 0 ? BELLMANFORD :
                    strcasecmp(argv[1], "dijkstra") == 0 ? DIJKSTRA :
                    strcasecmp(argv[1], "floyd-warshall") == 0 ? FLOYDWARSHALL :
                    strcasecmp(argv[1], "johnson") == 0 ? JOHNSON :NONE;

    int version = std::strtol(argv[2], nullptr, 10);

    Application().start(alg, version, argv[3], argv[4]);

    return EXIT_SUCCESS;
}