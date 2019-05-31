/**
 * Algoritmos em Grafos (MO412)
 *
 * @author: Kleber Kruger <kleberkruger@gmail.com>
 * @author: Felipe Barbosa <felipebarbosa@uft.edu.com>
 * @author: Rodrigo Kanehisa <rodrigokanehisa@gmail.com>
 */

#ifndef CAMINHOS_PATHSAPP_H
#define CAMINHOS_PATHSAPP_H


#include "application.h"


struct InputInfo {

};

struct OutputInfo {

};


class PathsApp : public Application<InputInfo, OutputInfo> {
protected:

    std::map<std::string, std::vector<Algorithm<InputInfo, OutputInfo>>> algorithmsMap() override;

    void createInputInfo(const std::string &text, InputInfo &input) override;

    void printOutput(OutputInfo output) override;
};


#endif //CAMINHOS_PATHSAPP_H
