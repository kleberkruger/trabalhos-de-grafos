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
//    std::cout << "join (" << x << "," << y << ")" << std::endl;
//    std::cout << "parent "; for (int i = 0; i < parent.size(); i++) std::cout << i << ":[" << parent[i] << "] "; std::cout << std::endl;

    int minListIndex, maxListIndex;
    if (children[parent[x]].size() < children[parent[y]].size()) {
        minListIndex = parent[x], maxListIndex = parent[y];
    } else {
        minListIndex = parent[y], maxListIndex = parent[x];
    }

    auto &minList = children[minListIndex];
    auto &maxList = children[maxListIndex];

//    std::cout << "|" << minListIndex << "|:"; for (auto it = minList.begin(); it != minList.end(); it++) std::cout << *it << ' '; std::cout << std::endl;
//    std::cout << "|" << maxListIndex << "|:"; for (auto it = maxList.begin(); it != maxList.end(); it++) std::cout << *it << ' '; std::cout << std::endl;

    maxList.push_back(minListIndex);
    parent[minListIndex] = maxListIndex;

    for (auto it = minList.begin(); it != minList.end(); it++) {
        maxList.push_back(*it);
        parent[*it] = maxListIndex;
        minList.erase(it);
    }

//    std::cout << "|" << maxListIndex << "|:"; for (auto it = maxList.begin(); it != maxList.end(); it++) std::cout << *it << ' '; std::cout << std::endl;
//    std::cout << "parent "; for (int i = 0; i < parent.size(); i++) std::cout << i << ":[" << parent[i] << "] "; std::cout << std::endl << std::endl;
}

bool ListDisjointSet::sameSet(int x, int y) {
    return find(x) == find(y);
}
