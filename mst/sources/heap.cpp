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

    auto l = left(i);
    auto r = right(i);
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

    struct node* mini = NULL; 
}

void insertion(int val) 
{ 
    struct node* new_node = (struct node*)malloc(sizeof(struct node)); 
    new_node->key = val; 
    new_node->degree = 0; 
    new_node->mark = 'W'; 
    new_node->c = 'N'; 
    new_node->parent = NULL; 
    new_node->child = NULL; 
    new_node->left = new_node; 
    new_node->right = new_node; 
    if (mini != NULL) { 
        (mini->left)->right = new_node; 
        new_node->right = mini; 
        new_node->left = mini->left; 
        mini->left = new_node; 
        if (new_node->key < mini->key) 
            mini = new_node; 
    } 
    else { 
        mini = new_node; 
    } 
    size++; 
} 

// Linking the heap nodes in parent child relationship 
void Fibonnaci_link(struct node* ptr2, struct node* ptr1) 
{ 
    (ptr2->left)->right = ptr2->right; 
    (ptr2->right)->left = ptr2->left; 
    if (ptr1->right == ptr1) 
        mini = ptr1; 
    ptr2->left = ptr2; 
    ptr2->right = ptr2; 
    ptr2->parent = ptr1; 
    if (ptr1->child == NULL) 
        ptr1->child = ptr2; 
    ptr2->right = ptr1->child; 
    ptr2->left = (ptr1->child)->left; 
    ((ptr1->child)->left)->right = ptr2; 
    (ptr1->child)->left = ptr2; 
    if (ptr2->key < (ptr1->child)->key) 
        ptr1->child = ptr2; 
    ptr1->degree++; 
} 

void heapfy() 
{ 
    int temp1; 
    float temp2 = (log(size)) / (log(2)); 
    int temp3 = temp2; 
    struct node* arr[temp3]; 
    for (int i = 0; i <= temp3; i++) 
        arr[i] = NULL; 
    node* ptr1 = mini; 
    node* ptr2; 
    node* ptr3; 
    node* ptr4 = ptr1; 
    do { 
        ptr4 = ptr4->right; 
        temp1 = ptr1->degree; 
        while (arr[temp1] != NULL) { 
            ptr2 = arr[temp1]; 
            if (ptr1->key > ptr2->key) { 
                ptr3 = ptr1; 
                ptr1 = ptr2; 
                ptr2 = ptr3; 
            } 
            if (ptr2 == mini) 
                mini = ptr1; 
            Fibonnaci_link(ptr2, ptr1); 
            if (ptr1->right == ptr1) 
                mini = ptr1; 
            arr[temp1] = NULL; 
            temp1++; 
        } 
        arr[temp1] = ptr1; 
        ptr1 = ptr1->right; 
    } while (ptr1 != mini); 
    mini = NULL; 
    for (int j = 0; j <= temp3; j++) { 
        if (arr[j] != NULL) { 
            arr[j]->left = arr[j]; 
            arr[j]->right = arr[j]; 
            if (mini != NULL) { 
                (mini->left)->right = arr[j]; 
                arr[j]->right = mini; 
                arr[j]->left = mini->left; 
                mini->left = arr[j]; 
                if (arr[j]->key < mini->key) 
                    mini = arr[j]; 
            } 
            else { 
                mini = arr[j]; 
            } 
            if (mini == NULL) 
                mini = arr[j]; 
            else if (arr[j]->key < mini->key) 
                mini = arr[j]; 
        } 
    } 
} 

void Extract_min() 
{ 
    if (mini == NULL) 
        throw std::invalid_argument("Heap is empty"); // TODO: ver uma exceção adequada.
    else { 
        node* temp = mini; 
        node* pntr; 
        pntr = temp; 
        node* x = NULL; 
        if (temp->child != NULL) { 
  
            x = temp->child; 
            do { 
                pntr = x->right; 
                (mini->left)->right = x; 
                x->right = mini; 
                x->left = mini->left; 
                mini->left = x; 
                if (x->key < mini->key) 
                    mini = x; 
                x->parent = NULL; 
                x = pntr; 
            } while (pntr != temp->child); 
        } 
        (temp->left)->right = temp->right; 
        (temp->right)->left = temp->left; 
        mini = temp->right; 
        if (temp == temp->right && temp->child == NULL) 
            mini = NULL; 
        else { 
            mini = temp->right; 
            heapfy(); 
        }
        size--;
    } 
} 