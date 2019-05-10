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

#include <string>
#include <vector>
#include <iostream>

struct Vertex {

    explicit Vertex(int id, std::string label = "");

    Vertex(const Vertex &orig);

    virtual ~Vertex();

    int id;
    std::string label;
};

struct Edge {

    explicit Edge(int start, int end, float weight);

    inline bool operator<(const Edge &other) const { return weight < other.weight; }

    inline bool operator>(const Edge &other) const { return weight > other.weight; }

    inline bool operator<=(const Edge &other) const { return weight <= other.weight; }

    inline bool operator>=(const Edge &other) const { return weight >= other.weight; }

    int start;
    int end;
    float weight;
};

class Graph {
public:

    explicit Graph(int n = 0, int m = 0);

    Graph(const Graph &orig);

    virtual ~Graph();

    int insertVertex(const std::string &label = "");

    int insertEdge(int v1, int v2, float weight);

    void clearEdges();

    void print();

    std::vector<Vertex> vertices;
    std::vector<Edge> edges;
};


#endif //MST_GRAPH_H
