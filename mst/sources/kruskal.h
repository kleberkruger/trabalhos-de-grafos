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

#ifndef MST_KRUSKAL_H
#define MST_KRUSKAL_H


#include <vector>
#include "graph.h"

// FIXME: Seria interessante transformar o Kruskal apenas em ima função template?
template<class DS>
class Kruskal {
public:

    double execute(const Graph &graph, Graph &mst) {
        mst = graph;
        mst.clearEdges();
//        mst.print();

        double total = 0;

        DS ds(mst.vertices.size());

        std::vector<Edge> edges = graph.edges;
        std::sort(edges.begin(), edges.end());

        for (auto e : edges) {
//            std::cout << "examinando (v" << e.start << ", v" << e.end << ") w(" << e.weight << ")" << std::endl;
            if (ds.find(e.start) != ds.find(e.end)) {
//                std::cout << "INSERINDO (v" << e.start << ", v" << e.end << ") w(" << e.weight << ")" << std::endl;
                mst.insertEdge(e.start, e.end, e.weight);
                ds.join(e.start, e.end);
                total += e.weight;
            }
        }

        return total;
    }
};


#endif //MST_KRUSKAL_H
