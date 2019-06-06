/**
 * Algoritmos em Grafos (MO412)
 *
 * @author: Kleber Kruger <kleberkruger@gmail.com>
 * @author: Felipe Barbosa <felipebarbosa@uft.edu.com>
 * @author: Rodrigo Kanehisa <rodrigokanehisa@gmail.com>
 */

#include "graph.h"


Vertex::Vertex(int id) : id(id) {}


Edge::Edge(int start, int end, int capacity) : start(start), end(end), capacity(capacity), flow(0) {}

//EdgeTo::EdgeTo(int start, int end, int capacity) : start(start), end(end), capacity(capacity) {}

//EdgeTo::~EdgeTo() = default;


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

const std::vector<std::vector<Edge *>> &Graph::getAdjacencyList() const {
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
        for (const Edge &e : edges) {
            adjacencyList[e.start].push_back(const_cast<Edge *>(&e));
        }
        updatedList = true;
    }
    return adjacencyList;
}

const std::vector<Edge *> &Graph::getAdjacencyList(int vertex) const {
    return getAdjacencyList()[vertex];
}

const std::vector<std::vector<Edge *>> &Graph::getMinAdjacencyList() const {
    return getAdjacencyList();
}

const std::vector<Edge *> &Graph::getMinAdjacencyList(int vertex) const {
    return getAdjacencyList()[vertex];
}

const std::vector<std::vector<Edge *>> &Graph::getMinAdjacencyMatrix() const {
    if (!updatedMatrix) {
        // alocação de espaço e inicialização
        unsigned int n = vertices.size();
        minAdjacencyMatrix.clear();
        minAdjacencyMatrix.reserve(n);
        for (unsigned int i = 0; i < n; i++) {
            minAdjacencyMatrix.emplace_back(n, nullptr);
        }

        // definição dos valores
        for (auto &e : edges) {
//            if (e.capacity < minAdjacencyMatrix[e.start][e.end]) {
            minAdjacencyMatrix[e.start][e.end] = const_cast<Edge *>(&e);
//            }
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
            std::cout << "(" << e->end << "):" << e->capacity << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "==================================================" << std::endl;
}

void Graph::printAdjacencyMatrix() const {
    printf("==================================================\n");
    auto &matrix = getMinAdjacencyMatrix();
    for (const auto & line : matrix) {
        for (auto e : line) {
            printf("%d ", e != nullptr ? e->capacity : 0);
        }
        printf("\n");
    }
    printf("==================================================\n");
}

bool Graph::containsEdge(Edge &edge) const {
    return (std::find(edges.begin(), edges.end(), edge) != edges.end());
}
