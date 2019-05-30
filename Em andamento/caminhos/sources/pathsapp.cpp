/**
 * Algoritmos em Grafos (MO412)
 *
 * @author: Kleber Kruger <kleberkruger@gmail.com>
 * @author: Felipe Barbosa <felipebarbosa@uft.edu.com>
 * @author: Rodrigo Kanehisa <rodrigokanehisa@gmail.com>
 */

#include "pathsapp.h"

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

std::map<std::string, std::vector<Algorithm>> PathsApp::algorithmsMap() {
    std::map<std::string, std::vector<Algorithm>> algorithms;

    algorithms[BELLMAN_FORD].push_back(Algorithm("Bellman Ford", PathsAlg::dijkstra, "Simple Bellman Ford"));
    algorithms[DIJKSTRA].push_back(Algorithm("Dijkstra", PathsAlg::dijkstra, "Simple Dijkstra"));
    algorithms[FLOYD_WARSHALL].push_back(Algorithm("Floyd Warshall", PathsAlg::dijkstra, "Simple Floyd Warshall"));
    algorithms[JOHNSON].push_back(Algorithm("Johnson", PathsAlg::dijkstra, "Simple Johnson"));

    return algorithms;
}
