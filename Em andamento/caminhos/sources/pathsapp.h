/**
 * Algoritmos em Grafos (MO412)
 *
 * @author: Kleber Kruger <kleberkruger@gmail.com>
 * @author: Felipe Barbosa <felipebarbosa@uft.edu.com>
 * @author: Rodrigo Kanehisa <rodrigokanehisa@gmail.com>
 */

#ifndef CAMINHOS_PATHSAPP_H
#define CAMINHOS_PATHSAPP_H


#include <string>
#include <vector>
#include "application.h"
#include "graph.h"
#include "binaryheap.h"


struct InputInfo {
    Graph graph;
    int source;
};

struct OutputInfo {
    std::vector<std::vector<float>> dist;
    std::vector<std::vector<int>> pred;
};


typedef Algorithm<InputInfo, OutputInfo> PathAlg;

class PathsApp : public Application<InputInfo, OutputInfo> {
protected:

    std::map<std::string, std::vector<Algorithm<InputInfo, OutputInfo>>> algorithmsMap() override;

    void createInputInfo(const std::string &text, InputInfo &input) override;

    void printOutput(OutputInfo output) override;

private:

    const char *BELLMAN_FORD = "bellman-ford";
    const char *DIJKSTRA = "dijkstra";
    const char *FLOYD_WARSHALL = "floyd-warshall";
    const char *JOHNSON = "johnson";
};


#endif //CAMINHOS_PATHSAPP_H
