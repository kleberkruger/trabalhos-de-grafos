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
#include "graph.h"
#include "kruskal.h"

int main() {

    Graph g(11);
    g.insertEdge(0, 1, 1);
    g.insertEdge(1, 2, 2);
    g.insertEdge(0, 3, 2);
    g.insertEdge(0, 4, 6);
    g.insertEdge(1, 4, 5);
    g.insertEdge(1, 5, 3);
    g.insertEdge(1, 6, 9);
    g.insertEdge(2, 6, 7);
    g.insertEdge(2, 7, 9);
    g.insertEdge(3, 4, 8);
    g.insertEdge(4, 5, 1);
    g.insertEdge(5, 6, 6);
    g.insertEdge(6, 7, 2);
    g.insertEdge(3, 8, 1);
    g.insertEdge(4, 8, 7);
    g.insertEdge(4, 9, 2);
    g.insertEdge(5, 9, 4);
    g.insertEdge(6, 9, 3);
    g.insertEdge(6, 10, 1);
    g.insertEdge(7, 10, 4);
    g.insertEdge(8, 9, 9);
    g.insertEdge(9, 10, 1);
//    g.print();

    Graph mst;

    Kruskal<UnionFind> alg1;
    std::cout << alg1.execute(g, mst) << std::endl;
    mst.print();

    Kruskal<VetorBemBosta> alg2;
    std::cout << alg2.execute2(g, mst) << std::endl;
    mst.print();

    return 0;
}