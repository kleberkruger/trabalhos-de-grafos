/**
 * Algoritmos em Grafos (MO412)
 *
 * @author: Kleber Kruger <kleberkruger@gmail.com>
 * @author: Felipe Barbosa <felipebarbosa@uft.edu.com>
 * @author: Rodrigo Kanehisa <rodrigokanehisa@gmail.com>
 */

#include "application.h"

Task::Task(std::string description) : description(std::move(description)),
#ifdef __OSX_AVAILABLE
                                      timePoint(std::chrono::steady_clock::now()) {}

#else
timePoint(std::chrono::system_clock::now()) {}
#endif


//template<typename R>
//Algorithm Application<R>::selectAlgorithm(const std::string &algorithm, unsigned short version) {
Algorithm Application::selectAlgorithm(const std::string &algorithm, unsigned short version) {
    auto map = algorithmsMap();
    auto it = map.find(algorithm);

    if (it == map.end()) {
        throw std::invalid_argument("Incorrect algorithm name");
    } else if (version >= (*it).second.size()) {
        throw std::invalid_argument("Incorrect version to " + algorithm);
    }

    return algorithmsMap()[algorithm][version];
}

//template<typename R>
//std::string Application<R>::readInputFile(const std::string &filePath) {
std::string Application::readInputFile(const std::string &filePath) {
    char buffer[BUFFER_SIZE];
    int fd, returned;

    if ((fd = open(filePath.data(), O_RDONLY)) == -1) {
        throw std::invalid_argument("Incorrect input file path: \"" + filePath + "\"");
    }

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

//template<typename R>
//void Application<R>::printTasks(std::vector<Task> tasks) {
void Application::printTasks(std::vector<Task> tasks) {
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

//template<typename R>
//void Application<R>::start(const std::string &algorithm, int version, const std::string &inputFilePath,
//                        const std::string &outputFilePath) {
void Application::start(const std::string &algorithm, int version, const std::string &inputFilePath,
                           const std::string &outputFilePath) {

    std::vector<Task> tasks;

    tasks.emplace_back("select algorithm");
    Algorithm alg = selectAlgorithm(algorithm, version);

    tasks.emplace_back("read input file");
    std::string input = readInputFile(inputFilePath);

    tasks.emplace_back("create the graph");
    Graph graph = createGraph(input);

    tasks.emplace_back("execute algorithm");
    AlgorithmOutput output = alg.execute(graph, 0);

    tasks.emplace_back("print output");
    printOutput(output);

    printTasks(tasks);
}
