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

#include <list>
#include <queue>
#include <string>
#include <vector>

/**
 * Classe que representa um componente (vértice ou aresta) de um grafo.
 */
class GraphComponent {
private:

    const int id;
    std::string label;

protected:

    explicit GraphComponent(const int id, const std::string &label) : id(id), label(label) {}

public:

    const int getId() const { return id; }

    const std::string &getLabel() const { return label; }

    void setLabel(const std::string &label) { GraphComponent::label = label; }
};

/**
 * Classe que representa um vértice do grafo.
 */
class Vertex : public GraphComponent {
private:

    const std::list<Vertex *> adjacent;

public:

    explicit Vertex(const int id, const std::string &label = "")
            : GraphComponent::GraphComponent(id, label) {}
};

class Edge : public GraphComponent {
public:

    Edge(const int id, const Vertex &start, const Vertex &end, const std::string &label)
            : GraphComponent(id, label), start(start), end(end) {}

    Edge(const int id, const Vertex &start, const Vertex &end, float weight = 1, const std::string &label = "")
            : GraphComponent(id, label), start(start), end(end), weight(weight) {}

public:

    const Vertex &start;
    const Vertex &end;
    float weight;
};

class Graph {
private:

    std::vector<Vertex *> vertex;
    std::vector<Edge *> edges;

public:

    /**
     * Cria um grafo com n vértices.
     *
     * @param n
     */
    explicit Graph(int n = 0) {
        for (int i = 0; i < n; i++) {
            insertVertex();
        }
    }


    /**
     * Destrói o grafo.
     */
    virtual ~Graph() {

    }

    /**
     * Limpa o grafo.
     */
    void clear() {

    }

    /**
     * Limpa as arestas do grafo.
     */
    void clearEdges() {

    }

    /**
     * Insere um vértice no grafo.
     *
     * @param label
     */
    int insertVertex(const std::string &label = "") {
        static int id = 0;
        auto *v = new Vertex(id, label);
        vertex.push_back(v);
        return id++;
    }

    /**
     * Insere uma aresta (v1, v2) ao grafo.
     *
     * @param v1 vértice inicial
     * @param v2 vértice final
     * @param weight custo (peso) da aresta
     */
    void insertEdge(int v1, int v2, float weight) {
        static int id = 0;
        auto *e = new Edge(id, *vertex[v1], *vertex[v2], weight);
        edges.push_back(e);
        id++;
    }

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
