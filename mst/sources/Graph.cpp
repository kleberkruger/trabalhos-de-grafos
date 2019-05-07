//
// Created by Kleber Kruger on 2019-05-07.
//

#include "Graph.h"


float Graph::kruskal(const Graph &g, Graph &mst) {
    mst = g;
    mst.clearEdges();

    float total = 0;

    for (auto u : g.vertex) DataStructs::makeSet(u);

    std::vector<Edge> edges = g.edges;
    std::sort(edges.begin(), edges.end());

    for (auto e : edges) {
        if (DataStructs::findSet(*e.start) != DataStructs::findSet(*e.end)) {
            mst.insertEdge(e);
            DataStructs::unionSets(*e.start, *e.end);
            total += e.weight;
        }
    }

    return total;
}

float Graph::prim(const Graph &g, Graph &mst) {
    mst = g;
    mst.clearEdges();

    for (auto u : g.vertex) {
        u.key = std::numeric_limits<float>::infinity();
        u.parent = nullptr;
    }

    return 0;
}
