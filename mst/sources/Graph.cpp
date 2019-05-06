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

bool compareEdges(Edge* e1, Edge* e2) {
    return false;
}

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
    for (std::vector<Vertex *>::size_type i = 0; i < graph.vertex.size(); i++) {
//        makeSet(vertex.at(i));
    }

//    std::sort(graph.edges.begin(), graph.edges.end(), compareEdges);
    for (std::vector<Edge *>::size_type i = 0; i < graph.edges.size(); i++) {
//        if (findSet(u) != findSet(v)) {
//            mst.insertVertex(edges.at(i));
//            union(u, v)
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
    for (std::vector<Vertex *>::size_type i = 0; i < graph.vertex.size(); i++) {
        Vertex *u = graph.vertex.at(i);
//        u.key = Infinity;
//        u.parent = null;
    }

    Vertex *r = graph.vertex.at(0);
    std::queue<Vertex *> q;
//    while (!q.empty()) {
//        Vertex *u = extractMin(q);
//        for (Vertex *v : u.adjacency()) {
//            if (q.find(v) && w(u,v) < v.key) {
//                v.parent = u;
//                v.key = w(u, v);
//            }
//        }
//    }

    return 0;
}
