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

#ifndef MST_DISJOINT_SET_H
#define MST_DISJOINT_SET_H

#include <vector>


class DisjointSet {
public:

//    virtual void makeSet() = 0;
//    virtual void join(int a, int b) = 0;
//    virtual int find(int a, int b) = 0;
//    bool sameSet(int x, int y);
};

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

class ListDisjointSet : public DisjointSet {
public:
};

class UnionFindDisjointSet : public DisjointSet {
public:

    explicit UnionFindDisjointSet(int n);

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

class BlogDisjointSet : public DisjointSet {
public:

    explicit BlogDisjointSet(int n);

    int find(int x);

    void join(int x, int y);

    bool sameSet(int x, int y);

private:

    void makeSet();

    std::vector<int> parent;
    std::vector<int> rank;
};


#endif //MST_DISJOINT_SET_H
