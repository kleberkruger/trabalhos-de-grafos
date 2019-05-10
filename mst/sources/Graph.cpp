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

Vertex::Vertex(int id, std::string label) : id(id), label(std::move(label)) {}

Vertex::Vertex(const Vertex &orig) = default;

Vertex::~Vertex() = default;


Edge::Edge(int start, int end, float weight) : start(start), end(end), weight(weight) {}


Graph::Graph(int n, int m) {
    vertices.reserve(n);
    edges.reserve(m);

    for (int i = 0; i < n; i++) {
        insertVertex();
    }
}

Graph::Graph(const Graph &orig) = default;

Graph::~Graph() = default;

int Graph::insertVertex(const std::string &label) {
    static int id = 0;

    vertices.emplace_back(id);
    return id++;
}

int Graph::insertEdge(int v1, int v2, float weight) {
    static int id = 0;

    edges.emplace_back(Edge(v1, v2, weight));
    return id++;
}

void Graph::clearEdges() {
    edges.clear();
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
