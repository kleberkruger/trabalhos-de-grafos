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

#include "listset.h"

ListDisjointSet::ListDisjointSet(int n) : parent(n), children(n) {
    makeSet();
    
}

void ListDisjointSet::makeSet() {
    for (int i = 0; i < parent.size(); i++) {
        parent[i] = i;
    }
}

int ListDisjointSet::find(int x) {
    return parent[x];
}

void ListDisjointSet::join(int x, int y) {
    int minListIndex, maxListIndex;
    if (children[parent[x]].size() < children[parent[y]].size()) {
        minListIndex = parent[x], maxListIndex = parent[y];
    } else {
        minListIndex = parent[y], maxListIndex = parent[x];
    }

    auto &minList = children[minListIndex];
    auto &maxList = children[maxListIndex];

    maxList.push_back(minListIndex);
    parent[minListIndex] = maxListIndex;
    
    for (auto it = minList.begin(); it != minList.end(); it++) {
        parent[*it] = maxListIndex;
    }

    std::move(minList.begin(), minList.end(), std::back_inserter(maxList));   
}

bool ListDisjointSet::sameSet(int x, int y) {
    return find(x) == find(y);
}
