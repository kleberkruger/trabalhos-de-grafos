#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <cstring>
#include <sstream>
#include <fstream>
#include <sys/filio.h>
#include <sys/ioctl.h>
#include "graph.h"

static const int BUFFER_SIZE = 65536;

enum Algorithm {
    NONE = 0, KRUSKAL = 1, PRIM = 2
};

void checkParameters(Algorithm alg, int version, const std::string &inFilePath, const std::string &outFilePath) {
    if (alg == NONE) {
        throw std::invalid_argument("Incorrect algorithm. Run in <algorithm>: <kruskal> or <prim>");
    }
}

std::string readFile(const std::string &filePath) {
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

void printMST(const std::string &filePath, const Graph &mst, double total) {
//    std::ofstream outFile;
//    outFile.open(filePath);
//
//    outFile << std::fixed;
//    outFile << total << std::endl;
//
//    for (auto &e : mst.edges) {
//        outFile << e.start << " " << e.end << " " << e.weight << std::endl;
//    }
//    outFile.close();

    FILE *fp = fopen(filePath.data(), "w");
    fprintf(fp, "%.2lf\n", total);
    for (auto &e : mst.edges) {
        fprintf(fp, "%d %d %.2lf\n", e.start, e.end, e.weight);
    }
    fclose(fp);

//    std::stringstream response;
//    response << total << std::endl;
//    for (auto &e : mst.edges) {
//        response << e.start << " " << e.end << " " << e.weight << std::endl;
//    }
//
//    int fd = open(filePath.data(), O_WRONLY);
//    write(fd, response.str().c_str(), response.str().length());
}

void printTimes(std::chrono::high_resolution_clock::time_point &t1, std::chrono::high_resolution_clock::time_point &t2,
                std::chrono::high_resolution_clock::time_point &t3, std::chrono::high_resolution_clock::time_point &t4,
                std::chrono::high_resolution_clock::time_point &t5) {

    std::cout << std::endl
              << "================================================================================" << std::endl
              << " Time to read input file: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << " ms" << std::endl
              << " Time to create graph: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(t3 - t2).count() << " ms" << std::endl
              << " Time to run algorithm: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(t4 - t3).count() << " ms" << std::endl
              << " Time to write MST: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(t5 - t4).count() << " ms" << std::endl
              << "--------------------------------------------------------------------------------" << std::endl
              << " Total time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(t5 - t1).count() << " ms" << std::endl
              << "================================================================================"
              << std::endl;
}

void execute(Algorithm alg, int version, const std::string &inFilePath, const std::string &outFilePath) {
    checkParameters(alg, version, inFilePath, outFilePath);

    auto t1 = std::chrono::high_resolution_clock::now();
    std::string text = readFile(inFilePath);

    auto t2 = std::chrono::high_resolution_clock::now();
    std::cout << "Creating graph..." << std::endl;

    long n, m, v1, v2;
    double w;
    char *token;

    n = strtol(text.c_str(), &token, 10), m = strtol(token, &token, 10);
    Graph graph(n, m);

    for (int i = 0; i < m; i++) {
        v1 = strtol(token, &token, 10), v2 = strtol(token, &token, 10), w = strtod(token, &token);
        graph.insertEdge(v1, v2, w);
    }

    auto t3 = std::chrono::steady_clock::now();

    Graph mst;
    double total = Graph::mst(graph, mst, alg - 1, version);

    auto t4 = std::chrono::steady_clock::now();

    printMST(outFilePath, mst, total);

    auto t5 = std::chrono::steady_clock::now();
    std::cout << "Finished." << std::endl;

    printTimes(t1, t2, t3, t4, t5);
}

void execute_1(Algorithm alg, int version, const std::string &inFilePath, const std::string &outFilePath) {
    checkParameters(alg, version, inFilePath, outFilePath);
    auto t1 = std::chrono::high_resolution_clock::now();

    std::ifstream file(inFilePath);
    if (file.good()) {
        int n, m, v1, v2;
        float w;

        file >> n >> m;
        for (int i = 0; i < m; i++) {
            file >> v1 >> v2 >> w;
            if (i == m - 1) std::cout << v1 << " " << v2 << " " << w << std::endl;
        }
    }
    file.close();
    auto t2 = std::chrono::high_resolution_clock::now();
    std::cout << "Time to create graph: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count()
              << " ms" << std::endl;
}

void execute_2(Algorithm alg, int version, const std::string &inFilePath, const std::string &outFilePath) {
    checkParameters(alg, version, inFilePath, outFilePath);
    auto t1 = std::chrono::high_resolution_clock::now();

    FILE *fp = fopen(inFilePath.data(), "r");
    if (fp) {
        int n, m, v1, v2;
        float w;

        fscanf(fp, "%d\n", &n);
        fscanf(fp, "%d\n", &m);
        for (int i = 0; i < m; i++) {
            fscanf(fp, "%d %d %f\n", &v1, &v2, &w);
            if (i == m - 1) std::cout << v1 << " " << v2 << " " << w << std::endl;
        }
    }
    fclose(fp);

    auto t2 = std::chrono::high_resolution_clock::now();
    std::cout << "Time to create graph: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count()
              << " ms" << std::endl;
}

void execute_3(Algorithm alg, int version, const std::string &inFilePath, const std::string &outFilePath) {
    checkParameters(alg, version, inFilePath, outFilePath);

    char buffer[BUFFER_SIZE];
    int returned;

    auto t1 = std::chrono::high_resolution_clock::now();

    int fd = open(inFilePath.data(), O_RDONLY);

    long long int nbytes;
    ioctl(fd, FIONREAD, &nbytes);
    std::string text;
    text.reserve(nbytes);

    while ((returned = read(fd, buffer, sizeof(buffer))) > 0) {
        buffer[returned] = 0x00;
        text.append(buffer);
    }

    long n, m, v1, v2;
    double w;
    char *token;

    n = strtol(text.c_str(), &token, 10);
    m = strtol(token, &token, 10);
    for (int i = 0; i < m; i++) {
        v1 = strtol(token, &token, 10);
        v2 = strtol(token, &token, 10);
        w = strtod(token, &token);
        if (i == m - 1) std::cout << v1 << " " << v2 << " " << w << std::endl;
    }

    auto t2 = std::chrono::high_resolution_clock::now();
    std::cout << "Total time: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count()
              << " ms" << std::endl;
}

/**
 * Executa a aplicação de acordo com os parâmetros de inicialização.
 *
 * <algorithm> <version> <filepath-in> <filepath-out>
 *
 * <algorithm>: algoritmo de execução (Kruskal ou Prim);
 * <version>: versão do algoritmo (um número inteiro, começando em 0);
 * <filepath-in>: arquivo de entrada que contém as informações do grafo;
 * <filepath-out>: arquivo de saída onde será exibida a MST resultante.
 *
 * Exemplos:
 * ./main kruskal 0 dataset/ja9847_in.txt dataset/ja9847_out.txt
 * ./main prim 0 dataset/ja9847_in.txt dataset/ja9847_out.txt
 *
 * @param argc quantidade de parâmetros
 * @param argv valores dos parâmetros
 *
 * @return 0 caso execute com sucesso; outro valor caso ocorra algum erro.
 */
int main(int argc, char *argv[]) {
    if (argc != 5) {
        throw std::invalid_argument("Run: <algorithm> <version> <filepath-in> <filepath-out>");
    }

    Algorithm alg = strcasecmp(argv[1], "prim") == 0 ? PRIM :
                    strcasecmp(argv[1], "kruskal") == 0 ? KRUSKAL : NONE;

    int version = std::strtol(argv[2], nullptr, 10);

    execute(alg, version, argv[3], argv[4]);

    return EXIT_SUCCESS;
}
