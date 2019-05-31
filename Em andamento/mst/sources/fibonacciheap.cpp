/**
 * Algoritmos em Grafos (MO412)
 *
 * Primeiro Trabalho Prático
 * - MST - Minimum Spanning Tree
 *
 * @authors:
 * - Kleber Kruger <kleberkruger@gmail->com>,
 * - Felipe Barbosa <felipebarbosa@uft->edu->com>,
 * - Rodrigo Kanehisa <rodrigokanehisa@gmail->com>
 */

#include "fibonacciheap.h"

FibonacciHeap::FibonacciHeap(int n, int s) : nodes(n), position(n){
    build(n,s);
}

//FibonacciHeap::~FibonacciHeap(void){
//    for(unsigned int i = 0; i < position.size(); i++){
//        free(position[i]);
//    }
//    for(unsigned int i = 0; i < A.size(); i++){
//        free(A[i]);
//    }
//    free(min);
//}

void FibonacciHeap::build(int n,int s) {
    min = NULL;
    no_of_nodes = 0;
    insertion(0,s);
    for (int i = 1; i < nodes->size(); i++) {
        insertion(std::numeric_limits<double>::infinity(),i);
    }
    A->resize(n)
    for(unsigned int i =0; i < A->size(); i++){
        A[i] = NULL;
    }
}



bool FibonacciHeap::empty(){
    if (no_of_nodes == 0){
        return true;
    }
    else{
        return false;
    }
}

void FibonacciHeap::insertion (double val,int pos) {
    HeapNode* new_node = (struct HeapNode*)malloc(sizeof(struct HeapNode));
    new_node->key = val;
    new_node->degree = 0;
    new_node->parent = NULL;
    new_node->child = NULL;
    new_node->prev = new_node;
    new_node->next = new_node;
    new_node->pos = pos;

    insert_on_root(new_node);

    no_of_nodes++;
    position[index] = new_node;

}

void FibonacciHeap::insert_on_root(HeapNode * x);{
    HeapNode * z = min;
    if(z != NULL){
        z = self->min
            x->prev = z
            x->next = z->next
            z->next->prev = x
            z->next = x
            if(z->key > x->key):
                self->min = x
    }
    else{
        x->prev = x
        x->next = x
        min = x;    
    }
}

int FibonacciHeap::extractMin(){

}

void FibonacciHeap::consolidate() {  
}

void FibonacciHeap::fibonnaci_link(HeapNode * ptr2, HeapNode * ptr1) { 
}

void FibonacciHeap::Cut(HeapNode * found, HeapNode * temp) { 
}

void FibonacciHeap::Cascase_cut(HeapNode* temp) { 
}

void FibonacciHeap::decreaseKey(unsigned long index, double val) {
}