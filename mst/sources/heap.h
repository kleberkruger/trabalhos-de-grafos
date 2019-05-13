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

#ifndef MST_HEAP_H
#define MST_HEAP_H


#include <vector>
#include <limits>
#include <iostream>
#include <stdexcept>
#include <algorithm>

class Heap {

    virtual int extractMin() = 0;

    virtual void decreaseKey(unsigned long index, float value) = 0;

    virtual bool empty() = 0;

protected:

//    virtual void build(int n, int s) = 0;
};

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

    int find(int index);

protected:

    void swap(int e1, int e2);

private:

    void build(int n, int s);

    std::vector<HeapNode> nodes;
    std::vector<HeapNode>::size_type size;
    std::vector<std::vector<HeapNode>::size_type> position;
};

class BinaryHeap : public Heap {
public:

    struct HeapNode {
        int vertex;
        float value;
    };

    BinaryHeap(int n, int s);

    int extractMin();

    void decreaseKey(std::vector<HeapNode>::size_type index, float value);

    inline bool empty() { return size == 0; }

    inline std::vector<HeapNode>::size_type parent(std::vector<HeapNode>::size_type index) {
        return (index - 1) / 2;
    }

    inline std::vector<HeapNode>::size_type left(std::vector<HeapNode>::size_type index) {
        return index * 2 + 1;
    }

    inline std::vector<HeapNode>::size_type right(std::vector<HeapNode>::size_type index) {
        return index * 2 + 2;
    }

protected:

    void heapify(std::vector<HeapNode>::size_type index);

    inline void swap(std::vector<HeapNode>::size_type i, std::vector<HeapNode>::size_type j) {
        auto aux = nodes[i];
        nodes[i] = nodes[j];
        nodes[j] = aux;
    }

private:

    void build(int n, int s);

    std::vector<HeapNode> nodes;
    std::vector<HeapNode>::size_type size;
};


#endif //MST_HEAP_H
