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

#include <iostream>
#include "disjoint_set.h"

ArrayDisjointSet::ArrayDisjointSet(int n) : parent(n) {
    makeSet();
}

void ArrayDisjointSet::makeSet() {
    for (int i = 0; i < parent.size(); i++) parent[i] = i;
}

int ArrayDisjointSet::find(int x) {
    return parent[x];
}

void ArrayDisjointSet::join(int x, int y) {
    for (int &i : parent) {
        if (i == parent[y]) {
            i = parent[x];
        }
    }
}

bool ArrayDisjointSet::sameSet(int x, int y) {
    return find(x) == find(y);
}

BlogDisjointSet::BlogDisjointSet(int n) : parent(n), rank(n) {
    makeSet();
}

void BlogDisjointSet::makeSet() {
    for (int i = 0; i < parent.size(); i++) parent[i] = i;
}

int BlogDisjointSet::find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

void BlogDisjointSet::join(int x, int y) {
    int xset = find(x);
    int yset = find(y);

    if (xset == yset)
        return;

    if (rank[xset] < rank[yset]) {
        parent[xset] = yset;
    } else if (rank[xset] > rank[yset]) {
        parent[yset] = xset;
    } else {
        parent[yset] = xset;
        rank[xset] = rank[xset] + 1;
    }
}

bool BlogDisjointSet::sameSet(int x, int y) {
    return find(x) == find(y);
}

UnionFindDisjointSet::UnionFindDisjointSet(int n) : nodes(n) {
    makeSet();
}

void UnionFindDisjointSet::makeSet() {
    for (int i = 0; i < nodes.size(); i++) {
        auto &n = nodes[i];
        n.parent = &n;
        n.rank = 0;
        n.id = i;
    }
}

int UnionFindDisjointSet::find(int x) {
    UnionFindNode &n = nodes[x];
    if (n.parent != &n) {
        n.parent = &nodes[find(n.parent->id)];
    }
    return n.parent->id;
}

bool UnionFindDisjointSet::sameSet(int x, int y) {
    return find(x) == find(y);
}

void UnionFindDisjointSet::join(int x, int y) {
    link(nodes[find(x)], nodes[find(y)]);
}

void UnionFindDisjointSet::link(UnionFindNode &x, UnionFindNode &y) {
    if (x.rank > y.rank) {
        y.parent = &x;
    } else {
        x.parent = &y;
        if (x.rank == y.rank) {
            y.rank++;
        }
    }
}
