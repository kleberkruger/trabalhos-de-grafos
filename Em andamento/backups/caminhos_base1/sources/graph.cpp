#include <utility>

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

#include "graph.h"


//Vertex::Vertex(int id, std::size_t adjCapacity) : id(id) {
Vertex::Vertex(int id) : id(id) {
//    adjacency.reserve(adjCapacity);
}


Edge::Edge(int start, int end, double weight) : start(start), end(end), weight(weight) {}

EdgeTo::EdgeTo(int end, double weight) : end(end), weight(weight) {}

EdgeTo::~EdgeTo() = default;


Graph::Graph(int n, int m) : adjacencyList(n),
                             minAdjacencyMatrix(n, std::vector<double>(n, std::numeric_limits<double>::infinity())) {

    for (int i = 0; i < n; i++) minAdjacencyMatrix[i][i] = 0;

    vertices.reserve(n);
    edges.reserve(m);

    // FIXME: Ajustando a capacidade inicial para (n -1), mas e se o grafo não for completo? (desperdício de memória?)
//    std::size_t adjCapacity = n - 1;
//    for (int i = 0; i < n; i++) insertVertex(i, adjCapacity);
    for (int i = 0; i < n; i++) insertVertex(i);
}

Graph::Graph(const Graph &orig) = default;

Graph::~Graph() = default;

//void Graph::insertVertex(int id, std::size_t adjCapacity) {
void Graph::insertVertex(int id) {
//    vertices.emplace_back(id, adjCapacity);
    vertices.emplace_back(id);
}

void Graph::insertEdge(int v1, int v2, double weight) {
    edges.emplace_back(v1, v2, weight);

//    vertices[v1].adjacency.emplace_back(v2, weight);
//    vertices[v2].adjacency.emplace_back(v1, weight);
}

void Graph::clearEdges() {
    edges.clear();
}

void Graph::clearAll() {
    edges.clear();
    vertices.clear();
}

const std::vector<std::vector<EdgeTo>> &Graph::getAdjacencyList() const {
    static bool exists = false;
    if (!exists) {
        for (auto &e : edges) {
            adjacencyList[e.start].push_back(EdgeTo(e.end, e.weight));
        }
        exists = true;
    }
    return adjacencyList;
}

const std::vector<EdgeTo> &Graph::getAdjacencyList(int vertex) const {
    return getAdjacencyList()[vertex];
}

const std::vector<std::vector<double>> &Graph::getMinAdjacencyMatrix() const {
    static bool exists = false;
    if (!exists) {
        for (auto &e : edges) {
            if (e.weight < minAdjacencyMatrix[e.start][e.end]) {
                minAdjacencyMatrix[e.start][e.end] = e.weight;
            }
        }
        exists = true;
    }
    return minAdjacencyMatrix;
}

void Graph::print() {

    std::cout << "==================================================" << std::endl
              << " Print Graph: " << this << std::endl
              << "--------------------------------------------------" << std::endl
              << " Edges:\t|V|= " << vertices.size() << "\t|E|= " << edges.size() << std::endl;

    if (!edges.empty()) {
        std::cout << "--------------------------------------------------" << std::endl;
        for (auto e : edges)
            std::cout << " (v" << e.start << ", v" << e.end << ") w(" << e.weight << ")" << std::endl;
    }

    std::cout << "==================================================" << std::endl;
}

