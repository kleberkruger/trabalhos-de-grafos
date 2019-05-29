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

#ifndef MST_APPLICATION_H
#define MST_APPLICATION_H

#include <chrono>
#include <string>
#include <vector>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "graph.h"

enum Algorithm {
    NONE = 0, BELLMANFORD = 1, DIJKSTRA = 2, FLOYDWARSHALL = 3, JOHNSON = 4
};

struct Task {

    explicit Task(std::string description);

    std::string description;
    std::chrono::high_resolution_clock::time_point timePoint;
};


class Application {
public:

    Application();

    void start(Algorithm algorithm, int version, const std::string &inputFilePath, const std::string &outputFilePath);

    void checkPoint(const std::string &task);

private:

    static const int BUFFER_SIZE = 65536;
    std::vector<Task> tasks;

    std::string readInputFile(const std::string &filePath);

    void printPath(std::vector<float> dist, std::vector<int> pred);

    void printPath(std::vector<float> dist, std::vector<int> pred, int vertex);

    void printCheckPoints();
};


#endif //MST_APPLICATION_H
