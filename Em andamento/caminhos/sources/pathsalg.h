/**
 * Algoritmos em Grafos (MO412)
 *
 * @author: Kleber Kruger <kleberkruger@gmail.com>
 * @author: Felipe Barbosa <felipebarbosa@uft.edu.com>
 * @author: Rodrigo Kanehisa <rodrigokanehisa@gmail.com>
 */

#ifndef CAMINHOS_PATHSALG_H
#define CAMINHOS_PATHSALG_H


#include "graph.h"
#include "application.h"

class PathsAlg {
public:

    static AlgorithmOutput dijkstra(const Graph &graph);

    static void BellmanFord(const Graph &graph, int source, std::vector<float> &dist, std::vector<int> &pred);

    static void BellmanFord(const Graph &graph, int source = 0);

    template<class DS>
    static void Dijkstra(const Graph &graph, int source, std::vector<float> &dist, std::vector<int> &pred);

    template<class DS>
    static void Dijkstra(const Graph &graph, int source = 0);

    static void Johnson(const Graph &graph, std::vector<float> &dist, std::vector<int> &pred);
};


#endif //CAMINHOS_PATHSALG_H
