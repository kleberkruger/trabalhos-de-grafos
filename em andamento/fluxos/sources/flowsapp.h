//
// Created by Kleber Kruger on 2019-06-04.
//

#ifndef FLUXOS_FLOWSAPP_H
#define FLUXOS_FLOWSAPP_H


#include "application.h"
#include "graph.h"
#include "flowsalg.h"


//struct InputInfo {
//    Graph graph;
//    mutable int source;
//    mutable int target;
//};
//
//struct OutputInfo {
//};
//
//typedef Algorithm<InputInfo, OutputInfo> FlowAlg;
//
//void fordFulkerson(const InputInfo &in, OutputInfo &out);
//
//void edmondsKarp(const InputInfo &in, OutputInfo &out);




class FlowsApp : public Application<InputInfo, OutputInfo> {
protected:

    std::map<std::string, std::vector<Algorithm<InputInfo, OutputInfo>>> algorithmsMap() override;

    void createInputInfo(const std::string &text, InputInfo &input) override;

    void printOutput(const std::string &filePath, const InputInfo &in, const OutputInfo &out) override;

private:

    const char *FORD_FULKERSON = "ford-fulkerson";
    const char *EDMONDS_KARP = "edmonds-karp";
};


#endif //FLUXOS_FLOWSAPP_H
