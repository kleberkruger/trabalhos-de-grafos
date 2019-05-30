/**
 * Algoritmos em Grafos (MO412)
 *
 * @author: Kleber Kruger <kleberkruger@gmail.com>
 * @author: Felipe Barbosa <felipebarbosa@uft.edu.com>
 * @author: Rodrigo Kanehisa <rodrigokanehisa@gmail.com>
 */

#include "pathsalg.h"

AlgorithmOutput dijkstra(const Graph &graph) {
    std::cout << "executando o Dijkstra" << std::endl;
    return AlgorithmOutput();
}

void BellmanFord(const Graph &graph, int source, std::vector<float> &dist, std::vector<int> &pred) {
    dist[source] = 0;
    pred[source] = source;

    for (int i = 0; i < graph.vertices.size() - 1; i++) {
        for (auto e : graph.edges) {
            auto u = e.start;
            auto v = e.end;
            auto w = e.weight;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pred[v] = u;
            }
        }
    }

    for (auto e : graph.edges) {
        auto u = e.start;
        auto v = e.end;
        auto w = e.weight;

        if (dist[u] != std::numeric_limits<int>::infinity() && dist[u] + w < dist[v]) {
            throw std::invalid_argument("Negative cycle"); // FIXME: verificar exceção mais adequada.
        }
    }
}

void BellmanFord(const Graph &graph, int source) {
    struct BellmanFordVertex {
        float dist;
        int pred;

        BellmanFordVertex() : dist(std::numeric_limits<float>::infinity()), pred(-1) {}
    };

    std::vector<BellmanFordVertex> vertices(graph.vertices.size());
    vertices[source].dist = 0;

    for (int i = 0; i < graph.vertices.size() - 1; i++) {
        for (auto e : graph.edges) {
            auto &u = vertices[e.start];
            auto &v = vertices[e.end];
            auto w = e.weight;

            if (v.dist > u.dist + w) {
                v.dist = u.dist + w;
                v.pred = e.start; // u
            }
        }
    }

    for (auto e: graph.edges) {
        auto &u = vertices[e.start];
        auto &v = vertices[e.end];
        auto w = e.weight;

        if (v.dist > u.dist + w) {
            throw std::invalid_argument("Negative cycle"); // FIXME: verificar exceção mais adequada.
        }
    }
}

template<class DS>
void Dijkstra(const Graph &graph, int source, std::vector<float> &dist, std::vector<int> &pred) {
    DS Q(graph.vertices.size(), source);

    dist[source] = 0;
    pred[source] = source;

    while (!Q.empty()) {
        Vertex u = graph.vertices[Q.extractMin()];

        for (auto &e : graph.getAdjacencyList(u.id)) {
            auto v = e.end;
            auto w = e.weight;

            if (dist[v] > dist[u.id] + w) {
                dist[v] = dist[u.id] + w;
                pred[v] = u.id;
                Q.decreaseKey(v, w);
            }
        }
    }
}

template<class DS>
void Dijkstra(const Graph &graph, int source) {

}

std::vector<std::vector<int>> PredInit(const Graph &graph)
{
    auto adjMatrix = graph.getMinAdjacencyMatrix();

    std::vector<std::vector<int>> pred;
    std::vector<int> line(adjMatrix.size(), -1);

    for(int i = 0; i < adjMatrix.size(); i++)
        pred.emplace_back(line);

    for(int i = 0; i < (int)adjMatrix.size(); i++)
        for(int j = 0; j < (int)adjMatrix.size(); j++)
            if(adjMatrix[i][j] != std::numeric_limits<double>::infinity() && i != j)
                pred[i][j] = i;

    return pred;
}

void FloydWarshall(const Graph &graph, std::vector<std::vector<double>> &dist, std::vector<std::vector<int>> &pred)
{
    auto adjMatrix = graph.getMinAdjacencyMatrix();
    int n = adjMatrix.size();

    pred = PredInit(graph);

    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    pred[i][j] = pred[k][j];
                }
}


void Johnson(const Graph &graph, std::vector<float> &dist, std::vector<int> &pred) {
    Graph copy = graph;
    auto id = graph.vertices.size();
    copy.insertVertex(graph.vertices.size());

    for (auto v : graph.vertices) {
        copy.insertEdge(id, v.id, 0);
    }

    BellmanFord(copy, id, dist, pred);

    for (auto u : copy.vertices) {
        for (auto v : copy.vertices) {

        }
    }
}
