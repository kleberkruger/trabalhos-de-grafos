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

#include "arrayset.h"

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
