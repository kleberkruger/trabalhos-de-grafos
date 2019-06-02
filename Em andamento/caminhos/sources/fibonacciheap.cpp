//
// Created by Kleber Kruger on 2019-06-02.
//

#include "fibonacciheap.h"

FibonacciHeap::FibonacciHeap() {
    heap = nullptr;
}

FibonacciHeap::FibonacciHeap(int n, int s) {
    heap = nullptr;
    build(n, s);
}

FibonacciHeap::~FibonacciHeap() {
    if (heap) {
        _deleteAll(heap);
    }
}

void FibonacciHeap::build(int n, int s) {
    for (int i = 0; i < n; i++) {
        insert(GraphNode(i, i == s ? 0 : std::numeric_limits<double>::infinity()));
    }
}

node *FibonacciHeap::insert(GraphNode value) {
    node *ret = _singleton(value);
    heap = _merge(heap, ret);
    return ret;
}

void FibonacciHeap::merge(FibonacciHeap &other) {
    heap = _merge(heap, other.heap);
    other.heap = nullptr;
}

bool FibonacciHeap::empty() {
    return heap == NULL;
}

GraphNode FibonacciHeap::getMinimum() {
    return heap->value;
}

int FibonacciHeap::extractMin() {
    node *old = heap;
    heap = _removeMinimum(heap);
    GraphNode ret = old->value;
    delete old;
    return ret.vertex;
}

void FibonacciHeap::decreaseKey(node *n, GraphNode value) {
    heap = _decreaseKey(heap, n, value);
}

void FibonacciHeap::decreaseKey(unsigned long vertex, double value) {
    GraphNode v(vertex, value);
    decreaseKey(find(v), v);
}

node *FibonacciHeap::find(GraphNode value) {
    return _find(heap, value);
}

node *FibonacciHeap::_singleton(GraphNode value) {
    node *n = new node;
    n->value = value;
    n->prev = n->next = n;
    n->degree = 0;
    n->marked = false;
    n->child = NULL;
    n->parent = NULL;
    return n;
}

node *FibonacciHeap::_merge(node *a, node *b) {
    if (a == NULL)return b;
    if (b == NULL)return a;
    if (a->value > b->value) {
        node *temp = a;
        a = b;
        b = temp;
    }
    node *an = a->next;
    node *bp = b->prev;
    a->next = b;
    b->prev = a;
    an->prev = bp;
    bp->next = an;
    return a;
}

void FibonacciHeap::_deleteAll(node *n) {
    if (n != NULL) {
        node *c = n;
        do {
            node *d = c;
            c = c->next;
            _deleteAll(d->child);
            delete d;
        } while (c != n);
    }
}

void FibonacciHeap::_addChild(node *parent, node *child) {
    child->prev = child->next = child;
    child->parent = parent;
    parent->degree++;
    parent->child = _merge(parent->child, child);
}

void FibonacciHeap::_unMarkAndUnParentAll(node *n) {
    if (n == NULL)return;
    node *c = n;
    do {
        c->marked = false;
        c->parent = NULL;
        c = c->next;
    } while (c != n);
}

node *FibonacciHeap::_removeMinimum(node *n) {
    _unMarkAndUnParentAll(n->child);
    if (n->next == n) {
        n = n->child;
    } else {
        n->next->prev = n->prev;
        n->prev->next = n->next;
        n = _merge(n->next, n->child);
    }
    if (n == NULL)return n;
    node *trees[64] = {NULL};

    while (true) {
        if (trees[n->degree] != NULL) {
            node *t = trees[n->degree];
            if (t == n)break;
            trees[n->degree] = NULL;
            if (n->value < t->value) {
                t->prev->next = t->next;
                t->next->prev = t->prev;
                _addChild(n, t);
            } else {
                t->prev->next = t->next;
                t->next->prev = t->prev;
                if (n->next == n) {
                    t->next = t->prev = t;
                    _addChild(t, n);
                    n = t;
                } else {
                    n->prev->next = t;
                    n->next->prev = t;
                    t->next = n->next;
                    t->prev = n->prev;
                    _addChild(t, n);
                    n = t;
                }
            }
            continue;
        } else {
            trees[n->degree] = n;
        }
        n = n->next;
    }

    node *min = n;
    node *start = n;
    do {
        if (n->value < min->value) min = n;
        n = n->next;
    } while (n != start);

    return min;
}

node *FibonacciHeap::_cut(node *heap, node *n) {
    if (n->next == n) {
        n->parent->child = NULL;
    } else {
        n->next->prev = n->prev;
        n->prev->next = n->next;
        n->parent->child = n->next;
    }
    n->next = n->prev = n;
    n->marked = false;
    return _merge(heap, n);
}

node *FibonacciHeap::_decreaseKey(node *heap, node *n, GraphNode value) {
    if (n->value < value)return heap;
    n->value = value;
    if (n->parent) {
        if (n->value < n->parent->value) {
            heap = _cut(heap, n);
            node *parent = n->parent;
            n->parent = NULL;
            while (parent != NULL && parent->marked) {
                heap = _cut(heap, parent);
                n = parent;
                parent = n->parent;
                n->parent = NULL;
            }
            if (parent != NULL && parent->parent != NULL)parent->marked = true;
        }
    } else {
        if (n->value < heap->value) {
            heap = n;
        }
    }
    return heap;
}

node *FibonacciHeap::_find(node *heap, GraphNode value) {
    node *n = heap;
    if (n == NULL)return NULL;
    do {
        if (n->value == value)return n;
        node *ret = _find(n->child, value);
        if (ret)return ret;
        n = n->next;
    } while (n != heap);
    return NULL;
}
