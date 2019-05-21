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

struct CheckPoint {

    std::chrono::high_resolution_clock::time_point timePoint;
};

class Application {
public:

    void checkPoint(const std::string &task);
};


#endif //MST_APPLICATION_H
