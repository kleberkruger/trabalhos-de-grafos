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

#include <algorithm>
#include <list>
#include <vector>
#include <string>

#include <iostream>

#include "DataStructs.h"

struct Vertex {

    float key;
    int rank;
    Vertex *parent;

    explicit Vertex() : key(std::numeric_limits<float>::infinity()) {}
};

struct Edge {

//    const Vertex &start;
//    const Vertex &end;

    Vertex *start;
    Vertex *end;
    float weight;

    explicit Edge(float weight = 1) : weight(weight) {}

//    Edge(const int id, const Vertex &start, const Vertex &end, float weight)
//            : start(start), end(end), weight(weight) {}

    inline bool operator<(const Edge &other) const { return weight < other.weight; }

    inline bool operator>(const Edge &other) const { return weight > other.weight; }

    inline bool operator<=(const Edge &other) const { return weight <= other.weight; }

    inline bool operator>=(const Edge &other) const { return weight >= other.weight; }
};

struct Graph {

    std::vector<Vertex> vertex;
    std::vector<Edge> edges;

//    explicit Graph(int n = 0, int m = 0) : vertex(n), edges(m) { // Apenas se fosse ponteiros
    explicit Graph(int n = 0, int m = 0) {
        for (int i = 0; i < n; i++) {
            insertVertex();
        }
    }

    Graph(const Graph &orig) = default;

    void clearEdges() {
        edges.clear();
    }

    void clearAll() {
        vertex.clear();
        edges.clear();
    }

    void insertVertex() {
        vertex.emplace_back();
    }

    void insertEdge(int v1, int v2, float weight) {
        edges.emplace_back(weight);
    }

    void insertEdge(const Edge &edge) {
        edges.emplace_back(edge);
    }

    static float kruskal(const Graph &graph, Graph &mst);

    static float prim(const Graph &graph, Graph &mst);

    void print() const {
        std::cout << "|V| in: " << this << ": " << vertex.size() << std::endl;
        std::cout << "Edges in: " << this << ": " << std::endl;
        for (auto e : edges)
            std::cout << e.weight << std::endl;
    }
};


#endif //MST_GRAPH_H
