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

//bool compareEdges(std::vector<Edge *>::const_iterator e1, std::vector<Edge *>::const_iterator e2) {
bool compareEdges(Edge *e1, Edge *e2) {
    return false;
}

struct less_than_key {
    inline bool operator()(const Edge &struct1, const Edge &struct2) {
        return struct1.weight < struct2.weight;
    }

    inline bool operator()(const Edge *struct1, const Edge *struct2) {
        return struct1->weight < struct2->weight;
    }
};

float Graph::kruskal(const Graph &graph, Graph &mst) {
//    A = O;
//    for each vertex v in G(V)
//        make-set(v)
//    sort the edges of G(E) into non-decreasing order by weight w
//    for each edge (u, v) in G(E), taken in non-decreasing order by weight
//        if find-set(u) != find-set(v)
//            A = A + (u,v)
//            union(u,v)
//    return A

    mst.clearEdges();
    for (auto v : graph.vertex) {
        DisjointSet<Vertex *>::findSet(v);
    }

    std::sort(graph.edges.begin(), graph.edges.end(), less_than_key());
    for (auto e : graph.edges) {
        auto u = e->start;
        auto v = e->end;
//        if (DisjointSet<Vertex *>::findSet(u) != DisjointSet<Vertex *>::findSet(v)) {
        mst.insertEdge(e);
        DisjointSet<Vertex *>::unionSets(u, v);
//        }
    }

    return 0;
}

float Graph::prim(const Graph &graph, Graph &mst) {
//    for each u in G(V)
//        u.key = Infinity
//        u.parent= null
//    r.key = 0
//    Q = G(V)
//    while Q != 0;
//        u = Q.extract-min
//        for each v int G.Adj[u]
//            if v in Q && w(u, v) < v.key
//                v.parent = u
//                v.key = w(u, v)

    mst.clearEdges();
    for (auto u : graph.vertex) {
        u->key = std::numeric_limits<float>::infinity();
        u->parent = nullptr;
    }

    Vertex *r = graph.vertex.at(0);
    std::queue<Vertex *> q;
//    while (!q.empty()) {
//        Vertex *u = extractMin(q);
    Vertex *u = nullptr;
    for (auto v : u->adjacent) {
//            if (q.find(v) && w(u,v) < v.key) {
        v->parent = u;
//        v.key = w(u, v);
    }
//}

    return 0;
}
