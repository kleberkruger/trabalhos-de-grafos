//
// Created by Kleber Kruger on 2019-05-07.
//

#ifndef MST_DATASTRUCTS_H
#define MST_DATASTRUCTS_H

#include "Graph.h"

struct Vertex;

class DataStructs {
public:

    static void makeSet(Vertex &x) {
        x.parent = x;
        x.rank = 0;
    }

    static void unionSets(Vertex &x, Vertex &y) {
        link(findSet(x), findSet(y));
    }

    static Vertex *findSet(Vertex &x) {
        if (x != x.parent) {
            x.parent = findSet(x.parent);
        }
        return x.parent;
    }

private:

    static void link(Vertex &x, Vertex &y) {
        if (x.rank > y.rank) {
            y.parent = x;
        } else {
            x.parent = y
            if (x.rank == y.rank)
                y.rank++;
        }
    }
};


#endif //MST_DATASTRUCTS_H
