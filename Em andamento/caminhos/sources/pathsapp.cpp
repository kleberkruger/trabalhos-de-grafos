/**
 * Algoritmos em Grafos (MO412)
 *
 * @author: Kleber Kruger <kleberkruger@gmail.com>
 * @author: Felipe Barbosa <felipebarbosa@uft.edu.com>
 * @author: Rodrigo Kanehisa <rodrigokanehisa@gmail.com>
 */

#include "pathsapp.h"

template<class DS>
void dijkstra(const InputInfo &in, OutputInfo &out) {
    std::cout << "executando o Dijkstra a partir do " << in.source << std::endl;
    in.graph.print();
}

std::map<std::string, std::vector<Algorithm<InputInfo, OutputInfo>>> PathsApp::algorithmsMap() {
    std::map<std::string, std::vector<Algorithm<InputInfo, OutputInfo>>> algorithms;

    algorithms[BELLMAN_FORD].push_back(PathAlg("Bellman Ford", dijkstra<BinaryHeap>, "Simple Bellman Ford"));
    algorithms[DIJKSTRA].push_back(PathAlg("Dijkstra", dijkstra<BinaryHeap>, "Simple Dijkstra"));
    algorithms[FLOYD_WARSHALL].push_back(PathAlg("Floyd Warshall", dijkstra<BinaryHeap>, "Simple Floyd Warshall"));
    algorithms[JOHNSON].push_back(PathAlg("Johnson", dijkstra<BinaryHeap>, "Simple Johnson"));

    return algorithms;
}

void PathsApp::createInputInfo(const std::string &text, InputInfo &in) {
    char *token;
    int n = strtol(text.c_str(), &token, 10);
    int m = strtol(token, &token, 10);
    int s = strtol(token, &token, 10);

    Graph graph(n, m);

    for (int i = 0; i < m; i++) {
        graph.insertEdge(strtol(token, &token, 10), strtol(token, &token, 10), strtod(token, &token));
    }

    in.graph = graph;
    in.source = s;
}

void PathsApp::printOutput(OutputInfo output) {
    std::cout << "eu venci" << std::endl;
}
