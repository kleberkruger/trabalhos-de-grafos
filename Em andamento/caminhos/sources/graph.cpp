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


Graph::Graph(int n, int m) : updatedList(false), updatedMatrix(false) {
//    adjacencyList(n);
//    minAdjacencyMatrix(n, std::vector<double>(n, std::numeric_limits<double>::infinity()));
//    for (int i = 0; i < n; i++) minAdjacencyMatrix[i][i] = 0;

    vertices.reserve(n);
    edges.reserve(m);

//    // FIXME: Ajustando a capacidade inicial para (n -1), mas e se o grafo não for completo? (desperdício de memória?)
//    std::size_t adjCapacity = n - 1;
//    for (int i = 0; i < n; i++) insertVertex(i, adjCapacity);
    for (int i = 0; i < n; i++) insertVertex(i);
}

//Graph::Graph(const Graph &orig) : vertices(orig.vertices), edges(orig.edges), adjacencyList(orig.vertices.size()),
//                                  minAdjacencyMatrix(orig.vertices.size(), std::vector<double>(
//                                          orig.vertices.size(), std::numeric_limits<double>::infinity())) {}

Graph::Graph(const Graph &orig) = default;

Graph::~Graph() = default;

//void Graph::insertVertex(int id, std::size_t adjCapacity) {
void Graph::insertVertex(int id) {
//    vertices.emplace_back(id, adjCapacity);
    vertices.emplace_back(id);
    graphChanged();
}

void Graph::insertEdge(int v1, int v2, double weight) {
    edges.emplace_back(v1, v2, weight);
//    vertices[v1].adjacency.emplace_back(v2, weight);
//    vertices[v2].adjacency.emplace_back(v1, weight);
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
        auto n = vertices.size();
        adjacencyList.clear();
        adjacencyList.reserve(n);
        for (auto i = 0; i < n; i++) {
            adjacencyList.emplace_back();
            adjacencyList[i].reserve(n); // otimização
        }
        for (auto &e : edges) {
            adjacencyList[e.start].push_back(EdgeTo(e.end, e.weight));
        }
        updatedList = true;
    }
    return adjacencyList;

//    static bool exists = false;
//    if (!exists) {
//        for (auto &e : edges) {
//            adjacencyList[e.start].push_back(EdgeTo(e.end, e.weight));
//        }
//        exists = true;
//    }
//    return adjacencyList;
}

const std::vector<EdgeTo> &Graph::getAdjacencyList(int vertex) const {
    return getAdjacencyList()[vertex];
}

const std::vector<std::vector<double>> &Graph::getMinAdjacencyMatrix() const {
    if (!updatedMatrix) {
        // alocação de espaço e inicialização
        auto n = vertices.size();
        minAdjacencyMatrix.clear();
        minAdjacencyMatrix.reserve(n);
        for (auto i = 0; i < n; i++) {
            minAdjacencyMatrix.emplace_back(n, std::numeric_limits<double>::infinity());
            minAdjacencyMatrix[i][i] = 0;
        }

        // definição dos valores
        for (auto &e : edges) {
            if (e.weight < minAdjacencyMatrix[e.start][e.end]) {
                minAdjacencyMatrix[e.start][e.end] = e.weight;
            }
        }

        updatedMatrix = true;
    }
    return minAdjacencyMatrix;

//    static bool exists = false;
//    if (!exists) {
//        for (auto &e : edges) {
//            if (e.weight < minAdjacencyMatrix[e.start][e.end]) {
//                minAdjacencyMatrix[e.start][e.end] = e.weight;
//            }
//        }
//        exists = true;
//    }
//    return minAdjacencyMatrix;
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
            std::cout << "(" << e.end << "):" << e.weight << " " ;
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
