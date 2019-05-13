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

#include "heap.h"

ArrayHeap::ArrayHeap(int n, int s) : nodes(n), position(n) {
    build(n, s);
}

void ArrayHeap::build(int n, int s) {
    for (int i = 0; i < nodes.size(); i++) {
        nodes[i].vertex = i;
        nodes[i].value = std::numeric_limits<float>::infinity();
    }
    nodes[s].value = 0;
    size = nodes.size();
}

int ArrayHeap::extractMin() {
    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (nodes[i].value < nodes[minIndex].value) {
            minIndex = i;
        }
    }

    int min = nodes[minIndex].vertex;
    swap(minIndex, --size);

    return min;
}

void ArrayHeap::decreaseKey(unsigned long index, float value) {
    nodes[find(index)].value = value;
}

bool ArrayHeap::empty() {
    return size == 0;
}

int ArrayHeap::find(int index) {
    return position[index];
}

void ArrayHeap::swap(int e1, int e2) {
    auto aux = nodes[e1];
    nodes[e1] = nodes[e2];
    nodes[e2] = aux;
}

BinaryHeap::BinaryHeap(int n, int s) : nodes(n) {
    build(n, s);
}

void BinaryHeap::build(int n, int s) {
    for (int i = 0; i < nodes.size(); i++) {
        nodes[i].vertex = i;
        nodes[i].value = std::numeric_limits<float>::infinity();
    }
    nodes[s].value = 0;
    size = nodes.size();
}

int BinaryHeap::extractMin() {
    if (size < 1) {
        throw std::invalid_argument("Heap is empty"); // TODO: ver uma exceção adequada.
    }

    int min = nodes[0].vertex;
    nodes[0] = nodes[--size];

    heapify(0);

    return min;
}

void BinaryHeap::decreaseKey(unsigned long index, float value) {
    std::cout << "v" << index << " => " << nodes[index].value << " => " << value << std::endl;
    if (nodes[index].value < value) {
        throw std::invalid_argument("Decrease Error!");
    }


    nodes[index].value = value;

    while (index > 0 && nodes[index].value < nodes[parent(index)].value) {
        swap(index, parent(index));
        index = parent(index);
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
