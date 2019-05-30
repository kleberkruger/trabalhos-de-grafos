/**
 * Algoritmos em Grafos (MO412)
 *
 * @author: Kleber Kruger <kleberkruger@gmail.com>
 * @author: Felipe Barbosa <felipebarbosa@uft.edu.com>
 * @author: Rodrigo Kanehisa <rodrigokanehisa@gmail.com>
 */

#ifndef CAMINHOS_APPLICATION_H
#define CAMINHOS_APPLICATION_H

#include <chrono>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fcntl.h>
#include <zconf.h>
#include <sys/filio.h>
#include <sys/ioctl.h>
#include "graph.h"

struct AlgorithmOutput {

};

struct Algorithm {

    const std::string name;
    AlgorithmOutput (*execute)(const Graph &graph);
    const std::string alias;

    Algorithm(std::string name, AlgorithmOutput (*execute)(const Graph &), std::string alias = "")
            : name(std::move(name)), execute(execute), alias(std::move(alias)) {}
};

struct Task {

    explicit Task(std::string description);

    std::string description;
    std::chrono::high_resolution_clock::time_point timePoint;
};

class Application {
public:

    void start(const std::string &algorithm, int version, const std::string &inputFilePath,
               const std::string &outputFilePath);

protected:

    virtual std::map<std::string, std::vector<Algorithm>> algorithmsMap() = 0;

    virtual Graph createGraph(const std::string &input) = 0;

    virtual void printOutput(AlgorithmOutput output) = 0;

private:

    static const int BUFFER_SIZE = 65536;

    static std::string readInputFile(const std::string &filePath);

    static void printTasks(std::vector<Task> tasks);

    Algorithm selectAlgorithm(const std::string &algorithm, unsigned short version);
};


#endif //CAMINHOS_APPLICATION_H
