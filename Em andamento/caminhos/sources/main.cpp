/**
 * Algoritmos em Grafos (MO412)
 *
 * @author: Kleber Kruger <kleberkruger@gmail.com>
 * @author: Felipe Barbosa <felipebarbosa@uft.edu.com>
 * @author: Rodrigo Kanehisa <rodrigokanehisa@gmail.com>
 */

#include <iostream>
#include "pathsapp.h"

/**
 * Executa a aplicação de acordo com os parâmetros de inicialização.
 *
 * <algorithm> <version> <filepath-in> <filepath-out>
 *
 * <algorithm>: algoritmo de execução (Bellman Ford, Dijkstra, Floyd Warshall, Johnson");
 * <version>: versão do algoritmo (um número inteiro, começando em 0);
 * <filepath-in>: arquivo de entrada que contém as informações do grafo;
 * <filepath-out>: arquivo de saída onde será exibido o resultado.
 *
 * Exemplos:
 * ./main bellman-ford 0 dataset/ja9847_in.txt dataset/ja9847_out.txt
 * ./main dijkstra 0 dataset/ja9847_in.txt dataset/ja9847_out.txt
 * ./main floyd-warshall 0 dataset/ja9847_in.txt dataset/ja9847_out.txt
 * ./main johnson 0 dataset/ja9847_in.txt dataset/ja9847_out.txt
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

    PathsApp().start(argv[1], std::strtol(argv[2], nullptr, 10), argv[3], argv[4]);

    return 0;
}
