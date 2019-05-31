/**
 * Algoritmos em Grafos (MO412)
 *
 * @author: Kleber Kruger <kleberkruger@gmail.com>
 * @author: Felipe Barbosa <felipebarbosa@uft.edu.com>
 * @author: Rodrigo Kanehisa <rodrigokanehisa@gmail.com>
 */

#include "pathsapp.h"

void dijkstra(const InputInfo &in, OutputInfo &out) {
    std::cout << "executando o Dijkstra!" << std::endl;
}

std::map<std::string, std::vector<Algorithm<InputInfo, OutputInfo>>> PathsApp::algorithmsMap() {
    std::map<std::string, std::vector<Algorithm<InputInfo, OutputInfo>>> algorithms;

    algorithms["dijkstra"].push_back(Algorithm<InputInfo, OutputInfo>("dijkstra", dijkstra));

    return algorithms;
}

void PathsApp::createInputInfo(const std::string &text, InputInfo &input) {

}

void PathsApp::printOutput(OutputInfo output) {

}
