/**
 * Algoritmos em Grafos (MO412)
 *
 * @author: Kleber Kruger <kleberkruger@gmail.com>
 * @author: Felipe Barbosa <felipebarbosa@uft.edu.com>
 * @author: Rodrigo Kanehisa <rodrigokanehisa@gmail.com>
 */

#include "pathsapp.h"

AlgorithmOutput dijkstra(const Graph &g) {
    std::cout << "executando o Dijkstra" << std::endl;
    return AlgorithmOutput();
}

Algorithm PathsApp::selectAlgorithm(const std::string &algorithm, int version) {
    Algorithm alg("Dijkstra", 0, dijkstra, "Simple Dijkstra");
    return alg;
}

Graph PathsApp::createGraph(const std::string &input) {
    char *token;
    int n = strtol(input.c_str(), &token, 10);
    int m = strtol(token, &token, 10);
    int s = strtol(token, &token, 10);

    Graph graph(n, m);

    for (int i = 0; i < m; i++) {
        graph.insertEdge(strtol(token, &token, 10), strtol(token, &token, 10), strtod(token, &token));
    }

    return graph;
}

void PathsApp::printOutput(AlgorithmOutput output) {

}
