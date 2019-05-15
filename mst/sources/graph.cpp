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

void Graph::clearAll() {
    edges.clear();
    vertices.clear();
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

double Graph::mst(const Graph &graph, Graph &mst, int alg, int version) {
    static MSTAlgorithm kruskals[] = {
            MSTAlgorithm("Kruskal Ingênuo", 0, Graph::kruskalIngenuo),
            MSTAlgorithm("Kruskal with UnionFind", 1, Graph::kruskal<UnionFind>),
            MSTAlgorithm("Kruskal with FastUnionFind", 2, Graph::kruskal<FastUnionFind>),
    };
    static MSTAlgorithm prims[] = {
            MSTAlgorithm("Prim Ingênuo", 0, Graph::primIngenuo),
            MSTAlgorithm("Prim with ArrayHeap", 1, Graph::prim<ArrayHeap>),
            MSTAlgorithm("Prim with BinaryHeap", 2, Graph::prim<BinaryHeap>),
            MSTAlgorithm("Prim with FibonacciHeap", 3, Graph::prim<FibonacciHeap>),
    };
    static std::vector<MSTAlgorithm *> algorithms = {kruskals, prims};

    std::cout << "Running: \"" << algorithms[alg][version].name << "\" version " << algorithms[alg][version].version << std::endl;
    return algorithms[alg][version].execute(graph, mst);
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

double Graph::primIngenuo(const Graph &graph, Graph &mst) {
    mst = graph;
    mst.clearEdges();

    std::vector<float> parent(graph.vertices.size());

    for (auto &i : parent) i = -1;
    parent[0] = 0;

    double total = 0;

    while (true) {

        float minWeight = std::numeric_limits<float>::infinity();
        int v0, w0;

        for (auto &w : graph.vertices) {
            if (parent[w.id] == -1) {
                for (auto &e : w.adjacency) {
                    int v = e.end;
                    if (parent[v] != -1 && minWeight > e.weight) {
                        minWeight = e.weight;
                        v0 = v, w0 = w.id;
                    }
                }
            }
        }

        if (minWeight == std::numeric_limits<float>::infinity())
            break;

        parent[w0] = v0;
        mst.insertEdge(w0, v0, minWeight);
        total += minWeight;
    }

    return total;
}

template<class DS>
double Graph::prim(const Graph &graph, Graph &mst) {
    struct PrimVertex {
        bool isPresent;
        int parent;
        double value;
    };

    mst = Graph(graph.vertices.size(), graph.vertices.size() - 1);

    std::vector<PrimVertex> vertices(graph.vertices.size());
    DS ds(mst.vertices.size(), 0);

    for (auto &v : vertices) {
        v.isPresent = true;
        v.parent = -1;
        v.value = std::numeric_limits<double>::infinity();
    }
    vertices[0].value = 0;

    double total = 0;

    while (!ds.empty()) {

        Vertex u = graph.vertices[ds.extractMin()];
        vertices[u.id].isPresent = false;

        for (auto &e : u.adjacency) {
            int v = e.end;
            if (vertices[v].isPresent && e.weight < vertices[v].value) {
                vertices[v].parent = u.id;

                ds.decreaseKey(v, e.weight);
                vertices[v].value = e.weight;
            }
        }

        if (vertices[u.id].parent != -1) {
            mst.insertVertex(u.id);
            mst.insertEdge(vertices[u.id].parent, u.id, vertices[u.id].value);
            total += vertices[u.id].value;
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