void Graph::BellmanFord(const Graph &graph, int source, std::vector<float> &dist, std::vector<int> &pred) {
    dist[source] = 0;
    pred[source] = source;

    for (int i = 0; i < graph.vertices.size() - 1; i++) {
        for (auto e : graph.edges) {
            auto u = e.start;
            auto v = e.end;
            auto w = e.weight;

//            if (dist[u] != std::numeric_limits<int>::infinity() && dist[u] + w < dist[v]) {
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

        if (dist[u] != std::numeric_limits<int>::infinity() && dist[u] + w < dist[v]) {
            throw std::invalid_argument("Negative cycle"); // FIXME: verificar exceção mais adequada.
        }
    }
}

void Graph::BellmanFord(const Graph &graph, int source) {
    struct BellmanFordVertex {
        float dist;
        int pred;

        BellmanFordVertex() : dist(std::numeric_limits<float>::infinity()), pred(-1) {}
    };

    std::vector<BellmanFordVertex> vertices(graph.vertices.size());
    vertices[source].dist = 0;

    for (int i = 0; i < graph.vertices.size() - 1; i++) {
        for (auto e : graph.edges) {
            auto &u = vertices[e.start];
            auto &v = vertices[e.end];
            auto w = e.weight;

            if (v.dist > u.dist + w) {
                v.dist = u.dist + w;
                v.pred = e.start; // u
            }
        }
    }

    for (auto e: graph.edges) {
        auto &u = vertices[e.start];
        auto &v = vertices[e.end];
        auto w = e.weight;

        if (v.dist > u.dist + w) {
            throw std::invalid_argument("Negative cycle"); // FIXME: verificar exceção mais adequada.
        }
    }
//    for (int i = 0; i < vertices.size(); i++) {
//        auto v = vertices[i];
//        std::cout << i << ": " << v.dist << " " << v.pred << " " << std::endl;
//    }
}

//template<class DS>
//void Graph::Dijkstra(const Graph &graph, int source, std::vector<float> &dist, std::vector<int> &pred) {
//
//}
//
//template<class DS>
//void Graph::Dijkstra(const Graph &graph, int source) {
//
//}

template<class DS>
void Graph::Dijkstra(const Graph &graph, int source, std::vector<float> &dist, std::vector<int> &pred) {
    DS Q(graph.vertices.size(), source);

    dist[source] = 0;
    pred[source] = source;

    while (!Q.empty()) {
        Vertex u = graph.vertices[Q.extractMin()];

        for (auto &e : graph.getAdjacencyList(u.id)) {
            auto v = e.end;
            auto w = e.weight;

//            if (dist[u.id] != std::numeric_limits<int>::infinity() && dist[u.id] + w < dist[v]) {
            if (dist[v] > dist[u.id] + w) {
                dist[v] = dist[u.id] + w;
                pred[v] = u.id;
                Q.decreaseKey(v, w);
            }
        }
    }
}

template<class DS>
void Graph::Dijkstra(const Graph &graph, int source) {

}

void Graph::path(const Graph &graph, int source, std::vector<float> &dist, std::vector<int> &pred) {
    Dijkstra<BinaryHeap>(graph, source, dist, pred);
}

void Graph::Johnson(const Graph &graph, std::vector<float> &dist, std::vector<int> &pred) {
    Graph copy = graph;
    auto id = graph.vertices.size();
    copy.insertVertex(graph.vertices.size());

    for (auto v : graph.vertices) {
        copy.insertEdge(id, v.id, 0);
    }

    BellmanFord(copy, id, dist, pred);

    for (auto u : copy.vertices) {
        for (auto v : copy.vertices) {

        }
    }
}

//template<class DS>
//double Graph::prim(const Graph &graph, Graph &mst) {
//    struct PrimVertex {
//        bool isPresent;
//        int parent;
//        double value;
//    };
//
//    mst = Graph(graph.vertices.size(), graph.vertices.size() - 1);
//
//    std::vector<PrimVertex> vertices(graph.vertices.size());
//    DS ds(mst.vertices.size(), 0);
//
//    for (auto &v : vertices) {
//        v.isPresent = true;
//        v.parent = -1;
//        v.value = std::numeric_limits<double>::infinity();
//    }
//    vertices[0].value = 0;
//
//    double total = 0;
//
//    while (!ds.empty()) {
//
//        Vertex u = graph.vertices[ds.extractMin()];
//        vertices[u.id].isPresent = false;
//
//        for (auto &e : graph.getAdjacencyList(u.id)) {
//            int v = e.end;
//            if (vertices[v].isPresent && e.weight < vertices[v].value) {
//                vertices[v].parent = u.id;
//
//                ds.decreaseKey(v, e.weight);
//                vertices[v].value = e.weight;
//            }
//        }
//
//        if (vertices[u.id].parent != -1) {
//            mst.insertVertex(u.id);
//            mst.insertEdge(vertices[u.id].parent, u.id, vertices[u.id].value);
//            total += vertices[u.id].value;
//        }
//    }
//
//    return total;
//}