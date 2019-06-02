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

struct node {
private:

    node *prev;
    node *next;
    node *child;
    node *parent;
    GraphNode value;
    int degree;
    bool marked;

public:

    friend class FibonacciHeap;

    node *getPrev() { return prev; }

    node *getNext() { return next; }

    node *getChild() { return child; }

    node *getParent() { return parent; }

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

    node *insert(GraphNode value);

    void merge(FibonacciHeap &other);

    GraphNode getMinimum();

    void decreaseKey(node *n, GraphNode value);

    node *find(GraphNode value);

    int extractMin() override;

    void decreaseKey(unsigned long vertex, double value) override;

    bool empty() override;

private:

    node *heap;

    void build(int n, int s);

    node *_empty();

    node *_singleton(GraphNode value);

    node *_merge(node *a, node *b);

    void _deleteAll(node *n);

    void _addChild(node *parent, node *child) ;

    void _unMarkAndUnParentAll(node *n) ;

    node*_removeMinimum(node *n);
    node *_cut(node *heap, node *n) ;

    node *_decreaseKey(node *heap, node *n, GraphNode value) ;

    node *_find(node *heap, GraphNode value);
};


#endif //CAMINHOS_FIBONACCIHEAP_H
