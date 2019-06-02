//
// Created by Kleber Kruger on 2019-06-02.
//

#ifndef CAMINHOS_FIBONACCIHEAP_H
#define CAMINHOS_FIBONACCIHEAP_H


#include "heap.h"

struct GraphNode {

    int vertex;
    double value;

    GraphNode(int vertex = -1, double value = std::numeric_limits<double>::infinity())
            : vertex(vertex), value(value) {}

    bool operator<(const GraphNode &other) const { return value < other.value; }

    bool operator>(const GraphNode &other) const { return value > other.value; }

    bool operator<=(const GraphNode &other) const { return value <= other.value; }

    bool operator>=(const GraphNode &other) const { return value >= other.value; }

    bool operator==(const GraphNode &other) const { return vertex == other.vertex; }

    bool operator!=(const GraphNode &other) const { return vertex != other.vertex; }
};

struct FibonacciNode {
private:

    FibonacciNode *prev;
    FibonacciNode *next;
    FibonacciNode *child;
    FibonacciNode *parent;
    GraphNode value;
    int degree;
    bool marked;

public:

    friend class FibonacciHeap;

    FibonacciNode *getPrev() { return prev; }

    FibonacciNode *getNext() { return next; }

    FibonacciNode *getChild() { return child; }

    FibonacciNode *getParent() { return parent; }

    GraphNode getValue() { return value; }

    bool isMarked() { return marked; }

    bool hasChildren() { return child; }

    bool hasParent() { return parent; }
};

class FibonacciHeap : Heap {
public:

    FibonacciHeap();

    FibonacciHeap(int n, int s);

    virtual ~FibonacciHeap();

    int extractMin() override;

    void decreaseKey(unsigned long vertex, double value) override;

    bool empty() override;

private:

    FibonacciNode *root;

    void build(int n, int s);

    FibonacciNode *insert(GraphNode value);

    FibonacciNode *_singleton(GraphNode value);

    FibonacciNode *_merge(FibonacciNode *a, FibonacciNode *b);

    void _deleteAll(FibonacciNode *n);

    void _addChild(FibonacciNode *parent, FibonacciNode *child);

    void _unMarkAndUnParentAll(FibonacciNode *n);

    FibonacciNode *_removeMinimum(FibonacciNode *n);

    FibonacciNode *_cut(FibonacciNode *heap, FibonacciNode *n);

    FibonacciNode *_decreaseKey(FibonacciNode *heap, FibonacciNode *n, GraphNode value);

    FibonacciNode *find(GraphNode value);

    FibonacciNode *find(FibonacciNode *heap, GraphNode value);
};


#endif //CAMINHOS_FIBONACCIHEAP_H
