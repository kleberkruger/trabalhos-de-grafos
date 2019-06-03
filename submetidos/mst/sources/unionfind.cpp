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

#include "unionfind.h"

UnionFind::UnionFind(int n) : nodes(n) {
    makeSet();
}

void UnionFind::makeSet() {
    for (int i = 0; i < nodes.size(); i++) {
        auto &n = nodes[i];
        n.parent = &n;
        n.rank = 0;
        n.id = i;
    }
}

int UnionFind::find(int x) {
    UnionFindNode &n = nodes[x];
    if (n.parent != &n) {
        n.parent = &nodes[find(n.parent->id)];
    }
    return n.parent->id;
}

bool UnionFind::sameSet(int x, int y) {
    return find(x) == find(y);
}

void UnionFind::join(int x, int y) {
    link(nodes[find(x)], nodes[find(y)]);
}

void UnionFind::link(UnionFindNode &x, UnionFindNode &y) {
    if (x.rank > y.rank) {
        y.parent = &x;
    } else {
        x.parent = &y;
        if (x.rank == y.rank) {
            y.rank++;
        }
    }
}
