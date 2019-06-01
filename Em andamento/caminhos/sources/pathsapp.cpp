/**
 * Algoritmos em Grafos (MO412)
 *
 * @author: Kleber Kruger <kleberkruger@gmail.com>
 * @author: Felipe Barbosa <felipebarbosa@uft.edu.com>
 * @author: Rodrigo Kanehisa <rodrigokanehisa@gmail.com>
 */

#include "pathsapp.h"

void bellmanFord(const Graph &graph, int source, std::vector<double> &dist, std::vector<int> &pred) {
    dist[source] = 0;
    pred[source] = source;

    for (int i = 0; i < graph.vertices.size() - 1; i++) {
        for (auto e : graph.edges) {
            auto u = e.start;
            auto v = e.end;
            auto w = e.weight;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pred[v] = u;
            }
        }
    }

    for (auto e : graph.edges) {
        auto u = e.start;
        auto v = e.end;
        auto w = e.weight;

        if (dist[v] > (dist[u] + w)) {
            throw std::invalid_argument("Negative cycle"); // FIXME: verificar exceção mais adequada.
        }
    }
}

void bellmanFord(const InputInfo &in, OutputInfo &out) {
    out.dist.emplace_back(in.graph.vertices.size(), std::numeric_limits<double>::infinity());
    out.pred.emplace_back(in.graph.vertices.size(), -1);

    bellmanFord(in.graph, in.source, out.dist[0], out.pred[0]);
}

template<class DS>
void dijkstra(const Graph &graph, int source, std::vector<double> &dist, std::vector<int> &pred) {
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
    out.dist.emplace_back(in.graph.vertices.size(), std::numeric_limits<double>::infinity());
    out.pred.emplace_back(in.graph.vertices.size(), -1);

    dijkstra<DS>(in.graph, in.source, out.dist[0], out.pred[0]);
}

//std::vector<std::vector<int>> PredInit(const Graph &graph) {
//    auto adjMatrix = graph.getMinAdjacencyMatrix();
//
//    std::vector<std::vector<int>> pred;
//    std::vector<int> line(adjMatrix.size(), -1);
//
//    for (int i = 0; i < adjMatrix.size(); i++)
//        pred.emplace_back(line);
//
//    for (int i = 0; i < (int) adjMatrix.size(); i++) {
//        for (int j = 0; j < (int) adjMatrix.size(); j++) {
//            if (adjMatrix[i][j] != std::numeric_limits<double>::infinity() && i != j) {
//                pred[i][j] = i;
//            }
//        }
//    }
//
//    return pred;
//}

void floydWarshall(const Graph &graph, std::vector<std::vector<double>> &dist, std::vector<std::vector<int>> &pred) {
    auto n = graph.getMinAdjacencyMatrix().size();

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    pred[i][j] = pred[k][j];
                }
            }
        }
    }
}

void floydWarshall(const InputInfo &in, OutputInfo &out) {
    in.source = -1;

    int n = in.graph.vertices.size();
    std::vector<int> line(n, -1);
    for (int i = 0; i < n; i++)
        out.pred.emplace_back(line);

//    std::vector<std::vector<int>> vec(n, std::vector<int>(n, -1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (in.graph.getMinAdjacencyMatrix()[i][j] != std::numeric_limits<double>::infinity() && i != j) {
                out.pred[i][j] = i;
            }
        }
    }
    out.dist = in.graph.getMinAdjacencyMatrix();

    floydWarshall(in.graph, out.dist, out.pred);
}

template<class DS>
void johnson(const Graph &graph, std::vector<std::vector<double>> &dist, std::vector<std::vector<int>> &pred) {

}

template<class DS>
void johnson(const InputInfo &in, OutputInfo &out) {
    in.source = -1;

    int n = in.graph.vertices.size();
    std::vector<int> line(n, -1);
    for (int i = 0; i < n; i++)
        out.pred.emplace_back(line);

//    std::vector<std::vector<int>> vec(n, std::vector<int>(n, -1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (in.graph.getMinAdjacencyMatrix()[i][j] != std::numeric_limits<double>::infinity() && i != j) {
                out.pred[i][j] = i;
            }
        }
    }
    out.dist = in.graph.getMinAdjacencyMatrix();

    johnson<DS>(in.graph, out.dist, out.pred);
}

std::map<std::string, std::vector<Algorithm<InputInfo, OutputInfo>>> PathsApp::algorithmsMap() {
    std::map<std::string, std::vector<Algorithm<InputInfo, OutputInfo>>> algorithms;

    algorithms[BELLMAN_FORD].push_back(PathAlg("Bellman Ford", bellmanFord, "Simple Bellman Ford"));

    algorithms[DIJKSTRA].push_back(PathAlg("Dijkstra", dijkstra<ArrayHeap>, "Dijkstra with ArrayHeap"));
    algorithms[DIJKSTRA].push_back(PathAlg("Dijkstra", dijkstra<BinaryHeap>, "Dijkstra with BinaryHeap"));
    algorithms[DIJKSTRA].push_back(PathAlg("Dijkstra", dijkstra<FibonacciHeap>, "Dijkstra with FibonacciHeap"));

    algorithms[FLOYD_WARSHALL].push_back(PathAlg("Floyd Warshall", floydWarshall, "Simple Floyd Warshall"));

    algorithms[JOHNSON].push_back(PathAlg("Dijkstra", johnson<ArrayHeap>, "Dijkstra with ArrayHeap"));
    algorithms[JOHNSON].push_back(PathAlg("Dijkstra", johnson<BinaryHeap>, "Dijkstra with BinaryHeap"));
    algorithms[JOHNSON].push_back(PathAlg("Dijkstra", johnson<FibonacciHeap>, "Dijkstra with FibonacciHeap"));

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

void PathsApp::printOutput(const std::string &filePath, const InputInfo &in, const OutputInfo &out) {
    if (in.source != -1) {
        printPath(filePath, out.dist[0], out.pred[0], in.source);
    } else {
//        for (int i = 0; i < out.dist.size(); i++) {
//            printPath(filePath, out.dist[i], out.pred[i], i);
//        }
        std::cout << "Predecessores:" << std::endl;
        Graph::printMatrix(out.pred);

        std::cout << "Distâncias:" << std::endl;
        Graph::printMatrix(out.dist);
    }
}

void PathsApp::printPath(const std::string &filePath, std::vector<double> dist, std::vector<int> pred, int source) {
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
