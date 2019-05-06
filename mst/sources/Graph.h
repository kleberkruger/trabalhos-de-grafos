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
#include <list>

class GraphComponent {
public:

    explicit GraphComponent(const std::string &label);

private:

    std::string label;
};

class Vertex : public GraphComponent {
public:

    Vertex(const std::string &label = "");

private:

    const std::list<Vertex *> adjacent;
};

class Edge : public GraphComponent {
public:

    Edge(const Vertex &start, const Vertex &end, const std::string &label);

    Edge(const Vertex &start, const Vertex &end, double weight = 1, const std::string &label = "");

private:

    const Vertex &start;
    const Vertex &end;
    double weight;
};

class Graph {
public:

    /**
     * Cria um grafo com n vértices.
     *
     * @param n
     */
    explicit Graph(int n = 0);


    /**
     * Destrói o grafo.
     */
    virtual ~Graph();

    /**
     * Limpa o grafo.
     */
    void clear();

    /**
     * Limpa as arestas do grafo.
     */
    void clearEdges();

    /**
     * Insere um vértice no grafo.
     *
     * @param label
     */
    int insertVertex(const std::string &label = "");

    /**
     * Insere uma aresta (v1, v2) ao grafo.
     *
     * @param v1 vértice inicial
     * @param v2 vértice final
     * @param weight custo (peso) da aresta
     */
    void insertEdge(int v1, int v2, int weight);

    /**
     * Executa o algoritmo de kruscal no grafo e armazena em mst a árvore geradora mínima.
     *
     * @param graph o grafo original
     * @param mst a árvore geradora mínima
     */
    static float kruskal(const Graph &graph, Graph &mst);

    /**
     * Executa o algoritmo de prim no grafo e armazena em mst a árvore geradora mínima.
     *
     * @param graph o grafo original
     * @param mst a árvore geradora mínima
     */
    static float prim(const Graph &graph, Graph &mst);
};


#endif //MST_GRAPH_H
