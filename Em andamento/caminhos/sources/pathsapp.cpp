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

    while (!Q.empty()) {
        Vertex u = graph.vertices[Q.extractMin()];
        for (auto &e : graph.getAdjacencyList(u.id)) {
            auto v = e.end;
            auto w = e.weight;

            if (dist[v] > dist[u.id] + w) {
                dist[v] = dist[u.id] + w;
                pred[v] = u.id;
                Q.decreaseKey(v, w);
            }
        }
    }
}

template<class DS>
void dijkstra(const InputInfo &in, OutputInfo &out) {
    out.dist.emplace_back(in.graph.vertices.size(), std::numeric_limits<float>::infinity());
    out.pred.emplace_back(in.graph.vertices.size(), -1);

    dijkstra<DS>(in.graph, in.source, out.dist[0], out.pred[0]);
}

std::map<std::string, std::vector<Algorithm<InputInfo, OutputInfo>>> PathsApp::algorithmsMap() {
    std::map<std::string, std::vector<Algorithm<InputInfo, OutputInfo>>> algorithms;

    algorithms[BELLMAN_FORD].push_back(PathAlg("Bellman Ford", dijkstra<BinaryHeap>, "Simple Bellman Ford"));

    algorithms[DIJKSTRA].push_back(PathAlg("Dijkstra", dijkstra<ArrayHeap>, "Dijkstra with ArrayHeap"));
    algorithms[DIJKSTRA].push_back(PathAlg("Dijkstra", dijkstra<BinaryHeap>, "Dijkstra with BinaryHeap"));
    algorithms[DIJKSTRA].push_back(PathAlg("Dijkstra", dijkstra<FibonacciHeap>, "Dijkstra with FibonacciHeap"));

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

void PathsApp::printOutput(const InputInfo &in, const OutputInfo &out) {
    if (in.source != -1) {
        printPath(out.dist[0], out.pred[0], in.source);
    } else {
        for (int i = 0; i < out.dist.size(); i++) {
            printPath(out.dist[i], out.pred[i], i);
        }
    }
}

void PathsApp::printPath(std::vector<float> dist, std::vector<int> pred, int source) {
    std::vector<int> path;

    for (int i = 0; i < pred.size(); i++) {
        path.clear();
        for (int v = i; v != source; v = pred[v]) {
            path.insert(path.begin(), v);
        }
        path.insert(path.begin(), source);

        std::cout << "(" << i << ") = " << dist[i] << " path ";
        for (int v : path) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }
}
