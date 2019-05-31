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
#include <utility>
#include <vector>
#include <fcntl.h>
#include <unistd.h>
#include <sys/filio.h>
#include <sys/ioctl.h>


#ifdef __OSX_AVAILABLE
typedef std::chrono::steady_clock OS_CLOCK;
#else
std::chrono::system_clock CLOCK;
#endif

struct Task {

    explicit Task(std::string description) : description(std::move(description)), timePoint(OS_CLOCK::now()) {}

    std::string description;
    std::chrono::high_resolution_clock::time_point timePoint;
};

template<typename AIn, typename AOut>
struct Algorithm {

    const std::string name;

    void (*execute)(const AIn &in, AOut &out);

    const std::string alias;

    Algorithm(std::string name, void (*execute)(const AIn &, AOut &), std::string alias = "")
            : name(std::move(name)), execute(execute), alias(std::move(alias)) {}
};

template<typename AIn, typename AOut>
class Application {
public:

    void start(const std::string &algorithm, unsigned short version, const std::string &inputFilePath,
               const std::string &outputFilePath) {

        AIn in;
        AOut out;
        std::vector<Task> tasks;

        tasks.emplace_back("select algorithm");
        Algorithm alg = selectAlgorithm(algorithm, version);

        tasks.emplace_back("read input file");
        std::string text = readInputFile(inputFilePath);

        tasks.emplace_back("create input info");
        createInputInfo(text, in);

        tasks.emplace_back("execute algorithm");
        alg.execute(in, out);

        tasks.emplace_back("print output");
        printOutput(in, out);

        printTasks(tasks);
    }

protected:

    virtual std::map<std::string, std::vector<Algorithm<AIn, AOut>>> algorithmsMap() = 0;

//    virtual Graph createGraph(const std::string &input, const AIn *more) = 0;

    virtual void createInputInfo(const std::string &text, AIn &input) = 0;

    virtual void printOutput(const AIn &input, const AOut &output) = 0;

private:

    static const int BUFFER_SIZE = 65536;

    static std::string readInputFile(const std::string &filePath) {
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

    static void printTasks(std::vector<Task> tasks) {
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

    Algorithm<AIn, AOut> selectAlgorithm(const std::string &algorithm, unsigned short version) {
        auto map = algorithmsMap();
        auto it = map.find(algorithm);

        if (it == map.end()) {
            throw std::invalid_argument("Incorrect algorithm name");
        } else if (version >= (*it).second.size()) {
            throw std::invalid_argument("Incorrect version to " + algorithm);
        }

        return algorithmsMap()[algorithm][version];
    }

};


#endif //CAMINHOS_APPLICATION_H
