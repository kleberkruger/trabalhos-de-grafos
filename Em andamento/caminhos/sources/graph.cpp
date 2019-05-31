/**
 * Algoritmos em Grafos (MO412)
 *
 * @author: Kleber Kruger <kleberkruger@gmail.com>
 * @author: Felipe Barbosa <felipebarbosa@uft.edu.com>
 * @author: Rodrigo Kanehisa <rodrigokanehisa@gmail.com>
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
                                    minAdjacencyMatrix(n, std::vector<double>(
                                            n, std::numeric_limits<double>::infinity())) {

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

void Graph::print() const {

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

void Graph::printAdjacencyList() const {
    std::cout << "==================================================" << std::endl;
    auto &list = getAdjacencyList();
    for (int i = 0; i < list.size(); ++i) {
        std::cout << "adjacency of " << i << ": ";
        for (auto &e : list[i]) {
            std::cout << e.end << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "==================================================" << std::endl;
}

void Graph::printAdjacencyMatrix() const {
    std::cout << "==================================================" << std::endl;
    auto &matrix = getMinAdjacencyMatrix();
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "==================================================" << std::endl;
}
