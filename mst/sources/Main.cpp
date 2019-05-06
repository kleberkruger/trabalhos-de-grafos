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
#include <zconf.h>
#include "Graph.h"

/**
 * Imprime a MST no arquivo de saída.
 *
 * @param mst
 * @param total
 * @param fileout
 */
void printMST(const Graph &mst, const float total, const std::string &fileout) {
    std::ofstream outfile;
    outfile.open(fileout);
    outfile << total << std::endl;
    for (int i = 0; i < 100; i++) {
        outfile << i << " " << i << " " << i << std::endl;
    }
    outfile.close();
}

int main(int argc, char *argv[]) {
    chdir("/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst");

    if (argc != 5) {
        throw std::invalid_argument("Run: <algorithm> <version> <filepath-in> <filepath-out>");
    }

    // Ler o arquivo usando uma função de conversão para o formato de entrada padrão deste trabalho.
    std::ifstream infile;
    infile.open(argv[3]);

    int n, m;
    infile >> n >> m;

    Graph g(n);

    for (int i = 0; i < m; i++) {
        int v1, v2;
        float w;

        infile >> v1 >> v2 >> w;
        g.insertEdge(v1, v2, w);
    }

    infile.close();

    Graph mst;
    float total = strcasecmp(argv[3], "prim") == 0 ?
                  Graph::prim(g, mst) :
                  strcasecmp(argv[3], "kruskal") == 0 ?
                  Graph::kruskal(g, mst) : 0;

    printMST(mst, total, argv[4]);

    return 0;
}