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

#include "fastunionfind.h"

FastUnionFind::FastUnionFind(int n) : parent(n), rank(n) {
    makeSet();
}

void FastUnionFind::makeSet() {
    for (int i = 0; i < parent.size(); i++) parent[i] = i;
}

int FastUnionFind::find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

void FastUnionFind::join(int x, int y) {
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

bool FastUnionFind::sameSet(int x, int y) {
    return find(x) == find(y);
}
