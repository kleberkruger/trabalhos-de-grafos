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
                                      timePoint(std::chrono::steady_clock::now()) {}


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

void Application::printMST(const std::string &filePath, const Graph &mst, double total) {
    FILE *fp = fopen(filePath.data(), "w");
    fprintf(fp, "%.2lf\n", total);
    for (auto &e : mst.edges) {
        fprintf(fp, "%d %d %.2lf\n", e.start, e.end, e.weight);
    }
    fclose(fp);
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

    checkPoint("run algorithm");
    Graph mst;
    double total = Graph::mst(graph, mst, algorithm - 1, version);

    checkPoint("print MST");
    printMST(outputFilePath, mst, total);

    checkPoint("finished");
    printCheckPoints();
}

void Application::checkPoint(const std::string &task) {
    tasks.emplace_back(task);
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
