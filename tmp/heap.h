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

#include "heap.h"

ArrayHeap::ArrayHeap(int n, int s) : nodes(n), position(n) {
    build(n, s);
}

void ArrayHeap::build(int n, int s) {
    for (int i = 0; i < nodes.size(); i++) {
        nodes[i].vertex = i;
        nodes[i].value = std::numeric_limits<float>::infinity();
    }
    nodes[s].value = 0;
    size = nodes.size();
}

int ArrayHeap::extractMin() {
    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (nodes[i].value < nodes[minIndex].value) {
            minIndex = i;
        }
    }

    int min = nodes[minIndex].vertex;
    swap(minIndex, --size);

    return min;
}

void ArrayHeap::decreaseKey(unsigned long index, float value) {
    nodes[find(index)].value = value;
}

bool ArrayHeap::empty() {
    return size == 0;
}

int ArrayHeap::find(int index) {
    return position[index];
}

void ArrayHeap::swap(int e1, int e2) {
    auto aux = nodes[e1];
    nodes[e1] = nodes[e2];
    nodes[e2] = aux;
}

BinaryHeap::BinaryHeap(int n, int s) : nodes(n) {
    build(n, s);
}

void BinaryHeap::build(int n, int s) {
    for (int i = 0; i < nodes.size(); i++) {
        nodes[i].vertex = i;
        nodes[i].value = std::numeric_limits<float>::infinity();
    }
    nodes[s].value = 0;
    size = nodes.size();
}

int BinaryHeap::extractMin() {
    if (size < 1) {
        throw std::invalid_argument("Heap is empty"); // TODO: ver uma exceção adequada.
    }

    int min = nodes[0].vertex;
    nodes[0] = nodes[--size];

    heapify(0);

    return min;
}

void BinaryHeap::decreaseKey(unsigned long index, float value) {
    std::cout << "v" << index << " => " << nodes[index].value << " => " << value << std::endl;
    if (nodes[index].value < value) {
        throw std::invalid_argument("Decrease Error!");
    }


    nodes[index].value = value;

    while (index > 0 && nodes[index].value < nodes[parent(index)].value) {
        swap(index, parent(index));
        index = parent(index);
    }
}

void BinaryHeap::heapify(unsigned long i) {

    auto l = prev(i);
    auto r = next(i);
    auto smallest = i;

    if (l <= size - 1 && nodes[l].value < nodes[smallest].value) smallest = l;
    if (r <= size - 1 && nodes[r].value < nodes[smallest].value) smallest = r;

    if (i != smallest) {
        swap(i, smallest);
        heapify(smallest);
    }
}

/**Tem que adaptar isso pro nosso código**/
//Olha o fibheap.cpp, tá na pasta tmp
//Eu até entendi como tá funcionando, a questão é só o extract min que retorna mais de um valor as vezes
//Tem que fazer funcionar com a classe
//Eu não tô lembrando de C++


FibHeap::FibHeap(int n, int s){
    build(n, s);
}

void FibHeap::build(int n, int s) {
    root = NULL;
    no_of_nodes = 0;
    insertion(s);
}

bool empty(){
    if (no_of_nodes == 0){
        return true;
    }
    else{
        return false;
    }
}

void insertion(int val) {
    struct node* new_node;
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

void union(struct node* h1, struct node* h2){
    struct node* h
    root = h1;

    h2->prev = h1->prev;
    h2->next = h1;
    (h1->prev)->next = h2;
    h1->prev = h2;

    if((h1 != NULL) || ((h2 != NULL) && (h2.key < h1.key)){
        root = h2;
    }
}

int extractMin(){

    if(root == NULL){
        printf("empty\n", );
        //excepion
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
        heapify(); 
    } 
    no_of_nodes--; 

    return output;
}

void heapify() 
{ 
    int temp1; 
    float temp2 = (log(no_of_nodes)) / (log(2)); 
    int temp3 = temp2; 
    struct node* arr[temp3]; 
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
            Fibonnaci_link(ptr2, ptr1); 
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