//
// Created by Kleber Kruger on 2019-05-10.
//

#include "kruskal.h"

UnionFind::UnionFindNode::UnionFindNode(Vertex *vertex, UnionFind::UnionFindNode *parent, int rank) : vertex(vertex),
                                                                                                      parent(parent),
                                                                                                      rank(rank) {}

UnionFind::UnionFind(int n) : nodes(n) {}

void UnionFind::makeSet(Vertex &x) {
    nodes[x.id].parent = &nodes[x.id];
    nodes[x.id].rank = 0;
    nodes[x.id].vertex = &x;
}

void UnionFind::unionSets(Vertex &x, Vertex &y) {
    link(nodes[findSet(x)->id], nodes[findSet(y)->id]);
}

Vertex *UnionFind::findSet(Vertex &x) {
    auto &eu = nodes[x.id];
    auto &meuPapai = eu.parent;
    if (&nodes[x.id] != nodes[x.id].parent)
        nodes[x.id].parent = &nodes[findSet(*meuPapai->vertex)->id];
    return nodes[x.id].parent->vertex;
}

void UnionFind::link(UnionFindNode &x, UnionFindNode &y) {
    if (x.rank > y.rank) {
        y.parent = &x;
    } else {
        x.parent = &y;
        if (x.rank == y.rank)
            y.rank++;
    }
}


VetorBemBosta::VetorBemBosta(int n) : color(n), usedEdges() {}

void VetorBemBosta::makeSet(Vertex &x) {
    color[x.id] = x.id;
}

void VetorBemBosta::unionSets(Vertex &x, Vertex &y) {
    for (int &i : color) {
        if (i == color[x.id]) {
            i = color[y.id];
        }
    }
}

Vertex *VetorBemBosta::findSet(Vertex &x) {
    return nullptr;
}
