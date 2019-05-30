/**
 * Algoritmos em Grafos (MO412)
 *
 * @author: Kleber Kruger <kleberkruger@gmail.com>
 * @author: Felipe Barbosa <felipebarbosa@uft.edu.com>
 * @author: Rodrigo Kanehisa <rodrigokanehisa@gmail.com>
 */


#ifndef CAMINHOS_PATHSAPP_H
#define CAMINHOS_PATHSAPP_H


#include <map>
#include "application.h"


class PathsApp : public Application {
private:

    std::map<std::string, std::vector<Algorithm>> algorithmsMap() override;

    Graph createGraph(const std::string &input) override;

    void printOutput(AlgorithmOutput output) override;

private:

    const char *BELLMAN_FORD = "bellman-ford";
    const char *DIJKSTRA = "dijkstra";
    const char *FLOYD_WARSHALL = "floyd-warshall";
    const char *JOHNSON = "johnson";
};


#endif //CAMINHOS_PATHSAPP_H
