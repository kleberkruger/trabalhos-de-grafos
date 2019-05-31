/**
 * Algoritmos em Grafos (MO412)
 *
 * @author: Kleber Kruger <kleberkruger@gmail.com>
 * @author: Felipe Barbosa <felipebarbosa@uft.edu.com>
 * @author: Rodrigo Kanehisa <rodrigokanehisa@gmail.com>
 */

#include "pathsapp.h"

template<class DS>
void dijkstra(const Graph &graph, int source, std::vector<float> &dist, std::vector<int> &pred) {
    DS Q(graph.vertices.size(), source);

    dist[source] = 0;
    pred[source] = source;

    for (int i = 0; i < graph.vertices.size(); i++) {
        std::cout << i << ": " << dist[i] << " " << pred[i] << " " << std::endl;
    }

    std::cout << "donde estás" << std::endl;

    while (!Q.empty()) {
        Vertex u = graph.vertices[Q.extractMin()];
        for (auto &e : graph.getAdjacencyList(u.id)) {
            std::cout << "pegando adjacentes do " << u.id << ": " << e.end << std::endl;
            auto v = e.end;
            auto w = e.weight;

            if (dist[v] > dist[u.id] + w) {
                dist[v] = dist[u.id] + w;
                pred[v] = u.id;
                Q.decreaseKey(v, w);
            }
        }
    }

    for (int i = 0; i < graph.vertices.size(); i++) {
        std::cout << i << ": " << dist[i] << " " << pred[i] << " " << std::endl;
    }
}

template<class DS>
AlgorithmOutput dijkstra(const Graph &graph, int source) {
    AlgorithmOutput output;
    output.dist.emplace_back(graph.vertices.size(), std::numeric_limits<float>::infinity());
    output.pred.emplace_back(graph.vertices.size(), -1);

    for (int i = 0; i < output.dist.size(); ++i) {
        for (int j = 0; j < output.dist[i].size(); ++j) {
            std::cout << output.dist[i][j] << " ";
        }
        std::cout << std::endl;
    }

    dijkstra<DS>(graph, source, output.dist[0], output.pred[0]);

    return output;
}

std::map<std::string, std::vector<Algorithm>> PathsApp::algorithmsMap() {
    std::map<std::string, std::vector<Algorithm>> algorithms;

    algorithms[BELLMAN_FORD].push_back(Algorithm("Bellman Ford", dijkstra<BinaryHeap>, "Simple Bellman Ford"));

    algorithms[DIJKSTRA].push_back(Algorithm("Dijkstra", dijkstra<BinaryHeap>, "Simple Dijkstra"));
    algorithms[DIJKSTRA].push_back(Algorithm("Dijkstra", dijkstra<BinaryHeap>, "Simple Dijkstra"));

    algorithms[FLOYD_WARSHALL].push_back(Algorithm("Floyd Warshall", dijkstra<BinaryHeap>, "Simple Floyd Warshall"));

    algorithms[JOHNSON].push_back(Algorithm("Johnson", dijkstra<BinaryHeap>, "Simple Johnson"));

    return algorithms;
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
