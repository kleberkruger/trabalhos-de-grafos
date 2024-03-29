/**
 * Algoritmos em Grafos (MO412)
 *
 * @author: Kleber Kruger <kleberkruger@gmail.com>
 * @author: Felipe Barbosa <felipebarbosa@uft.edu.com>
 * @author: Rodrigo Kanehisa <rodrigokanehisa@gmail.com>
 */

#include "binaryheap.h"

BinaryHeap::BinaryHeap(int n, int s) : nodes(n), position(n), size(0) {
    build(n, s);
}

void BinaryHeap::build(int n, int s) {
    for (auto i = 0; i < n; i++) {
        nodes[i].vertex = i;
        nodes[i].value = std::numeric_limits<double>::infinity();

        position[i] = i;
    }
    nodes[s].value = 0;
    size = nodes.size();

    for (int i = size / 2 - 1; i >= 0; i--) heapify(i);
}

int BinaryHeap::extractMin() {
    if (size < 1) {
        throw std::invalid_argument("Heap is empty"); // TODO: ver uma exceção adequada.
    }

    int min = nodes[0].vertex;
//    std::cout << "vou extrair o " << min << std::endl;
    position[nodes[size - 1].vertex] = 0;
    nodes[0] = nodes[--size];

//    std::cout << "vou mesmo extrair o " << min << std::endl;

    if (size > 0) heapify(0);

//    std::cout << "heapfado!" << min << std::endl;

    return min;
}

void BinaryHeap::decreaseKey(unsigned long vertex, double value) {
    auto index = position[vertex];
    if (nodes[index].value > value) {
        //std::cout << nodes[index].value << " " << value << std::endl;
        //throw std::invalid_argument("Decrease error!");

        nodes[index].value = value;

        while (index > 0 && nodes[index].value < nodes[parent(index)].value) {
            swap(index, parent(index));
            index = parent(index);
        }
    }
}

void BinaryHeap::heapify(unsigned long i) {

    auto l = left(i);
    auto r = right(i);
    auto smallest = i;

    if (l <= size - 1 && nodes[l].value < nodes[smallest].value) smallest = l;
    if (r <= size - 1 && nodes[r].value < nodes[smallest].value) smallest = r;

    if (i != smallest) {
        swap(i, smallest);
        heapify(smallest);
    }
}

void BinaryHeap::swap(unsigned long i, unsigned long j) {
//    std::cout << "swap(" << i << "," << j << ")" << std::endl;
//    std::cout << "swap de (" << nodes[i].vertex << "," << nodes[j].vertex << ")" << std::endl;

    position[nodes[i].vertex] = j;
    position[nodes[j].vertex] = i;

    auto aux = nodes[i];
    nodes[i] = nodes[j];
    nodes[j] = aux;

//    std::cout << "[ ";
//    for (int i = 0; i < size; i++) std::cout << "v" << i << "=" << position[i] << " ";
//    std::cout << "]" << std::endl << std::endl;
}

void BinaryHeap::print() {
    for (unsigned int i = 0; i < size; i++)
        std::cout << i << "=[(" << nodes[i].value << ") v" << nodes[i].vertex << "=" << position[nodes[i].vertex]
                  << "] ";
    std::cout << std::endl;
}
