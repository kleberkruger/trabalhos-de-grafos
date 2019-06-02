/**
 * Algoritmos em Grafos (MO412)
 *
 * @author: Kleber Kruger <kleberkruger@gmail.com>
 * @author: Felipe Barbosa <felipebarbosa@uft.edu.com>
 * @author: Rodrigo Kanehisa <rodrigokanehisa@gmail.com>
 */

#include "arrayheap.h"

ArrayHeap::ArrayHeap(int n, int s) : nodes(n), position(n) {
    build(n, s);
}

void ArrayHeap::build(int n, int s) {
    for (int i = 0; i < nodes.size(); i++) {
        nodes[i].vertex = i;
        nodes[i].value = std::numeric_limits<double>::infinity();

        position[i] = i;
    }
    nodes[s].value = 0;
    size = nodes.size();
}

int ArrayHeap::extractMin() {
    if (size < 1) {
        throw std::invalid_argument("Heap is empty"); // TODO: ver uma exceção adequada.
    }

    int minIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (nodes[i].value < nodes[minIndex].value) {
            minIndex = i;
        }
    }

    int min = nodes[minIndex].vertex;
    swap(minIndex, --size);

    return min;
}

void ArrayHeap::decreaseKey(unsigned long index, double value) {
    nodes[position[index]].value = value;
}

bool ArrayHeap::empty() {
    return size == 0;
}

void ArrayHeap::print() {
    for (int i = 0; i < size; i++) std::cout << "[" << nodes[i].value << "]:" << nodes[i].vertex << " ";
    std::cout << std::endl;
}

void ArrayHeap::swap(unsigned long i, unsigned long j) {
//    auto aux = nodes[i];
//    nodes[i] = nodes[j];
//    nodes[j] = aux;
//
//    position[i] = j;
//    position[j] = i;

    position[nodes[i].vertex] = j;
    position[nodes[j].vertex] = i;

    auto aux = nodes[i];
    nodes[i] = nodes[j];
    nodes[j] = aux;
}
