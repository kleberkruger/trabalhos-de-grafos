//
// Created by Kleber Kruger on 2019-06-04.
//

#ifndef FLUXOS_APPLICATION_H
#define FLUXOS_APPLICATION_H


#include <chrono>
#include <map>
#include <string>
#include <vector>
#include <fcntl.h>
#include <unistd.h>
#include <sys/filio.h>
#include <sys/ioctl.h>

#ifdef __OSX_AVAILABLE
typedef std::chrono::steady_clock OS_CLOCK;
#else
typedef std::chrono::system_clock OS_CLOCK;
#endif

struct Task {

    explicit Task(std::string description) : description(std::move(description)),
                                             timePoint(OS_CLOCK::now()) {}

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

    /**
     * Executa o algoritmo de acordo com os dados de entrada gerando uma saída.
     *
     * @param inputFilePath
     * @param outputFilePath
     * @param algorithm
     * @param version
     */
    void start(const std::string &inputFilePath, const std::string &outputFilePath,
               const std::string &algorithm, unsigned short version = 0) {

        AIn in;
        AOut out;
        std::vector<Task> tasks;

        Algorithm alg = selectAlgorithm(algorithm, version);

        tasks.emplace_back("read input file");
        std::string text = readInputFile(inputFilePath);

        tasks.emplace_back("create input info");
        createInputInfo(text, in);

        tasks.emplace_back("execute algorithm " + alg.name);
        alg.execute(in, out);

        tasks.emplace_back("print output");
        printOutput(outputFilePath, in, out);

        tasks.emplace_back("finished");
        printTasks(tasks);
    }

protected:

    virtual std::map<std::string, std::vector<Algorithm<AIn, AOut>>> algorithmsMap() = 0;

    virtual void createInputInfo(const std::string &text, AIn &input) = 0;

    virtual void printOutput(const std::string &filePath, const AIn &input, const AOut &output) = 0;

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
        printf("================================================================================\n");
        for (unsigned int i = 0; i < tasks.size() - 1; i++) {
            printf(" Time to %s: %llu ms\n", tasks[i].description.data(),
                   std::chrono::duration_cast<std::chrono::milliseconds>(
                           tasks[i + 1].timePoint - tasks[i].timePoint).count());
        }
        printf("--------------------------------------------------------------------------------\n"
               " Total time: %llu ms\n"
               "================================================================================\n",
               std::chrono::duration_cast<std::chrono::milliseconds>(
                       tasks[tasks.size() - 1].timePoint - tasks[0].timePoint).count());
    }

    template<typename R, typename... Args>
    static inline R run(const std::string &task, R (*function)(Args...), Args... args) {
        return function(args...);
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

#endif //FLUXOS_APPLICATION_H
