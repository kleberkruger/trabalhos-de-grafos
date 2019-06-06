//
// Created by Kleber Kruger on 2019-06-04.
//

#include "flowsalg.h"

enum Color {
    WHITE, GRAY, BLACK
};

struct SearchVertex {
    int vertex;
    int parent;
    long distance;
    unsigned long finished;
    Color color;

    explicit SearchVertex(int vertex) : vertex(vertex), parent(-1),
                                        distance(std::numeric_limits<long>::max()), color(WHITE) {}
};

/**
 *
 * @param graph
 * @param s
 * @param t
 */
void breadthFirstSearch(const Graph &graph, int s, int t) {
    std::vector<SearchVertex> vertices;
    vertices.reserve(graph.vertices.size());

    for (auto &v : graph.vertices) {
        vertices.emplace_back(v.id);
    }

    vertices[s].color = GRAY;
    vertices[s].distance = 0;

    for (auto &v : vertices) {
        std::cout << "v=" << v.vertex << " p=" << v.parent << " d=" << v.distance << " c=" << v.color << std::endl;
    }

    std::deque<SearchVertex *> q;
    q.push_back(&vertices[s]);

    while (!q.empty()) {
        auto &u = q.front();
        q.pop_front();

        for (auto &e : graph.getAdjacencyList(u->vertex)) {
            auto &v = vertices[e->end];
            if (v.color == WHITE) {
                v.color = GRAY;
                v.distance = u->distance + 1;
                v.parent = u->vertex;
                q.push_back(&v);
            }
        }
        u->color = BLACK;
    }

    std::cout << "Resposta: " << std::endl;
    for (auto &v : vertices) {
        std::cout << "v=" << v.vertex << " p=" << v.parent << " d=" << v.distance << " c=" << v.color << std::endl;
    }
}

bool DFSVisit(const Graph &graph, std::vector<SearchVertex> &vertices, int s, int t,
              std::pair<int, std::vector<Edge *>> &path) {

//    std::cout << "visitando v " << s << std::endl;

    auto &u = vertices[s];
    u.color = GRAY;
//    path.second.push_back(u.vertex);
    if (u.vertex == t) {
//        std::cout << "encontrei o " << t << std::endl;
        u.color = BLACK;
        return true;
    }

    for (auto &e : graph.getAdjacencyList(u.vertex)) {
        if (e->capacity > 0) {
            auto &v = vertices[e->end];
            if (v.color == WHITE) {
                v.parent = u.vertex;
//            if (e.capacity < path.first) path.first = e.capacity;
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

/**
 *
 * @param graph
 * @param s
 * @param t
 */
bool DFS(const Graph &graph, int s, int t, std::pair<int, std::vector<Edge *>> &path) {
    std::vector<SearchVertex> vertices;
    vertices.reserve(graph.vertices.size());

    for (auto &u : graph.vertices) {
        vertices.emplace_back(u.id);
    }

    path.first = std::numeric_limits<int>::max();
    path.second.clear();

    return DFSVisit(graph, vertices, s, t, path);

    // chamar primeiro para o source
//    if (vertices[s].color == WHITE)
//        DFSVisit(graph, vertices, vertices[s], t, time);
//    for (auto &u : vertices) {
//        if (u.color == WHITE) DFSVisit(graph, vertices, u, t, time);
//    }

//    for (auto &v : vertices) {
//        std::cout << "v=" << v.vertex << " p=" << v.parent << " d=" << v.distance << " f=" << v.finished << " c="
//                  << v.color << std::endl;
//    }
}

void fordFulkerson(const InputInfo &in, OutputInfo &out) {
    std::pair<int, std::vector<Edge *>> path;
    long total = 0;

    Graph residual = in.graph;
    for (auto &e : residual.edges) {
        residual.insertEdge(e.end, e.start, 0);
    }

    auto &matrix = in.graph.getMinAdjacencyMatrix();
    auto &matrixR = residual.getMinAdjacencyMatrix();

    while (DFS(residual, in.source, in.target, path)) {
        for (auto p : path.second) std::cout << "(" << p->start << "," << p->end << ") ";
        std::cout << path.first << std::endl;

        total += path.first;

        for (auto &e : path.second) {
            if (matrix[e->start][e->end] != nullptr) {
                matrix[e->start][e->end]->flow += path.first;
            } else {
                matrix[e->end][e->start]->flow -= path.first;
            }
            matrixR[e->start][e->end]->capacity -= path.first;
            matrixR[e->end][e->start]->capacity += path.first;
        }

        in.graph.print();
        residual.print();

        std::cout << total << std::endl;
    }
}

void edmondsKarp(const InputInfo &in, OutputInfo &out) {
//    breadthFirstSearch(in.graph, in.source);
//    DFS(in.graph, in.source, in.target);
}

//void FlowAlgs::fordFulkerson(const InputInfo &in, OutputInfo &out) {
//
//}
//
//void FlowAlgs::edmondsKarp(const InputInfo &in, OutputInfo &out) {
//
//}
