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

#ifndef MST_BINARYHEAP_H
#define MST_BINARYHEAP_H

#include <vector>
#include "heap.h"

class BinaryHeap : public Heap {
public:

    struct HeapNode {
        int vertex;
        double value;
    };

    BinaryHeap(int n, int s);

    int extractMin() override;

    void decreaseKey(std::vector<HeapNode>::size_type index, double value) override;

    void print();

    inline bool empty() override { return size == 0; }

    inline std::vector<HeapNode>::size_type parent(std::vector<HeapNode>::size_type index) {
        return (unsigned long) (index - 1) / 2;
    }

    inline std::vector<HeapNode>::size_type left(std::vector<HeapNode>::size_type index) {
        return (index * 2) + 1;
    }

    inline std::vector<HeapNode>::size_type right(std::vector<HeapNode>::size_type index) {
        return (index * 2) + 2;
    }

protected:

    void heapify(std::vector<HeapNode>::size_type index);

private:

    void build(int n, int s);

    void swap(std::vector<HeapNode>::size_type i, std::vector<HeapNode>::size_type j);

    std::vector<HeapNode> nodes;
    std::vector<std::vector<HeapNode>::size_type> position;
    std::vector<HeapNode>::size_type size;
};

#endif //MST_BINARYHEAP_H
