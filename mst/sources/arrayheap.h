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

#ifndef MST_ARRAYHEAP_H
#define MST_ARRAYHEAP_H

#include <vector>
#include "heap.h"

class ArrayHeap : public Heap {

    struct HeapNode {
        int vertex;
        float value;
    };

public:

    ArrayHeap(int n, int s);

    int extractMin() override;

    void decreaseKey(unsigned long index, float value) override;

    bool empty() override;

    void print();

protected:

private:

    void build(int n, int s);

    void swap(std::vector<HeapNode>::size_type i, std::vector<HeapNode>::size_type j);

    std::vector<HeapNode> nodes;
    std::vector<HeapNode>::size_type size;
    std::vector<std::vector<HeapNode>::size_type> position;
};

#endif //MST_ARRAYHEAP_H
