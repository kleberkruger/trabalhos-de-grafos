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

#ifndef MST_UNIONFIND_H
#define MST_UNIONFIND_H

#include <vector>
#include "disjointset.h"

class UnionFind : public DisjointSet {
public:

    explicit UnionFind(int n);

    int find(int x);

    void join(int x, int y);

    bool sameSet(int x, int y);

private:

    struct UnionFindNode {
        UnionFindNode *parent;
        int rank;
        int id;
    };

    void makeSet();

    void link(UnionFindNode &x, UnionFindNode &y);

    std::vector<UnionFindNode> nodes;
};

#endif //MST_UNIONFIND_H
