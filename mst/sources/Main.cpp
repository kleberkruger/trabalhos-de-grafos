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

#include "Graph.h"

int main() {

    Graph g(3, 4);
    g.insertEdge(0, 1, 4);
    g.insertEdge(0, 2, 2);
    g.insertEdge(1, 2, 3);
    g.insertEdge(1, 2, 1);

    Graph mst;
    Graph::kruskal(g, mst);

    return 0;
}
