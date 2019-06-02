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

    for (unsigned int i = 0; i < graph.vertices.size() - 1; i++) {
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

    while (!Q.empty()) {
//        static auto k = -1;
//        std::cout << "p0: " << "extractMin()" << std::endl;
//        if (k == 974) Q.print();


        Vertex u = graph.vertices[Q.extractMin()];
//        k = u.id;

//        if (u.id == 974) std::cout << "p1: " << u.id << std::endl;


        for (auto &e : graph.getAdjacencyList(u.id)) {
            auto v = e.end;
            auto w = e.weight;

//            if (u.id == 974) std::cout << "p2: " << u.id << "," << e.end << std::endl;

            if (dist[v] > dist[u.id] + w) {
                dist[v] = dist[u.id] + w;
                pred[v] = u.id;
                Q.decreaseKey(v, w);
            }

//            if (u.id == 974) std::cout << "p3: " << u.id << "," << e.end << std::endl;
        }

//        std::cout << "p4: " << u.id << std::endl;
//        Q.print();
    }

//    std::cout << "p5: " << "finished" << std::endl;
}

template<class DS>
void dijkstra(const InputInfo &in, OutputInfo &out) {
    out.dist.emplace_back(in.graph.vertices.size(), std::numeric_limits<double>::infinity());
    out.pred.emplace_back(in.graph.vertices.size(), -1);

    dijkstra<DS>(in.graph, in.source, out.dist[0], out.pred[0]);

}

void floydWarshall(const Graph &graph, std::vector<std::vector<double>> &dist, std::vector<std::vector<int>> &pred) {
    auto n = graph.getMinAdjacencyMatrix().size();

    for (unsigned int k = 0; k < n; k++) {
        for (unsigned int i = 0; i < n; i++) {
            for (unsigned int j = 0; j < n; j++) {
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
void johnson(const InputInfo &in, OutputInfo &out) {
    in.source = -1;

    auto graph = in.graph;
    int id = graph.vertices.size();
    graph.insertVertex(id);
    for (unsigned int i = 0; i < in.graph.vertices.size(); i++) {
        graph.insertEdge(id, i, 0);
    }

    std::vector<double> dist(graph.vertices.size(), std::numeric_limits<double>::infinity());
    std::vector<int> pred(graph.vertices.size(), -1);
    bellmanFord(graph, id, dist, pred);

    for (auto &e : graph.edges) {
        e.weight = e.weight + dist[e.start] - dist[e.end];
    }

    auto n = in.graph.vertices.size();
    out.dist = std::vector<std::vector<double>>(n, std::vector<double>(n, std::numeric_limits<double>::infinity()));
    out.pred = std::vector<std::vector<int>>(n, std::vector<int>(n, -1));

    Graph g = in.graph;
    for (unsigned int i = 0; i < in.graph.edges.size(); i++) {
        g.edges[i].weight = graph.edges[i].weight;
    }

    for (auto &u : in.graph.vertices) {
        dijkstra<DS>(g, u.id, out.dist[u.id], out.pred[u.id]);
        for (auto &v : in.graph.vertices) {
            out.dist[u.id][v.id] = out.dist[u.id][v.id] + dist[v.id] - dist[u.id];
        }
    }
}

std::map<std::string, std::vector<Algorithm<InputInfo, OutputInfo>>> PathsApp::algorithmsMap() {
    std::map<std::string, std::vector<Algorithm<InputInfo, OutputInfo>>> algorithms;

    algorithms[BELLMAN_FORD].push_back(PathAlg("Bellman Ford", bellmanFord, "Simple Bellman Ford"));

    algorithms[DIJKSTRA].push_back(PathAlg("Dijkstra", dijkstra<ArrayHeap>, "Dijkstra with ArrayHeap"));
    algorithms[DIJKSTRA].push_back(PathAlg("Dijkstra", dijkstra<BinaryHeap>, "Dijkstra with BinaryHeap"));
    algorithms[DIJKSTRA].push_back(PathAlg("Dijkstra", dijkstra<FibonacciHeap>, "Dijkstra with FibonacciHeap"));

    algorithms[FLOYD_WARSHALL].push_back(PathAlg("Floyd Warshall", floydWarshall, "Simple Floyd Warshall"));

    algorithms[JOHNSON].push_back(PathAlg("Dijkstra", johnson<ArrayHeap>, "Johnson using Dijkstra with ArrayHeap"));
    algorithms[JOHNSON].push_back(PathAlg("Dijkstra", johnson<BinaryHeap>, "Johnson using Dijkstra with BinaryHeap"));
    algorithms[JOHNSON].push_back(
            PathAlg("Dijkstra", johnson<FibonacciHeap>, "Johnson using Dijkstra with FibonacciHeap"));

    return algorithms;
}

void PathsApp::createInputInfo(const std::string &text, InputInfo &in) {
    char *token;
    int n = strtol(text.c_str(), &token, 10);
    int m = strtol(token, &token, 10);
    int s = strtol(token, &token, 10);

    Graph graph(n, m);

    for (int i = 0; i < m; i++) {
        int v1 = strtol(token, &token, 10);
        int v2 = strtol(token, &token, 10);
        double w = strtod(token, &token);
        graph.insertEdge(v1, v2, w);
    }

    in.graph = graph;
    in.source = s;
}

void PathsApp::printOutput(const std::string &filePath, const InputInfo &in, const OutputInfo &out) {
//    int fd;
//    if ((fd = open(filePath.data(), O_CREAT | O_WRONLY) == -1)) {
//        throw std::invalid_argument("Incorrect output file path: \"" + filePath + "\"");
//    }
//    write(fd, text.str().data(), text.str().size());
//    close(fd);

    FILE *fp = fopen(filePath.data(), "w");
    if (fp == nullptr) {
        throw std::invalid_argument("Incorrect output file path: \"" + filePath + "\"");
    }

    if (in.source != -1) {
        fprintf(fp, "%s", printPath(filePath, out.dist[0], out.pred[0], in.source).data());
    } else {
        for (auto i = 0; i < in.graph.vertices.size(); i++) {
            fprintf(fp, "%s", printPath(filePath, out.dist[i], out.pred[i], i).data());
        }
    }
    fclose(fp);
}

std::string
PathsApp::printPath(const std::string &filePath, std::vector<double> dist, std::vector<int> pred, int source) {
    std::vector<int> path;
    std::stringstream text;

    for (int i = 0; i < pred.size(); i++) {
        path.clear();
        for (int v = i; v != source && v != -1; v = pred[v]) {
            path.insert(path.begin(), v);
        }
        path.insert(path.begin(), source);

        text << dist[i] << " ";
        for (int v : path) {
            text << v << " ";
        }
        text << std::endl;
    }

    return text.str();
}
