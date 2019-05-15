#include <utility>

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

#include <iostream>
#include <list>
#include <vector>

#include "disjointset.h"
#include "arrayset.h"
#include "listset.h"
#include "unionfind.h"
#include "fastunionfind.h"

#include "heap.h"
#include "arrayheap.h"
#include "binaryheap.h"
#include "fibonacciheap.h"

struct Vertex;
struct Edge;
struct EdgeTo;

struct Vertex {

    /**
     * Cria um vértice.
     *
     * @param id
     */
    explicit Vertex(int id);

    int id;
    std::list<EdgeTo> adjacency;
};

struct Edge {

    /**
     * Cria uma aresta.
     *
     * @param start id do vértice inicial
     * @param end id do vértice final
     * @param weight peso da aresta
     */
    explicit Edge(int start, int end, float weight);

    bool operator<(const Edge &other) const { return weight < other.weight; }

    bool operator>(const Edge &other) const { return weight > other.weight; }

    bool operator<=(const Edge &other) const { return weight <= other.weight; }

    bool operator>=(const Edge &other) const { return weight >= other.weight; }

    int start, end;
    float weight;
};

struct EdgeTo {

    /**
     * Cria uma "meia aresta".
     *
     * @param end
     * @param weight
     */
    EdgeTo(int end, float weight);

    virtual ~EdgeTo();

    int end;
    float weight;
};

class Graph {
public:

    struct MSTAlgorithm {
        const std::string name;
        int version;

        double (*execute)(const Graph &graph, Graph &mst);

        MSTAlgorithm(std::string name, const int version, double (*execute)(const Graph &, Graph &))
                : name(std::move(name)), version(version), execute(execute) {}
    };

    /**
     * Cria um grafo.
     *
     * @param n
     * @param m
     */
    explicit Graph(int n = 0, int m = 0);

    /**
     * Cria a cópia de um grafo especificado.
     *
     * @param orig
     */
    Graph(const Graph &orig);

    /**
     * Destrói um grafo.
     */
    virtual ~Graph();

    /**
     * Insere um vértice no grafo.
     *
     * @param id
     */
    void insertVertex(int id);

    /**
     * Insere uma aresta no grafo.
     *
     * @param v1
     * @param v2
     * @param weight
     */
    void insertEdge(int v1, int v2, float weight);

    /**
     * Limpa todas as arestas do grafo.
     */
    void clearEdges();

    /**
     * Limpa todas as arestas e vértices do grafo.
     */
    void clearAll();

    /**
     * Imprime o grafo (usado para debug).
     */
    void print();

    /**
     * Executa o algoritmo de árvore geradora mínima (MST) no grafo.
     *
     * @param graph
     * @param mst
     * @param version
     * @return
     */
    static double mst(const Graph &graph, Graph &mst, int version = DEFAULT_VERSION);

    /**
     * Executa o algoritmo ingênuo de Kruskal no grafo.
     *
     * @param graph
     * @param mst
     * @return
     */
    static double kruskalIngenuo(const Graph &graph, Graph &mst);

    /**
     * Executa o algoritmo de Kruskal no grafo conforme a estrutura de dados recebida.
     *
     * @tparam DS
     * @param graph
     * @param mst
     * @return
     */
    template<class DS>
    static double kruskal(const Graph &graph, Graph &mst);

    /**
     * Executa o algoritmo ingênuo de Kruskal no grafo.
     *
     * @param graph
     * @param mst
     * @return
     */
    static double primIngenuo(const Graph &graph, Graph &mst);

    /**
     * Executa o algoritmo de Prim no grafo conforme a estrutura recebida.
     *
     * @tparam DS
     * @param graph
     * @param mst
     * @return
     */
    template<class DS>
    static double prim(const Graph &graph, Graph &mst);

    /**
     * Retorna a lista de adjacências do grafo.
     *
     * @return
     */
    const std::vector<Vertex> &getAdjacencyList() const;

    /**
     * Retorna a lista de adjacências de um vértice especificado.
     *
     * @param vertex
     * @return
     */
    const std::list<EdgeTo> &getAdjacencyList(int vertex) const;

    /**
     * Retorna a matriz de adjacência do grafo.
     *
     * @return
     */
    float *getMinAdjacencyMatrix() const;

    std::vector<Vertex> vertices;
    std::vector<Edge> edges;

private:

    const static int DEFAULT_VERSION = 0;

    float *minAdjacencyMatrix;
};

#endif //MST_GRAPH_H
