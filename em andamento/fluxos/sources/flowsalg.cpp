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

void breadthFirstSearch(const Graph &graph, int s) {
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

    std::queue<SearchVertex *> q;
    q.push(&vertices[s]);

    while (!q.empty()) {
        auto &u = q.front();
        q.pop();

        for (auto &e : graph.getAdjacencyList(u->vertex)) {
            auto &v = vertices[e.end];
            if (v.color == WHITE) {
                v.color = GRAY;
                v.distance = u->distance + 1;
                v.parent = u->vertex;
                q.push(&v);
            }
        }
        u->color = BLACK;
    }

    std::cout << "resposta: " << std::endl;
    for (auto &v : vertices) {
        std::cout << "v=" << v.vertex << " p=" << v.parent << " d=" << v.distance << " c=" << v.color << std::endl;
    }
}

void depthFirstSearchVisit(const Graph &graph, std::vector<SearchVertex> &vertices,
                           SearchVertex &u, unsigned long &time) {
    u.distance = ++time;
    u.color = GRAY;
    for (auto &e : graph.getAdjacencyList(u.vertex)) {
        auto &v = vertices[e.end];
        if (v.color == WHITE) {
            v.parent = u.vertex;
            depthFirstSearchVisit(graph, vertices, v, time);
        }
    }
    u.color = BLACK;
    u.finished = ++time;
}

void depthFirstSearch(const Graph &graph, int s) {
    std::vector<SearchVertex> vertices;
    vertices.reserve(graph.vertices.size());

    for (auto &u : graph.vertices) {
        vertices.emplace_back(u.id);
    }

    unsigned long time = 0;

    for (auto &u : vertices) {
        if (u.color == WHITE) depthFirstSearchVisit(graph, vertices, u, time);
    }

    for (auto &v : vertices) {
        std::cout << "v=" << v.vertex << " p=" << v.parent << " d=" << v.distance << " f=" << v.finished << " c="
                  << v.color << std::endl;
    }
}


void fordFulkerson(const InputInfo &in, OutputInfo &out) {
//    breadthFirstSearch(in.graph, in.source);
    depthFirstSearch(in.graph, in.source);
}

void edmondsKarp(const InputInfo &in, OutputInfo &out) {
//    breadthFirstSearch(in.graph, in.source);
    depthFirstSearch(in.graph, in.source);
}

//void FlowAlgs::fordFulkerson(const InputInfo &in, OutputInfo &out) {
//
//}
//
//void FlowAlgs::edmondsKarp(const InputInfo &in, OutputInfo &out) {
//
//}
