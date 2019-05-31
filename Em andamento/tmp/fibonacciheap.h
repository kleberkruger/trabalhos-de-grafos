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

#ifndef MST_FIBONACCIHEAP_H
#define MST_FIBONACCIHEAP_H

#include <vector>
#include <limits>
#include "heap.h"
#include <math.h>
#include <functional>

class FibonacciHeap : public Heap {
public:
	struct HeapNode { 
	    HeapNode* parent; // Parent pointer 
	    HeapNode* child; // Child pointer 
	    HeapNode* prev; // Pointer to the HeapNode on the left 
	    HeapNode* next; // Pointer to the HeapNode on the right 
        double key; // Value of the HeapNode
	    int pos; // Position of the HeapNode in the position array
	    int degree; // Degree of the HeapNode
	    bool mark; // Black or white mark of the HeapNode
	};

    FibonacciHeap(int n, int s);
    ~FibonacciHeap();

    int extractMin() override;

    void decreaseKey(unsigned long index, double val) override;

    bool empty() override;

	void insertion(double val,int index);

	void print();

protected:
	void consolidate();
	void fibonnaci_link(HeapNode * y, HeapNode * x);
	void Cut(HeapNode* found, HeapNode * temp);
	void Cascase_cut(HeapNode * temp);
	void Decrease_key(HeapNode * found, int val);
    

private:
	void build(int n,int s);
	void insert_on_root(HeapNode * x);
	void remove_from_root(HeapNode * x);
	void insert_on_child(HeapNode * y, HeapNode * x);
	void remove_from_child(HeapNode * x, HeapNode * y);

	HeapNode * min;
	int total_nodes;
    std::vector<HeapNode> nodes;
    std::vector<HeapNode>::size_type size;
    std::vector<HeapNode *> position;
    std::vector<HeapNode *> A;

};

#endif //MST_FIBONACCIHEAP_H