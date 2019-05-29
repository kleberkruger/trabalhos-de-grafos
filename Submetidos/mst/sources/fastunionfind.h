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

#ifndef MST_FASTUNIONFIND_H
#define MST_FASTUNIONFIND_H

#include <vector>
#include "disjointset.h"

class FastUnionFind : public DisjointSet {
public:

    explicit FastUnionFind(int n);

    int find(int x);

    void join(int x, int y);

    bool sameSet(int x, int y);

private:

    void makeSet();

    std::vector<int> parent;
    std::vector<int> rank;
};

#endif //MST_FASTUNIONFIND_H
