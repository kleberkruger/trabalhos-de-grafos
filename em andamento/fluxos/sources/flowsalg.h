//
// Created by Kleber Kruger on 2019-06-04.
//

#ifndef FLUXOS_FLOWSALG_H
#define FLUXOS_FLOWSALG_H


#include "graph.h"

struct InputInfo {
    Graph graph;
    mutable int source;
    mutable int target;
};

struct OutputInfo {
};

template<typename AIn, typename AOut>
struct Algorithm;

typedef Algorithm<InputInfo, OutputInfo> FlowAlg;

void fordFulkerson(const InputInfo &in, OutputInfo &out);

void edmondsKarp(const InputInfo &in, OutputInfo &out);

//class FlowAlgs {
//public:
//
//    static void fordFulkerson(const InputInfo &in, OutputInfo &out);
//
//    static void edmondsKarp(const InputInfo &in, OutputInfo &out);
//};


#endif //FLUXOS_FLOWSALG_H
