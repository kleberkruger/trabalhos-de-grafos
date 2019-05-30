/**
 * Algoritmos em Grafos (MO412)
 *
 * @author: Kleber Kruger <kleberkruger@gmail.com>
 * @author: Felipe Barbosa <felipebarbosa@uft.edu.com>
 * @author: Rodrigo Kanehisa <rodrigokanehisa@gmail.com>
 */

#ifndef CAMINHOS_PATHSALG_H
#define CAMINHOS_PATHSALG_H


#include "graph.h"
#include "application.h"


AlgorithmOutput dijkstra(const Graph &graph);

void BellmanFord(const Graph &graph, int source, std::vector<float> &dist, std::vector<int> &pred);

void BellmanFord(const Graph &graph, int source = 0);

template<class DS>
void Dijkstra(const Graph &graph, int source, std::vector<float> &dist, std::vector<int> &pred);

template<class DS>
void Dijkstra(const Graph &graph, int source = 0);

std::vector<std::vector<int>> PredInit(const Graph &graph);

void FloydWarshall(const Graph &graph, std::vector<std::vector<float>> &dist, std::vector<std::vector<int>> &pred);

void Johnson(const Graph &graph, std::vector<float> &dist, std::vector<int> &pred);


#endif //CAMINHOS_PATHSALG_H
