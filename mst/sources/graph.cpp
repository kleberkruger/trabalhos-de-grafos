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

Vertex::Vertex(int id) : id(id) {}


Edge::Edge(int start, int end, float weight) : start(start), end(end), weight(weight) {}

EdgeTo::EdgeTo(int end, float weight) : end(end), weight(weight) {}

EdgeTo::~EdgeTo() = default;


Graph::Graph(int n, int m) {
    vertices.reserve(n);
    edges.reserve(m);

    for (int i = 0; i < n; i++) insertVertex(i);
}

Graph::Graph(const Graph &orig) = default;

Graph::~Graph() = default;

void Graph::insertVertex(int id) {
    vertices.emplace_back(id);
}

void Graph::insertEdge(int v1, int v2, float weight) {
    edges.emplace_back(v1, v2, weight);

    vertices[v1].adjacency.emplace_back(v2, weight);
    vertices[v2].adjacency.emplace_back(v1, weight);
}

void Graph::clearEdges() {
    edges.clear();
}

const std::vector<Vertex> &Graph::getAdjacencyList() const {
    return vertices;
}

const std::list<EdgeTo> &Graph::getAdjacencyList(int vertex) const {
    return vertices[vertex].adjacency;
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

double Graph::mst(const Graph &graph, Graph &mst, int version) {

//    std::cout << "Executando algoritmo: " << version << std::endl;
//    double total = 0;
//
//    switch (version) {
//        case 0:
//            Kruskal<ArrayDisjointSet> alg0;
//            total = alg0.execute(graph, mst);
//            break;
//        case 1:
//            Kruskal<BlogDisjointSet> alg1;
//            total = alg1.execute(graph, mst);
//            break;
//
//        case 2:
//            Kruskal<ArrayDisjointSet> alg2;
//            total = alg2.execute(graph, mst);
//            break;
//    }
//    return total;

    std::cout << "Executando algoritmo: " << version << std::endl;
    double total = 0;

    switch (version) {
        case 0:
//            total = kruskal<ArrayDisjointSet>(graph, mst);
            total = kruskalIngenuo(graph, mst);
            break;
        case 1:
            total = kruskal<BlogDisjointSet>(graph, mst); // 1:13
            break;
        case 2:
            total = kruskal<UnionFindDisjointSet>(graph, mst); // 1:15
            break;
    }
    return total;
}

double Graph::kruskalIngenuo(const Graph &graph, Graph &mst) {
    mst = graph;
    mst.clearEdges();

    std::vector<bool> usedEdges(graph.edges.size());
    std::vector<int> color(graph.vertices.size());
    float total = 0;

    for (int i = 0; i < graph.vertices.size(); i++) {
        color[i] = i;
    }

    while (true) {
        int u = -1, v = -1, id = -1;
        float minWeight = std::numeric_limits<float>::infinity();

        for (int i = 0; i < graph.edges.size(); i++) {
            auto e = graph.edges[i];
            if (color[e.start] != color[e.end] && e.weight < minWeight) {
                u = e.start, v = e.end, minWeight = e.weight, id = i;
            }
        }

        if (minWeight == std::numeric_limits<float>::infinity()) break;

        if (!usedEdges[id]) {
            mst.insertEdge(u, v, minWeight);
            total += minWeight;
            usedEdges[id] = true;
        }

        for (int i = 0; i < graph.vertices.size(); i++) {
            if (color[i] == color[v]) {
                color[i] = color[u];
            }
        }
    }

    return total;
}

template<class DS>
double Graph::kruskal(const Graph &graph, Graph &mst) {
    mst = graph;
    mst.clearEdges();

    double total = 0;

    DS ds(mst.vertices.size());

    std::vector<Edge> edges = graph.edges;
    std::sort(edges.begin(), edges.end());

    for (auto e : edges) {
        if (!ds.sameSet(e.start, e.end)) {
            mst.insertEdge(e.start, e.end, e.weight);
            ds.join(e.start, e.end);
            total += e.weight;
        }
    }

    return total;
}

/*
 * TODO: Implementar a matriz de adjacência.
 */
float *Graph::getMinAdjacencyMatrix() const {
    return minAdjacencyMatrix;
}
