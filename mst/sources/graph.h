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

#ifndef MST_GRAPH_H
#define MST_GRAPH_H


#include <vector>
#include <iostream>
#include "disjoint_set.h"
//#include "kruskal.h"


struct Vertex {

    explicit Vertex(int id);

    int id;
};

struct Edge {

    explicit Edge(int start, int end, float weight);

    bool operator<(const Edge &other) const { return weight < other.weight; }

    bool operator>(const Edge &other) const { return weight > other.weight; }

    bool operator<=(const Edge &other) const { return weight <= other.weight; }

    bool operator>=(const Edge &other) const { return weight >= other.weight; }

    int start, end;
    float weight;
};

struct EdgeTo {

    int end;
    float weight;
};

class Graph {
public:

    explicit Graph(int n = 0, int m = 0);

    Graph(const Graph &orig);

    virtual ~Graph();

    void insertVertex(int id);

    void insertEdge(int v1, int v2, float weight);

    void clearEdges();

    void print();

    static double mst(const Graph &graph, Graph &mst, int version = DEFAULT_VERSION);

    template <class DS>
    static double kruskal(const Graph &graph, Graph &mst);

    static double kruskalIngenuo(const Graph &graph, Graph &mst);

    std::vector<Vertex> vertices;
    std::vector<Edge> edges;

private:

    const static int DEFAULT_VERSION = 0;
};


#endif //MST_GRAPH_H
