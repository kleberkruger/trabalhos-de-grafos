//
// Created by Kleber Kruger on 2019-05-31.
//

#include "pathsalg.h"

//template<class DS>
//void dijkstra(const Graph &graph, int source, std::vector<double> &dist, std::vector<int> &pred) {
//    DS Q(graph.vertices.size(), source);
//
//    dist[source] = 0;
//    pred[source] = source;
//
//    while (!Q.empty()) {
//        Vertex u = graph.vertices[Q.extractMin()];
//        for (auto &e : graph.getAdjacencyList(u.id)) {
//            auto v = e.end;
//            auto w = e.weight;
//            if (dist[v] > dist[u.id] + w) {
//                dist[v] = dist[u.id] + w;
//                pred[v] = u.id;
//                Q.decreaseKey(v, w);
//            }
//        }
//    }
//}
//
//template<class DS>
//void dijkstra(const InputInfo &in, OutputInfo &out) {
//    out.dist.emplace_back(in.graph.vertices.size(), std::numeric_limits<double>::infinity());
//    out.pred.emplace_back(in.graph.vertices.size(), -1);
//
//    dijkstra<DS>(in.graph, in.source, out.dist[0], out.pred[0]);
//}