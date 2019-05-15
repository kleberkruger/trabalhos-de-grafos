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

#ifndef MST_LISTSET_H
#define MST_LISTSET_H

#include "disjointset.h"

class ListDisjointSet : public DisjointSet {
public:

    struct ListNode {
        int id;
        ListNode *parent;
    };

    explicit ListDisjointSet(int n);

    int find(int x);

    void join(int x, int y);

    bool sameSet(int x, int y);

private:

    void makeSet();

    std::vector<ListNode> nodes;
};


#endif //MST_LISTSET_H
