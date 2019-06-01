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

FibonacciHeap::FibonacciHeap(int n, int s) : nodes(n), position(n) {
    build(n, s);
}

FibonacciHeap::~FibonacciHeap(void) {
    for (auto &i : position) {
        free(i);
    }
    for (auto &i : A) {
        free(i);
    }
}

void FibonacciHeap::build(int n, int s) {
    min = nullptr;
    total_nodes = 0;
    insertion(0, s);
    for (unsigned int i = 1; i < n; i++) {
        insertion(std::numeric_limits<double>::infinity(), i);
    }

    A.resize(n);
    for (unsigned int i = 0; i < A.size(); i++) {
        A[i] = nullptr;
    }
}

bool FibonacciHeap::empty() {
    return total_nodes == 0;
}

void FibonacciHeap::insertion(double val, int pos) {
    auto *new_node = (struct HeapNode *) malloc(sizeof(struct HeapNode));
    new_node->key = val;
    new_node->degree = 0;
    new_node->parent = nullptr;
    new_node->child = nullptr;
    new_node->prev = new_node;
    new_node->next = new_node;
    new_node->pos = pos;
    new_node->mark = false;

    insert_on_root(new_node);

    total_nodes++;
    position[pos] = new_node;

}

void FibonacciHeap::insert_on_root(HeapNode *x) {
    HeapNode *z = min;
    if (z != nullptr) {
        z = min;
        x->prev = z;
        x->next = z->next;
        z->next->prev = x;
        z->next = x;
        if (z->key > x->key) {
            min = x;
        }
    } else {
        x->prev = x;
        x->next = x;
        min = x;
    }
}

void FibonacciHeap::remove_from_root(HeapNode *x) {
    if (total_nodes > 0) {
        x->next->prev = x->prev;
        x->prev->next = x->next;
        x->next = x;
        x->prev = x;
    }
    if (total_nodes == 0)
        min = nullptr;
}


int FibonacciHeap::extractMin() {
    if (min == nullptr) {
        std::cout << "Error: Heap is empty" << std::endl;
        return -1;
    }

    HeapNode *z = min;
    if (z != nullptr) {
        if (z->child != nullptr) {
            HeapNode *x;
            do {
                x = z->child;
                insert_on_root(x);
                x->parent = nullptr;
                x = x->child;
            } while (x != z->child);
        }
    }
    remove_from_root(z);
    if (total_nodes == 0)
        min = nullptr;
    else {
        min = z->next;
        consolidate();
    }
    total_nodes--;
    int index = z->pos;
    return index;
}

void FibonacciHeap::consolidate() {
    int golden_ratio = log(total_nodes) / log(1.6810);
    golden_ratio++;
    for (unsigned int i = 0; i < golden_ratio; i++) {
        A[i] = nullptr;
    }

    HeapNode *w = min;
    do {
        HeapNode *x = w;
        int d = x->degree;
        while (A[d] != nullptr) {
            HeapNode *y = A[d];
            if (x->key > y->key) {
                std::swap(x, y);
            }
            fibonnaci_link(y, x);
            A[d] = nullptr;
            d++;
        }
        A[d] = x;
        w = w->next;
    } while (w != min);
}

void FibonacciHeap::fibonnaci_link(HeapNode *y, HeapNode *x) {
    remove_from_root(y);
    y->mark = false;
    insert_on_child(y, x);
}

void FibonacciHeap::insert_on_child(HeapNode *y, HeapNode *x) {
    if (y->child != nullptr) {
        x->prev = y->child;
        x->next = y->child->next;
        y->child->next->prev = x;
        y->child->next = x;
    } else {
        y->child = x;
        x->next = x;
        x->prev = x;
    }
}

void FibonacciHeap::remove_from_child(HeapNode *x, HeapNode *y) {
    if (x == x->next) {
        y->child = nullptr;
    } else if (y->child == x) {
        y->child = x->next;
        y->next->parent = y;
    }

    x->prev->next = x->next;
    x->next->prev = x->prev;
    y->degree--;
}

void FibonacciHeap::Cut(HeapNode *x, HeapNode *y) {
    remove_from_child(x, y);
    insert_on_root(x);
    x->parent = nullptr;
    x->mark = false;
}

void FibonacciHeap::Cascase_cut(HeapNode *y) {
    HeapNode *z = y->parent;
    if (z != nullptr) {
        if (!y->mark)
            y->mark = true;
        else {
            Cut(y, z);
            Cascase_cut(z);
        }
    }
}

void FibonacciHeap::decreaseKey(unsigned long index, double val) {
    HeapNode *x = position[index];
    if (x->key > val) {
        x->key = val;
        HeapNode *y = x->parent;
        if (y != nullptr and x->key < y->key) {
            Cut(x, y);
            Cascase_cut(y);
        }
        if (x->key < min->key)
            min = x;
    }
}