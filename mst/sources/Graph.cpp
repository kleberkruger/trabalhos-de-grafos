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

#include "Graph.h"

GraphComponent::GraphComponent(const std::string &label) : label(label) {}

Vertex::Vertex(const std::string &label) : GraphComponent(label) {}

Edge::Edge(const Vertex &start, const Vertex &end, const std::string &label)
        : GraphComponent(label), start(start), end(end) {}

Edge::Edge(const Vertex &start, const Vertex &end, double weight, const std::string &label)
        : GraphComponent(label), start(start), end(end), weight(weight) {}

Graph::Graph(int n) {}

Graph::~Graph() {

}

void Graph::clear() {
    clearEdges();
}

void Graph::clearEdges() {

}

int Graph::insertVertex(const std::string &label) {
    return 0;
}

void Graph::insertEdge(int v1, int v2, int weight) {

}

float Graph::kruskal(const Graph &graph, Graph &mst) {
    mst.clearEdges();

    return 0;
}

float Graph::prim(const Graph &graph, Graph &mst) {
    mst.clearEdges();

    return 0;
}




