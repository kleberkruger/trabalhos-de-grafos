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

enum AlgorithmName {
    NONE = 0, BELLMANFORD = 1, DIJKSTRA = 2, FLOYDWARSHALL = 3, JOHNSON = 4
};

enum AlgorithmName valueOfEnum(const std::string &algorithm) {
    return strcasecmp(algorithm.data(), "bellman-ford") == 0 ? BELLMANFORD :
           strcasecmp(algorithm.data(), "dijkstra") == 0 ? DIJKSTRA :
           strcasecmp(algorithm.data(), "floyd-warshall") == 0 ? FLOYDWARSHALL :
           strcasecmp(algorithm.data(), "johnson") == 0 ? JOHNSON : NONE;
}


Algorithm PathsApp::selectAlgorithm(const std::string &algorithm, int version) {
    static Algorithm bellmanFords[] = {
            Algorithm("Bellman Ford", 0, dijkstra, "Simple Bellman Ford"),
    };
    static Algorithm dijkstras[] = {
            Algorithm("Dijkstra", 0, dijkstra, "Simple Dijkstra"),
            Algorithm("Dijkstra", 0, dijkstra, "Simple Dijkstra"),
    };
    static Algorithm floydWarshalls[] = {
            Algorithm("Floyd Warshall", 0, dijkstra, "Simple Floyd Warshall"),
    };
    static Algorithm johnsons[] = {
            Algorithm("Johnson", 0, dijkstra, "Simple Johnson"),
    };

    static std::vector<Algorithm *> algorithms = {bellmanFords, dijkstras, floydWarshalls, johnsons};

    return algorithms[valueOfEnum(algorithm) - 1][version];
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
