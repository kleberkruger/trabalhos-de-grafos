//
// Created by Kleber Kruger on 2019-06-04.
//

#include "flowsapp.h"

//void fordFulkerson(const InputInfo &in, OutputInfo &out) {
//
//}
//
//void edmondsKarp(const InputInfo &in, OutputInfo &out) {
//
//}


std::map<std::string, std::vector<Algorithm<InputInfo, OutputInfo>>> FlowsApp::algorithmsMap() {
    std::map<std::string, std::vector<Algorithm<InputInfo, OutputInfo>>> algorithms;

    algorithms[FORD_FULKERSON].push_back(FlowAlg("Ford Fulkerson", fordFulkerson));
    algorithms[EDMONDS_KARP].push_back(FlowAlg("Edmonds Karp", edmondsKarp));

    return algorithms;
}

void FlowsApp::createInputInfo(const std::string &text, InputInfo &in) {
    char *token;
    int n = strtol(text.c_str(), &token, 10);
    int m = strtol(token, &token, 10);
    int s = strtol(token, &token, 10);
    int t = strtol(token, &token, 10);

    Graph graph(n, m);

    for (int i = 0; i < m; i++) {
        int v1 = strtol(token, &token, 10);
        int v2 = strtol(token, &token, 10);
        int c = strtol(token, &token, 10);
        graph.insertEdge(v1, v2, c);
    }

    in.graph = graph;
    in.source = s;
    in.target = t;
}

void FlowsApp::printOutput(const std::string &filePath, const InputInfo &in, const OutputInfo &out) {

}
