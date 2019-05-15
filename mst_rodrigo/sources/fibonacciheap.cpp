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

#include "fibonacciheap.h"

FibonacciHeap::FibonacciHeap(int n, int s) : nodes(n), position(n){
    build(n,s);
}

void FibonacciHeap::build(int n,int s) {
    root = NULL;
    no_of_nodes = 0;
    insertion(0,s);
    for (int i = 1; i < nodes.size(); i++) {
        insertion(std::numeric_limits<float>::infinity(),i);
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

void FibonacciHeap::insertion (float val,int index) {
    HeapNode* new_node = (struct HeapNode*)malloc(sizeof(struct HeapNode));
    new_node->key = val;
    new_node->degree = 0;
    new_node->parent = NULL;
    new_node->child = NULL;
    new_node->prev = new_node;
    new_node->next = new_node;
    new_node->pos = index;



    if(root !=  NULL){
        new_node->prev = root->prev;
        new_node->next = root;
        (root->prev)->next = new_node;
        root->prev = new_node;
        if(new_node->key < root->key){
            root = new_node;
        }
    }
    else{
        root = new_node;
    }
    no_of_nodes++;
    position[index] = new_node;

}

void FibonacciHeap::Union(HeapNode *h1, HeapNode *h2){
    HeapNode *h;
    root = h1;

    h2->prev = h1->prev;
    h2->next = h1;
    (h1->prev)->next = h2;
    h1->prev = h2;

    if((h1 != NULL) || ((h2 != NULL) && (h2->key < h1->key))){
        root = h2;

    }
}

int FibonacciHeap::extractMin(){
    if(root == NULL){
        throw std::invalid_argument("Heap is empty");
    }

    HeapNode* temp = root;
    HeapNode* pntr; 
    pntr = temp; 
    HeapNode* x = NULL; 
    if (temp->child != NULL) { 
        x = temp->child; 
        do { 
            pntr = x->next; 
            (root->prev)->next = x; 
            x->next = root; 
            x->prev = root->prev; 
            root->prev = x; 
            if (x->key < root->key) 
                root = x; 
            x->parent = NULL; 
            x = pntr; 
        } while (pntr != temp->child); 
    } 
    (temp->prev)->next = temp->next;
    (temp->next)->prev = temp->prev;
    root = temp->next;
    if (temp == temp->next && temp->child == NULL) 
            root = NULL;
    else {
        root = temp->next; 
        consolidate();
    }
    no_of_nodes--; 
    return root->pos;
}

void FibonacciHeap::consolidate() {  
    int temp1; 
    float temp2 = (log(no_of_nodes)) / (log(2)); 
    int temp3 = temp2; 
    HeapNode* arr[temp3]; 
    for (int i = 0; i <= temp3; i++) 
        arr[i] = NULL; 
    HeapNode* ptr1 = root; 
    HeapNode* ptr2; 
    HeapNode* ptr3; 
    HeapNode* ptr4 = ptr1; 
    do { 
        ptr4 = ptr4->next; 
        temp1 = ptr1->degree; 
        while (arr[temp1] != NULL) { 



            /*------ BUG AQUI -----*/
            ptr2 = arr[temp1]; 
            if (ptr1->key > ptr2->key) { 
                ptr3 = ptr1; 
                ptr1 = ptr2; 
                ptr2 = ptr3; 
            } 
            /*------ BUG AQUI -----*/



            if (ptr2 == root) 
                root = ptr1; 
            fibonnaci_link(ptr2, ptr1); 
            if (ptr1->next == ptr1) 
                root = ptr1; 
            arr[temp1] = NULL; 
            temp1++; 
        } 
        arr[temp1] = ptr1; 
        ptr1 = ptr1->next; 
    } while (ptr1 != root); 
    root = NULL; 
    for (int j = 0; j <= temp3; j++) { 
        if (arr[j] != NULL) { 
            arr[j]->prev = arr[j]; 
            arr[j]->next = arr[j]; 
            if (root != NULL) { 
                (root->prev)->next = arr[j]; 
                arr[j]->next = root; 
                arr[j]->prev = root->prev; 
                root->prev = arr[j]; 
                if (arr[j]->key < root->key) 
                    root = arr[j]; 
            } 
            else { 
                root = arr[j]; 
            } 
            if (root == NULL) 
                root = arr[j]; 
            else if (arr[j]->key < root->key) 
                root = arr[j]; 
        } 
    } 
}

void FibonacciHeap::fibonnaci_link(HeapNode * ptr2, HeapNode * ptr1) { 

    (ptr2->prev)->next = ptr2->next; 
    (ptr2->next)->prev = ptr2->prev; 
    if (ptr1->next == ptr1) 
        root = ptr1; 
    ptr2->prev = ptr2; 
    ptr2->next = ptr2; 
    ptr2->parent = ptr1; 
    if (ptr1->child == NULL) 
        ptr1->child = ptr2; 
    ptr2->next = ptr1->child; 
    ptr2->prev = (ptr1->child)->prev; 
    ((ptr1->child)->prev)->next = ptr2; 
    (ptr1->child)->prev = ptr2; 
    if (ptr2->key < (ptr1->child)->key) 
        ptr1->child = ptr2; 
    ptr1->degree++;
}

void FibonacciHeap::Cut(HeapNode * found, HeapNode * temp) { 
    if (found == found->next) 
        temp->child = NULL; 
  
    (found->prev)->next = found->next; 
    (found->next)->prev = found->prev; 
    if (found == temp->child) 
        temp->child = found->next; 
  
    temp->degree = temp->degree - 1; 
    found->next = found; 
    found->prev = found; 
    (root->prev)->next = found; 
    found->next = root; 
    found->prev = root->prev; 
    root->prev = found; 
    found->parent = NULL; 
    found->mark = 'B'; 
}

void FibonacciHeap::Cascase_cut(HeapNode* temp) { 
    HeapNode* ptr5 = temp->parent; 
    if (ptr5 != NULL) { 
        if (temp->mark == 'W') { 
            temp->mark = 'B'; 
        } 
        else { 
            Cut(temp, ptr5); 
            Cascase_cut(ptr5); 
        } 
    } 
}

void FibonacciHeap::decreaseKey(unsigned long index, float val) {

    HeapNode * found = position[index];

    if (root == NULL) 
        std::cout << "The Heap is Empty" << std::endl; 
        
    if (found == NULL) 
        std::cout << "Node not found in the Heap" << std::endl; 
  
    found->key = val; 


    HeapNode* temp = found->parent; 
    if (temp != NULL && found->key < temp->key) { 
        Cut(found, temp); 
        Cascase_cut(temp); 
    } 
    if (found->key < root->key) 
        root = found; 
}

void FibonacciHeap::print() 
{ 
    HeapNode* ptr = root; 
    if (ptr == NULL) 
        std::cout << "The Heap is Empty" << std::endl; 
  
    else { 
        std::cout << "The root nodes of Heap are: " << std::endl; 
        do { 
            std::cout << ptr->key; 
            ptr = ptr->next; 
            if (ptr != root) { 
                std::cout << "-->"; 
            } 
        } while (ptr != root && ptr->next != NULL); 
        std::cout << std::endl 
             << "The heap has " << no_of_nodes << " nodes" << std::endl; 
    } 
} 