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
                             adjacencyMatrix(n, std::vector<double>(n, std::numeric_limits<double>::infinity())) {

    for (int i = 0; i < n; i++) adjacencyMatrix[i][i] = 0;

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

const std::vector<std::vector<double>> &Graph::getAdjacencyMatrix() const {
    static bool exists = false;
    if (!exists) {
        for (auto &e : edges) {
            if (e.weight < adjacencyMatrix[e.start][e.end]) {
                adjacencyMatrix[e.start][e.end] = e.weight;
            }
        }
        exists = true;
    }
    return adjacencyMatrix;
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

            if (dist[u] != std::numeric_limits<int>::infinity() && dist[u] + w < dist[v]) {
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
