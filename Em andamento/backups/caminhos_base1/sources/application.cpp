#include <utility>

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

#include "application.h"


Task::Task(std::string description) : description(std::move(description)),
#ifdef __OSX_AVAILABLE
                                      timePoint(std::chrono::steady_clock::now()) {}

#else
timePoint(std::chrono::system_clock::now()) {}
#endif

Application::Application() {
    tasks.reserve(5);
}

void checkParameters(Algorithm algorithm, int version,
                     const std::string &inputFilePath, const std::string &outputFilePath) {

    if (algorithm == NONE) {
        throw std::invalid_argument("Incorrect algorithm. Run in <algorithm>: <kruskal> or <prim>");
    }
}

std::string Application::readInputFile(const std::string &filePath) {
    char buffer[BUFFER_SIZE];
    int returned;

    std::cout << "Reading input file: \"" << filePath << "\"..." << std::endl;

    int fd = open(filePath.data(), O_RDONLY);

    std::size_t size;
    ioctl(fd, FIONREAD, &size);
    std::string text;
    text.reserve(size);

    while ((returned = read(fd, buffer, sizeof(buffer))) > 0) {
        buffer[returned] = 0x00;
        text.append(buffer);
    }

    return text;
}

void Application::start(Algorithm algorithm, int version,
                        const std::string &inputFilePath, const std::string &outputFilePath) {

    checkParameters(algorithm, version, inputFilePath, outputFilePath);

    checkPoint("read input file");
    std::string text = readInputFile(inputFilePath);

    checkPoint("create the graph");
    char *token;
    int n = strtol(text.c_str(), &token, 10);
    int m = strtol(token, &token, 10);
    Graph graph(n, m);
    for (int i = 0; i < m; i++) {
        graph.insertEdge(strtol(token, &token, 10), strtol(token, &token, 10), strtod(token, &token));
    }

    std::vector<float> dist(graph.vertices.size(), std::numeric_limits<float>::infinity());
    std::vector<int> pred(graph.vertices.size(), -1);

    checkPoint("run algorithm");

//    auto &matrix = graph.getMinAdjacencyMatrix();
//    for (int i = 0; i < matrix.size(); i++) {
//        for (int j = 0; j < matrix[i].size(); j++) {
//            if (j == 0)
//                printf("|");
//
//            printf(" %3.1f ", matrix[i][j]);
//
//            if (j == matrix.size() - 1)
//                printf("|");
//        }
//        printf("\n");
//    }
//    printf("\n");

    Graph::path(graph, 3, dist, pred);

//    graph.print();
//
//    Graph::BellmanFord(graph, 3, dist, pred);
//    Graph::BellmanFord(graph, 3);
//
//    checkPoint("print the paths");
////    printPath(dist, pred);
//
//    for (float f : dist) {
//        std::cout << f << " ";
//    }
//    std::cout << std::endl;
//    for (int i = 0; i < pred.size(); i++) {
//        std::cout << i << ": " << pred[i] << std::endl;
//    }
//    std::cout << std::endl;

    printPath(dist, pred, 3);

    checkPoint("finished");
    printCheckPoints();
}

void Application::checkPoint(const std::string &task) {
    tasks.emplace_back(task);
}

void Application::printPath(std::vector<float> dist, std::vector<int> pred, int source) {

    for (int i = 0; i < dist.size(); i++) {
        std::vector<int> path(dist.size(), -1);
        std::cout << dist[i] << " " << source << " ";

        int aux = 0;
        int curr = pred[i];

        do {
            path[aux] = curr;
            curr = pred[curr];
            aux++;
        } while (curr != source);

        std::reverse(path.begin(), path.end());

        for (int j : path) {
            if (j != -1) std::cout << " v" << j << " ";
        }

        std::cout << i << std::endl;
    }
}

void Application::printPath(std::vector<std::vector<float>> dist, std::vector<std::vector<int>> pred) {
    for (int i = 0; i < dist.size(); i++) {
        printPath(dist[i], pred[i], i);
    }
}

void Application::printCheckPoints() {
    std::cout << std::endl
              << "================================================================================" << std::endl;

    for (int i = 0; i < tasks.size() - 1; i++) {
        std::cout << "Time to " << tasks[i].description << ": "
                  << std::chrono::duration_cast<std::chrono::milliseconds>(
                          tasks[i + 1].timePoint - tasks[i].timePoint).count()
                  << " ms" << std::endl;
    }
    std::cout << "--------------------------------------------------------------------------------" << std::endl
              << " Total time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(
                      tasks[tasks.size() - 1].timePoint - tasks[0].timePoint).count() << " ms" << std::endl
              << "================================================================================"
              << std::endl;
}