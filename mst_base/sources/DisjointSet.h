//
// Created by Kleber Kruger on 2019-05-07.
//

#ifndef MST_DISJOINTSET_H
#define MST_DISJOINTSET_H

template<class T = void *>
class DisjointSet {
public:

    DisjointSet() {}

    virtual ~DisjointSet() {}

    template<class V>
    static void makeSet(V x) {

    }

    template<class V>
    static void unionSets(V x, V y) {

    }

    template <class V>
    static void findSet (V x) {

    }

private:

    template<class V>
    static void link(V x, V y) {

    }

};


#endif //MST_DISJOINTSET_H
