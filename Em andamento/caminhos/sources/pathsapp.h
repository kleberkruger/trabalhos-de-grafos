/**
 * Algoritmos em Grafos (MO412)
 *
 * @author: Kleber Kruger <kleberkruger@gmail.com>
 * @author: Felipe Barbosa <felipebarbosa@uft.edu.com>
 * @author: Rodrigo Kanehisa <rodrigokanehisa@gmail.com>
 */


#ifndef CAMINHOS_PATHSAPP_H
#define CAMINHOS_PATHSAPP_H


#include "application.h"


class PathsApp : public Application {

    Algorithm selectAlgorithm(const std::string &algorithm, int version) override;

    Graph createGraph(const std::string &input) override;

    void printOutput(AlgorithmOutput output) override;
};


#endif //CAMINHOS_PATHSAPP_H
