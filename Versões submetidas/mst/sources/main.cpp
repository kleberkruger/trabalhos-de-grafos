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
#include <cstring>
#include <iomanip>
#include <chrono>
#include "graph.h"
#include "arrayheap.h"

enum Algorithm {
    NONE = 0, KRUSKAL = 1, PRIM = 2
};

void execute(Algorithm alg, int version, const std::string &inFilePath, const std::string &outFilePath) {
    if (alg == NONE) {
        throw std::invalid_argument("Incorrect algorithm. Run in <algorithm>: <kruskal> or <prim>");
    }

//    struct TimeTask {
//        std::chrono::time_point start;
//        std::chrono::time_point end;
//    };

    int n, m, v1, v2;
    double w;

    auto start1 = std::chrono::steady_clock::now();

    // Lê o arquivo de entrada e cria o grafo original
    std::cout << "Reading input file and creating the graph..." << std::endl;
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

    auto end1 = std::chrono::steady_clock::now();

    auto start2 = std::chrono::steady_clock::now();

    // Executa o algoritmo de MST
    Graph mst;
    double total = Graph::mst(g, mst, alg - 1, version);

    auto end2 = std::chrono::steady_clock::now();
    std::cout << "Total MST: " << total << std::endl;
    std::cout << "Writing MST in the output file..." << std::endl;

    auto start3 = std::chrono::steady_clock::now();
    // Imprime a resposta no arquivo de saída
    std::ofstream outFile;
    outFile.open(outFilePath);
    outFile << std::fixed;
    outFile << total << std::endl;
    for (auto &e : mst.edges) {
        outFile << e.start << " " << e.end << " " << e.weight << std::endl;
    }
    outFile.close();
    std::cout << "Finished." << std::endl;

    auto end3 = std::chrono::steady_clock::now();

    std::cout << "Read input file time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1).count()
              << " ms" << std::endl;
    std::cout << "Run MST : "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2).count()
              << " ms" << std::endl;
    std::cout << "Write output file time : "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end3 - start3).count()
              << " ms" << std::endl;
}

int main(int argc, char *argv[]) {
//    chdir("/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/swap/grafos-t1-mst/mst");

    if (argc != 5) {
        throw std::invalid_argument("Run: <algorithm> <version> <filepath-in> <filepath-out>");
    }

    Algorithm alg = strcasecmp(argv[1], "prim") == 0 ? PRIM :
                    strcasecmp(argv[1], "kruskal") == 0 ? KRUSKAL : NONE;

    execute(alg, std::atoi(argv[2]), argv[3], argv[4]); // NOLINT(cert-err34-c)

    return EXIT_SUCCESS;
}
