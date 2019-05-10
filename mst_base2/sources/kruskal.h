//
// Created by Kleber Kruger on 2019-05-10.
//

#ifndef MST_KRUSKAL_H
#define MST_KRUSKAL_H

#include "graph.h"

class KruskalDataStruct {
public:

    virtual void makeSet(Vertex &x) = 0;

    virtual void unionSets(Vertex &x, Vertex &y) = 0;

    virtual Vertex *findSet(Vertex &x) = 0;

};

class VetorBemBosta : KruskalDataStruct {
public:

    explicit VetorBemBosta(int n);

    void makeSet(Vertex &x) override;

    void unionSets(Vertex &x, Vertex &y) override;

    Vertex *findSet(Vertex &x) override;

private:

    std::vector<bool> usedEdges;
    std::vector<int> color;
};

class UnionFind : KruskalDataStruct {
public:

    struct UnionFindNode {

        explicit UnionFindNode(Vertex *vertex = nullptr, UnionFindNode *parent = nullptr, int rank = -1);

        Vertex *vertex;
        UnionFindNode *parent;
        int rank;
    };

    explicit UnionFind(int n);

    void makeSet(Vertex &x) override;

    void unionSets(Vertex &x, Vertex &y) override;

    Vertex *findSet(Vertex &x) override;

private:

    void link(UnionFindNode &x, UnionFindNode &y);

private:

    std::vector<UnionFindNode> nodes;
};

template<class T>
class Kruskal {
public:

    float execute(const Graph &graph, Graph &mst) {
        mst = graph;
        mst.clearEdges();

        float total = 0;

        T *ds = new T(mst.vertices.size());

        for (auto &u : mst.vertices)
            ds->makeSet(u);

        std::vector<Edge> edges = graph.edges;
        std::sort(edges.begin(), edges.end());

        for (auto e : edges) {
            auto &u = mst.vertices[e.start];
            auto &v = mst.vertices[e.end];
//            std::cout << &u << " " << &v << " " << e.weight << std::endl;

            if (ds->findSet(u) != ds->findSet(v)) {
                mst.insertEdge(e.start, e.end, e.weight);
                ds->unionSets(u, v);
                total += e.weight;
            }
        }

        return total;
    }

    float execute2(const Graph &graph, Graph &mst);
};

template<class T>
float Kruskal<T>::execute2(const Graph &graph, Graph &mst) {

    mst = graph;
    mst.clearEdges();

    bool usedEdges[graph.edges.size()];
    memset(usedEdges, false, sizeof(usedEdges));

    int color[graph.vertices.size()];
    float total = 0;

    for (int i = 0; i < graph.vertices.size(); i++) {
        color[i] = i;
    }

    while (true) {
        int u = -1, v = -1, id = -1;
        float minWeight = std::numeric_limits<float>::infinity();

        for (int i = 0; i < graph.edges.size(); i++) {
            auto e = graph.edges[i];
            if (color[e.start] != color[e.end] && e.weight < minWeight) {
                u = e.start, v = e.end, minWeight = e.weight, id = i;
            }
        }

        if (minWeight == std::numeric_limits<float>::infinity()) break;

//        std::cout << "escolhi (v" << u << ", v" << v << ") w(" << minWeight << ") id " << id << std::endl;
        if (!usedEdges[id]) {
            mst.insertEdge(u, v, minWeight);
            total += minWeight;
            usedEdges[id] = true;
//            std::cout << "ENTROU (v" << u << ", v" << v << ") w(" << minWeight << ") id " << id << std::endl;
        }

        for (int i = 0; i < graph.vertices.size(); i++) {
            if (color[i] == color[v]) {
                color[i] = color[u];
            }
        }

//        for (int i = 0; i < graph.vertices.size(); i++) {
//            std::cout << "v" << i << "[" << color[i] << "] ";
//        }
//        std::cout << std::endl;
    }

    return total;
}


#endif //MST_KRUSKAL_H
