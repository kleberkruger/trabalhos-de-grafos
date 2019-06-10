/**
 * Algoritmos em Grafos (MO412)
 *
 * @author: Kleber Kruger <kleberkruger@gmail.com>
 * @author: Felipe Barbosa <felipebarbosa@uft.edu.com>
 * @author: Rodrigo Kanehisa <rodrigokanehisa@gmail.com>
 */

#ifndef CAMINHOS_GRAPH_H
#define CAMINHOS_GRAPH_H

#include <iostream>
#include <vector>

struct Vertex;
struct Edge;
//struct EdgeTo;

struct Vertex {

    /**
     * Cria um vértice.
     *
     * @param id
     */
    explicit Vertex(int id);

    int id;
};

struct Edge {

    /**
     * Cria uma aresta.
     *
     * @param start id do vértice inicial
     * @param end id do vértice final
     * @param capacity capacidade da aresta
     */
    explicit Edge(int start, int end, int capacity);

//    bool operator<(const Edge &other) const { return capacity < other.capacity; }
//
//    bool operator>(const Edge &other) const { return capacity > other.capacity; }
//
//    bool operator<=(const Edge &other) const { return capacity <= other.capacity; }
//
//    bool operator>=(const Edge &other) const { return capacity >= other.capacity; }

    bool operator==(const Edge &other) const { return start == other.start && end == other.end && capacity == other.capacity; }

    bool operator!=(const Edge &other) const { return start != other.start || end != other.end || capacity != other.capacity; }

    int start, end, capacity, flow;
};

//struct EdgeTo {
//
//    /**
//     * Cria uma "meia aresta".
//     *
//     * @param end
//     * @param capacity
//     */
//    EdgeTo(int start, int end, int capacity);
//
//    virtual ~EdgeTo();
//
//    int start, end, capacity;
//};

class Graph {
public:

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
     * @param capacity
     */
    void insertEdge(int v1, int v2, int capacity);

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
    void print() const;

    /**
     * Imprime a lista de adjacências do grafo (usado para debug).
     */
    void printAdjacencyList() const;

    /**
     * Imprime a matriz de adjacências (usado para debug).
     */
    void printAdjacencyMatrix() const;

    /**
     * Retorna a lista de adjacências do grafo.
     *
     * @return
     */
    const std::vector<std::vector<Edge *>> &getAdjacencyList() const;

    /**
     * Retorna a lista de adjacências de um vértice especificado.
     *
     * @param vertex
     * @return
     */
    const std::vector<Edge *> &getAdjacencyList(int vertex) const;

    /**
     * Retorna a lista de adjacências do grafo.
     *
     * @return
     */
    const std::vector<std::vector<Edge *>> &getMinAdjacencyList() const;

    /**
     * Retorna a lista de adjacências de um vértice especificado.
     *
     * @param vertex
     * @return
     */
    const std::vector<Edge *> &getMinAdjacencyList(int vertex) const;

    /**
     * Retorna a matriz de adjacência do grafo.
     *
     * @return
     */
    const std::vector<std::vector<Edge *>> &getMinAdjacencyMatrix() const;

//    /**
//     * Retorna a matriz de adjacência do grafo.
//     *
//     * @return
//     */
//    const std::vector<std::vector<std::vector<double>>> &getAdjacencyMatrix() const;
//
//    /**
//     * Retorna os valores das arestas na posição (x,y) da matriz de adjacências.
//     *
//     * @param x
//     * @param y
//     *
//     * @return
//     */
//    const std::vector<double> &getAdjacencyMatrix(int x, int y) const;

    template<typename T>
    static void printMatrix(const std::vector<std::vector<T>> matrix) {
        printf("==================================================\n");
        for (const auto &i : matrix) {
            for (double j : i) {
                printf("%4.1lf", (double) j);
            }
            printf("\n");
        }
        printf("==================================================\n");
    }

    std::vector<Vertex> vertices;
    std::vector<Edge> edges;

private:

    mutable std::vector<std::vector<Edge *>> adjacencyList;
    mutable std::vector<std::vector<Edge *>> minAdjacencyMatrix;
    mutable bool updatedList{};
    mutable bool updatedMatrix{};
//    mutable std::vector<std::vector<std::vector<double>>> adjacencyMatrix; // e se existir várias arestas de a para b?

    void graphChanged();
};


#endif //CAMINHOS_GRAPH_H
