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

#ifndef MST_ARRAYSET_H
#define MST_ARRAYSET_H

#include <vector>
#include "disjointset.h"

class ArrayDisjointSet : public DisjointSet {
public:

    explicit ArrayDisjointSet(int n);

    int find(int x);

    void join(int x, int y);

    bool sameSet(int x, int y);

private:

    void makeSet();

    std::vector<int> parent;
};

#endif //MST_ARRAYSET_H
