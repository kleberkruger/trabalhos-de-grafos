/**
 * Algoritmos em Grafos (MO412)
 *
 * Primeiro Trabalho Prático
 * - MST - Minimum Spanning Tree
 *
 * @authors:
 * - Kleber Kruger <kleberkruger@gmail.com>,
 * - Felipe Barbosa <felipebarbosa@uft.edu.com>,
 * - Rodrigo Kanehisa <rodrigokanehisa@gmail.com>
 */

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <strings.h>
#include "graph.h"

enum Algorithm {
    NONE = 0, KRUSKAL = 1, PRIM = 2
};

void execute(Algorithm alg, int version, const std::string &inFilePath, const std::string &outFilePath) {
    if (alg == NONE) {
        throw std::invalid_argument("Incorrect algorithm. Run in <algorithm>: <kruskal> or <prim>");
    }

    int n, m, v1, v2;
    float w;

    // Lê o arquivo de entrada e cria o grafo original
    std::ifstream inFile;
    inFile.open(inFilePath);
    if (!inFile.good()) {
        throw std::invalid_argument("Arquivo \"" + inFilePath + "\" não encontrado");
    }

    inFile >> n >> m;
    Graph g(n, m);
    for (int i = 0; i < m; i++) {
        inFile >> v1 >> v2 >> w;
        g.insertEdge(v1, v2, w);
    }
    inFile.close();

    // Executa o algoritmo de MST
    Graph mst;
    double total = Graph::mst(g, mst, (alg - 1) * 3 + version);

    // Imprime a resposta no arquivo de saída
    std::ofstream outFile;
    outFile.open(outFilePath);
    outFile << total << std::endl;
    for (auto &e : mst.edges) {
        outFile << e.start << " " << e.end << " " << e.weight << std::endl;
    }
    outFile.close();
}

int main(int argc, char *argv[]) {
    //chdir("/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst");

    if (argc != 5) {
        throw std::invalid_argument("Run: <algorithm> <version> <filepath-in> <filepath-out>");
    }

    Algorithm alg = strcasecmp(argv[1], "prim") == 0 ? PRIM :
                    strcasecmp(argv[1], "kruskal") == 0 ? KRUSKAL : NONE;

    execute(alg, std::atoi(argv[2]), argv[3], argv[4]); // NOLINT(cert-err34-c)

    return EXIT_SUCCESS;
}