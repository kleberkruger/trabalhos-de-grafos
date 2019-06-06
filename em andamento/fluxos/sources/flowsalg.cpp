//
// Created by Kleber Kruger on 2019-06-04.
//

#include "flowsalg.h"

enum Color {
    WHITE, GRAY, BLACK
};

struct SearchVertex {
    int vertex;
    Edge *parent;
    Color color;

    explicit SearchVertex(int vertex) : vertex(vertex), parent(nullptr), color(WHITE) {}
};

bool BFS(const Graph &graph, int s, int t, std::pair<int, std::vector<Edge *>> &path) {
    std::vector<SearchVertex> vertices;
    vertices.reserve(graph.vertices.size());
    for (auto &v : graph.vertices) {
        vertices.emplace_back(v.id);
    }

    vertices[s].color = GRAY;

    path.first = std::numeric_limits<int>::max();
    path.second.clear();

    if (s == t) return true;

    std::deque<SearchVertex *> q;
    q.push_back(&vertices[s]);

    while (!q.empty()) {
        auto &u = q.front();
        q.pop_front();

        for (auto &e : graph.getAdjacencyList(u->vertex)) {
            if (e->capacity > 0) {
                auto &v = vertices[e->end];
                if (v.color == WHITE) {
                    v.color = GRAY;
                    v.parent = e;
                    q.push_back(&v);

                    if (v.vertex == t) {
//                    std::cout << "encontrei o " << v.vertex << std::endl;
                        path.first = e->capacity;
                        path.second.emplace_back(e);
                        auto aux = e;
                        while (aux->start != s) {
//                        std::cout << aux->start << " " << aux->end << std::endl;
                            aux = vertices[aux->start].parent;
                            path.second.emplace_back(aux);
                            if (aux->capacity < path.first) path.first = aux->capacity;
                        }

                        return true;
                    }
                }
            }
        }
        u->color = BLACK;
    }

    return false;
}

bool DFSVisit(const Graph &graph, std::vector<SearchVertex> &vertices, int s, int t,
              std::pair<int, std::vector<Edge *>> &path) {

    auto &u = vertices[s];
    u.color = GRAY;
    if (u.vertex == t) {
        u.color = BLACK;
        return true;
    }

    for (auto &e : graph.getAdjacencyList(u.vertex)) {
        if (e->capacity > 0) {
            auto &v = vertices[e->end];
            if (v.color == WHITE) {
                if (DFSVisit(graph, vertices, v.vertex, t, path)) {
                    if (e->capacity < path.first) path.first = e->capacity;
                    path.second.push_back(e);
                    return true;
                }
            }
        }
    }
    u.color = BLACK;
    return false;
}

bool DFS(const Graph &graph, int s, int t, std::pair<int, std::vector<Edge *>> &path) {
    std::vector<SearchVertex> vertices;
    vertices.reserve(graph.vertices.size());

    for (auto &u : graph.vertices) {
        vertices.emplace_back(u.id);
    }

    path.first = std::numeric_limits<int>::max();
    path.second.clear();

    return DFSVisit(graph, vertices, s, t, path);
}

void compadreWashington(const InputInfo &in, OutputInfo &out,
                        bool (*search)(const Graph &, int, int, std::pair<int, std::vector<Edge *>> &)) {

    std::pair<int, std::vector<Edge *>> path;
    out.total = 0;

    Graph residual = in.graph;
    for (auto &e : residual.edges) {
        residual.insertEdge(e.end, e.start, 0);
    }

    auto &matrix = in.graph.getMinAdjacencyMatrix();
    auto &matrixR = residual.getMinAdjacencyMatrix();

    while (search(residual, in.source, in.target, path)) {
//        for (auto p : path.second) std::cout << "(" << p->start << "," << p->end << ") ";
//        std::cout << path.first << std::endl;

        out.total += path.first;
        for (auto &e : path.second) {
            if (matrix[e->start][e->end] != nullptr) {
                matrix[e->start][e->end]->flow += path.first;
            } else {
                matrix[e->end][e->start]->flow -= path.first;
            }
            matrixR[e->start][e->end]->capacity -= path.first;
            matrixR[e->end][e->start]->capacity += path.first;
        }
    }
//    std::cout << out.total << std::endl;
}

void fordFulkerson(const InputInfo &in, OutputInfo &out) {
    compadreWashington(in, out, DFS);
}

void edmondsKarp(const InputInfo &in, OutputInfo &out) {
    compadreWashington(in, out, BFS);
}
