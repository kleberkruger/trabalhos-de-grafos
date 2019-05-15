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

class FibonacciHeap : public Heap {
public:
	struct node { 
	    node* parent; // Parent pointer 
	    node* child; // Child pointer 
	    node* prev; // Pointer to the node on the left 
	    node* next; // Pointer to the node on the right 
	    int key; // Value of the node 
	    int degree; // Degree of the node 
	    char mark; // Black or white mark of the node 
	    char c; // Flag for assisting in the Find node function 
	};
	

    FibonacciHeap(int n, int s);

    int extractMin();

    void decreaseKey(node * found, float value);

	void insertion(int val);

	bool empty();

protected:
	void Union(node * h1, node * h2);
	void consolidate();
	void fibonnaci_link(node * ptr1, node * ptr2);
	void Cut(node* found, node * temp);
	void Cascase_cut(node * temp);
	void Decrease_key(node * found, int val);
	void Find(node * n, int old_val, int val);
    

private:
	void build(int s);

	node * root;
	int no_of_nodes;

};

#endif //MST_FIBONACCIHEAP_H