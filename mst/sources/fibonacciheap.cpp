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

FibonacciHeap::FibonacciHeap(int n, int s){
    build(s);
}

void FibonacciHeap::build(int s) {
    root = NULL;
    no_of_nodes = 0;
    insertion(s);
}

bool FibonacciHeap::empty(){
    if (no_of_nodes == 0){
        return true;
    }
    else{
        return false;
    }
}

void FibonacciHeap::insertion (int val) {
    node* new_node;
    new_node->key = val; 
    new_node->degree = 0;
    new_node->parent = NULL;
    new_node->child = NULL;
    new_node->prev = new_node;
    new_node->next = new_node;

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
}

void FibonacciHeap::Union(node *h1, node *h2){
    node *h;
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
        std::cout << "empty\n";
        return -1;
        //Joga um excessão aqui que é melhor
    }

    int output = root->key;
    node* temp = root;
    node* pntr; 
    pntr = temp; 
    node* x = NULL; 
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

    return output;
}

void FibonacciHeap::consolidate() {  
    int temp1; 
    float temp2 = (log(no_of_nodes)) / (log(2)); 
    int temp3 = temp2; 
    node* arr[temp3]; 
    for (int i = 0; i <= temp3; i++) 
        arr[i] = NULL; 
    node* ptr1 = root; 
    node* ptr2; 
    node* ptr3; 
    node* ptr4 = ptr1; 
    do { 
        ptr4 = ptr4->next; 
        temp1 = ptr1->degree; 
        while (arr[temp1] != NULL) { 
            ptr2 = arr[temp1]; 
            if (ptr1->key > ptr2->key) { 
                ptr3 = ptr1; 
                ptr1 = ptr2; 
                ptr2 = ptr3; 
            } 
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

void FibonacciHeap::fibonnaci_link(node * ptr2, node * ptr1) { 
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

void FibonacciHeap::Cut(node * found, node * temp) { 
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

void FibonacciHeap::Cascase_cut(node* temp) { 
    node* ptr5 = temp->parent; 
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

void FibonacciHeap::Decrease_key(node * found, int val) { 
    if (root == NULL) 
        std::cout << "The Heap is Empty" << std::endl; 
    	
    if (found == NULL) 
        std::cout << "Node not found in the Heap" << std::endl; 
  
    found->key = val; 
  
    node* temp = found->parent; 
    if (temp != NULL && found->key < temp->key) { 
        Cut(found, temp); 
        Cascase_cut(temp); 
    } 
    if (found->key < root->key) 
        root = found; 
}

void FibonacciHeap::Find(node * n,int old_val, int val) { 
    node* found = NULL; 
    node* temp5 = root; 
    temp5->c = 'Y'; 
    node* found_ptr = NULL; 
    if (temp5->key == old_val) { 
        found_ptr = temp5; 
        temp5->c = 'N'; 
        found = found_ptr; 
        Decrease_key(found, val); 
    } 
    if (found_ptr == NULL) { 
        if (temp5->child != NULL){
            Find(temp5->child, old_val, val); 
        }
        if ((temp5->next)->c != 'Y'){ 
            Find(temp5->next, old_val, val);
        } 
    } 
    temp5->c = 'N'; 
    found = found_ptr; 
} 