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
	    int degree; // Degree of the HeapNode 
	    int pos; // Position of the HeapNode in the position array
	    char mark; // Black or white mark of the HeapNode 
	    char c; // Flag for assisting in the Find HeapNode function 
	};
	int debug = 0;

    FibonacciHeap(int n, int s);

    int extractMin() override;

    void decreaseKey(unsigned long index, double val) override;

    bool empty() override;

	void insertion(double val,int index);

	void print();
protected:
	void Union(HeapNode * h1, HeapNode * h2);
	void consolidate();
	void fibonnaci_link(HeapNode * ptr2, HeapNode * ptr1);
	void Cut(HeapNode* found, HeapNode * temp);
	void Cascase_cut(HeapNode * temp);
	void Decrease_key(HeapNode * found, int val);
	void Find(HeapNode * n, int old_val, int val);
    

private:
	void build(int n,int s);

	HeapNode * root;
	int no_of_nodes;
    std::vector<HeapNode> nodes;
    std::vector<HeapNode>::size_type size;
    std::vector<HeapNode *> position;

};

#endif //MST_FIBONACCIHEAP_H