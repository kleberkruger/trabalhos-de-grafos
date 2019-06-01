/**
 * Algoritmos em Grafos (MO412)
 *
 * @author: Kleber Kruger <kleberkruger@gmail.com>
 * @author: Felipe Barbosa <felipebarbosa@uft.edu.com>
 * @author: Rodrigo Kanehisa <rodrigokanehisa@gmail.com>
 */

#ifndef CAMINHOS_PATHSAPP_H
#define CAMINHOS_PATHSAPP_H


#include <sstream>
#include <string>
#include <vector>
#include "application.h"
#include "graph.h"
#include "arrayheap.h"
#include "binaryheap.h"
#include "fibonacciheap.h"
//#include "pathsalg.h"


struct InputInfo {
    Graph graph;
    mutable int source;
};

struct OutputInfo {
    std::vector<std::vector<double>> dist;
    std::vector<std::vector<int>> pred;
};


typedef Algorithm<InputInfo, OutputInfo> PathAlg;

class PathsApp : public Application<InputInfo, OutputInfo> {
protected:

    std::map<std::string, std::vector<Algorithm<InputInfo, OutputInfo>>> algorithmsMap() override;

    void createInputInfo(const std::string &text, InputInfo &input) override;

    void printOutput(const std::string &filePath, const InputInfo &in, const OutputInfo &out) override;

private:

    const char *BELLMAN_FORD = "bellman-ford";
    const char *DIJKSTRA = "dijkstra";
    const char *FLOYD_WARSHALL = "floyd-warshall";
    const char *JOHNSON = "johnson";

    static void printPath(const std::string &filePath, std::vector<double> dist, std::vector<int> pred, int source);
};


#endif //CAMINHOS_PATHSAPP_H
