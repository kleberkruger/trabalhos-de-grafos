/**
 * Algoritmos em Grafos (MO412)
 *
 * @author: Kleber Kruger <kleberkruger@gmail.com>
 * @author: Felipe Barbosa <felipebarbosa@uft.edu.com>
 * @author: Rodrigo Kanehisa <rodrigokanehisa@gmail.com>
 */

#include "graph.h"


Vertex::Vertex(int id) : id(id) {}


Edge::Edge(int start, int end, int capacity) : start(start), end(end), capacity(capacity) {}

EdgeTo::EdgeTo(int end, int capacity) : end(end), capacity(capacity) {}

EdgeTo::~EdgeTo() = default;


Graph::Graph(int n, int m) : updatedList(false), updatedMatrix(false) {
    vertices.reserve(n);
    edges.reserve(m);

    for (int i = 0; i < n; i++) insertVertex(i);
}

Graph::Graph(const Graph &orig) = default;

Graph::~Graph() = default;

void Graph::insertVertex(int id) {
    vertices.emplace_back(id);
    graphChanged();
}

void Graph::insertEdge(int v1, int v2, int weight) {
    edges.emplace_back(v1, v2, weight);
    graphChanged();
}

void Graph::clearEdges() {
    edges.clear();
    graphChanged();
}

void Graph::clearAll() {
    edges.clear();
    vertices.clear();
    graphChanged();
}

const std::vector<std::vector<EdgeTo>> &Graph::getAdjacencyList() const {
    if (!updatedList) {
        // alocação de espaço e inicialização
        unsigned int n = vertices.size();
        adjacencyList.clear();
        adjacencyList.reserve(n);
        for (unsigned int i = 0; i < n; i++) {
            adjacencyList.emplace_back();
            adjacencyList[i].reserve(n); // otimização
        }

        // definição dos valores
        for (auto &e : edges) {
            adjacencyList[e.start].push_back(EdgeTo(e.end, e.capacity));
        }
        updatedList = true;
    }
    return adjacencyList;
}

const std::vector<EdgeTo> &Graph::getAdjacencyList(int vertex) const {
    return getAdjacencyList()[vertex];
}

const std::vector<std::vector<EdgeTo>> &Graph::getMinAdjacencyList() const {
    return getAdjacencyList();
}

const std::vector<EdgeTo> &Graph::getMinAdjacencyList(int vertex) const {
    return getAdjacencyList()[vertex];
}

const std::vector<std::vector<int>> &Graph::getMinAdjacencyMatrix() const {
    if (!updatedMatrix) {
        // alocação de espaço e inicialização
        unsigned int n = vertices.size();
        minAdjacencyMatrix.clear();
        minAdjacencyMatrix.reserve(n);
        for (unsigned int i = 0; i < n; i++) {
            minAdjacencyMatrix.emplace_back(n, std::numeric_limits<double>::infinity());
            minAdjacencyMatrix[i][i] = 0;
        }

        // definição dos valores
        for (auto &e : edges) {
            if (e.capacity < minAdjacencyMatrix[e.start][e.end]) {
                minAdjacencyMatrix[e.start][e.end] = e.capacity;
            }
        }
        updatedMatrix = true;
    }
    return minAdjacencyMatrix;
}

void Graph::graphChanged() {
    updatedList = false;
    updatedMatrix = false;
}

void Graph::print() const {
    std::cout << "==================================================" << std::endl
              << " Print Graph: " << this << std::endl
              << "--------------------------------------------------" << std::endl
              << " Edges:\t|V|= " << vertices.size() << "\t|E|= " << edges.size() << std::endl;
    if (!edges.empty()) {
        std::cout << "--------------------------------------------------" << std::endl;
        for (auto e : edges)
            std::cout << " (v" << e.start << ", v" << e.end << ") c(" << e.capacity << ")" << std::endl;
    }
    std::cout << "==================================================" << std::endl;
}

void Graph::printAdjacencyList() const {
    std::cout << "==================================================" << std::endl;
    auto &list = getAdjacencyList();
    for (unsigned int i = 0; i < list.size(); ++i) {
        std::cout << "adjacency of " << i << ": ";
        for (auto &e : list[i]) {
            std::cout << "(" << e.end << "):" << e.capacity << " " ;
        }
        std::cout << std::endl;
    }
    std::cout << "==================================================" << std::endl;
}

void Graph::printAdjacencyMatrix() const {
    std::cout << "==================================================" << std::endl;
    auto &matrix = getMinAdjacencyMatrix();
    for (const auto &i : matrix) {
        for (double j : i) {
            printf("%4.0lf", j);
        }
        std::cout << std::endl;
    }

    std::cout << "==================================================" << std::endl;
}
