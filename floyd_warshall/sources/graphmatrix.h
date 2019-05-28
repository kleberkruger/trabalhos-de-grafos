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

#ifndef MST_GRAPHMATRIX_H
#define MST_GRAPHMATRIX_H

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstdio>
#include <limits>

class GraphMatrix{
  public:
    explicit GraphMatrix(int n = 0);

    void FloydWarshall();
    void ShowGraph();
    void InsertEdge(int a, int b, float value);
    std::vector<std::vector<float>> adjMatrix;

  private:
    void initialize(int n);

};

#endif 