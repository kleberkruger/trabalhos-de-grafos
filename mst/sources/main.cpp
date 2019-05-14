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
#include "graph.h"
#include "arrayheap.h"

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

void arrayHeapTest() {

    ArrayHeap heap(11, 0);

    heap.decreaseKey(1, 13);
    heap.decreaseKey(2, 8);
    heap.decreaseKey(3, 4);
    heap.decreaseKey(4, 9);
    heap.decreaseKey(5, 1);
    heap.decreaseKey(6, 16);
    heap.decreaseKey(7, 11);
    heap.decreaseKey(8, 8);
    heap.decreaseKey(9, 2);
    heap.decreaseKey(10, 20);

    heap.print();
    std::cout << std::endl;

    std::cout << "extractMin = " << heap.extractMin() << std::endl;
    heap.print();
    std::cout << std::endl;

    heap.decreaseKey(10, 0);
    heap.print();

    std::cout << "extractMin = " << heap.extractMin() << std::endl;
    heap.print();
    std::cout << std::endl;

    std::cout << "extractMin = " << heap.extractMin() << std::endl;
    heap.print();
    std::cout << std::endl;

    std::cout << "extractMin = " << heap.extractMin() << std::endl;
    heap.print();
    std::cout << std::endl;

    std::cout << "extractMin = " << heap.extractMin() << std::endl;
    heap.print();
    std::cout << std::endl;

    std::cout << "extractMin = " << heap.extractMin() << std::endl;
    heap.print();
    std::cout << std::endl;

    std::cout << "extractMin = " << heap.extractMin() << std::endl;
    heap.print();
    std::cout << std::endl;

    std::cout << "extractMin = " << heap.extractMin() << std::endl;
    heap.print();
    std::cout << std::endl;

    std::cout << "extractMin = " << heap.extractMin() << std::endl;
    heap.print();
    std::cout << std::endl;

    std::cout << "extractMin = " << heap.extractMin() << std::endl;
    heap.print();
    std::cout << std::endl;

    std::cout << "extractMin = " << heap.extractMin() << std::endl;
    heap.print();
    std::cout << std::endl;

//    std::cout << "extractMin = " << heap.extractMin() << std::endl;
//    heap.print();
//    std::cout << std::endl;
}

void binaryHeapTest() {

    BinaryHeap heap(11, 0);
    std::cout << std::endl;

    heap.decreaseKey(6, 16);
    std::cout << std::endl;

    heap.decreaseKey(9, 2);
    std::cout << std::endl;

    heap.decreaseKey(3, 1);
    std::cout << std::endl;

    heap.decreaseKey(1, 13);
    std::cout << std::endl;

    heap.decreaseKey(4, 9);
    std::cout << std::endl;

    heap.decreaseKey(2, 8);
    std::cout << std::endl;

    heap.decreaseKey(5, 1);
    std::cout << std::endl;

    heap.decreaseKey(8, 8);
    std::cout << std::endl;

    heap.decreaseKey(7, 11);
    std::cout << std::endl;

    heap.decreaseKey(10, 20);
    std::cout << std::endl;
}

int main(int argc, char *argv[]) {
    chdir("/Volumes/KrugerDrive/kleberkruger/Clouds/Box Sync/SourceCode/Git/GitHub/Disciplinas/Algoritmos em Grafos/grafos-t1-mst/mst");

    if (argc != 5) {
        throw std::invalid_argument("Run: <algorithm> <version> <filepath-in> <filepath-out>");
    }

    Algorithm alg = strcasecmp(argv[1], "prim") == 0 ? PRIM :
                    strcasecmp(argv[1], "kruskal") == 0 ? KRUSKAL : NONE;

    execute(alg, std::atoi(argv[2]), argv[3], argv[4]); // NOLINT(cert-err34-c)
//    binaryHeapTest();

    return EXIT_SUCCESS;
}
