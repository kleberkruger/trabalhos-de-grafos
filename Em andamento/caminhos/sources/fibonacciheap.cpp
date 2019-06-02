//
// Created by Kleber Kruger on 2019-06-02.
//

#include "fibonacciheap.h"

FibonacciHeap::FibonacciHeap() {
    root = nullptr;
}

FibonacciHeap::FibonacciHeap(int n, int s) {
    root = nullptr;
    build(n, s);
}

FibonacciHeap::~FibonacciHeap() {
    if (root) {
        _deleteAll(root);
    }
}

void FibonacciHeap::build(int n, int s) {
    for (int i = 0; i < n; i++) {
        insert(GraphNode(i, i == s ? 0 : std::numeric_limits<double>::infinity()));
    }
}

FibonacciNode *FibonacciHeap::insert(GraphNode value) {
    FibonacciNode *ret = _singleton(value);
    root = _merge(root, ret);
    return ret;
}

bool FibonacciHeap::empty() {
    return root == nullptr;
}

int FibonacciHeap::extractMin() {
    FibonacciNode *old = root;
    root = _removeMinimum(root);
    GraphNode ret = old->value;
    delete old;
    return ret.vertex;
}

void FibonacciHeap::decreaseKey(unsigned long vertex, double value) {
    GraphNode v(vertex, value);
    root = _decreaseKey(root, find(v), v);
}

FibonacciNode *FibonacciHeap::_singleton(GraphNode value) {
    auto *n = new FibonacciNode;
    n->value = value;
    n->prev = n->next = n;
    n->degree = 0;
    n->marked = false;
    n->child = nullptr;
    n->parent = nullptr;
    return n;
}

FibonacciNode *FibonacciHeap::_merge(FibonacciNode *a, FibonacciNode *b) {
    if (a == nullptr) return b;
    if (b == nullptr) return a;
    if (a->value > b->value) {
        FibonacciNode *temp = a;
        a = b;
        b = temp;
    }
    FibonacciNode *an = a->next;
    FibonacciNode *bp = b->prev;
    a->next = b;
    b->prev = a;
    an->prev = bp;
    bp->next = an;
    return a;
}

void FibonacciHeap::_deleteAll(FibonacciNode *n) {
    if (n != nullptr) {
        FibonacciNode *c = n;
        do {
            FibonacciNode *d = c;
            c = c->next;
            _deleteAll(d->child);
            delete d;
        } while (c != n);
    }
}

void FibonacciHeap::_addChild(FibonacciNode *parent, FibonacciNode *child) {
    child->prev = child->next = child;
    child->parent = parent;
    parent->degree++;
    parent->child = _merge(parent->child, child);
}

void FibonacciHeap::_unMarkAndUnParentAll(FibonacciNode *n) {
    if (n == nullptr) return;
    FibonacciNode *c = n;
    do {
        c->marked = false;
        c->parent = nullptr;
        c = c->next;
    } while (c != n);
}

FibonacciNode *FibonacciHeap::_removeMinimum(FibonacciNode *n) {
    _unMarkAndUnParentAll(n->child);
    if (n->next == n) {
        n = n->child;
    } else {
        n->next->prev = n->prev;
        n->prev->next = n->next;
        n = _merge(n->next, n->child);
    }
    if (n == nullptr) return n;
    FibonacciNode *trees[64] = {nullptr};

    while (true) {
        if (trees[n->degree] != nullptr) {
            FibonacciNode *t = trees[n->degree];
            if (t == n)break;
            trees[n->degree] = nullptr;
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

    FibonacciNode *min = n;
    FibonacciNode *start = n;
    do {
        if (n->value < min->value) min = n;
        n = n->next;
    } while (n != start);

    return min;
}

FibonacciNode *FibonacciHeap::_cut(FibonacciNode *heap, FibonacciNode *n) {
    if (n->next == n) {
        n->parent->child = nullptr;
    } else {
        n->next->prev = n->prev;
        n->prev->next = n->next;
        n->parent->child = n->next;
    }
    n->next = n->prev = n;
    n->marked = false;
    return _merge(heap, n);
}

FibonacciNode *FibonacciHeap::_decreaseKey(FibonacciNode *heap, FibonacciNode *n, GraphNode value) {
    if (n->value < value) return heap;
    n->value = value;
    if (n->parent) {
        if (n->value < n->parent->value) {
            heap = _cut(heap, n);
            FibonacciNode *parent = n->parent;
            n->parent = nullptr;
            while (parent != nullptr && parent->marked) {
                heap = _cut(heap, parent);
                n = parent;
                parent = n->parent;
                n->parent = nullptr;
            }
            if (parent != nullptr && parent->parent != nullptr)parent->marked = true;
        }
    } else {
        if (n->value < heap->value) {
            heap = n;
        }
    }
    return heap;
}

FibonacciNode *FibonacciHeap::find(GraphNode value) {
    return find(root, value);
}

FibonacciNode *FibonacciHeap::find(FibonacciNode *heap, GraphNode value) {
    FibonacciNode *n = heap;
    if (n == nullptr)return nullptr;
    do {
        if (n->value == value)return n;
        FibonacciNode *ret = find(n->child, value);
        if (ret)return ret;
        n = n->next;
    } while (n != heap);
    return nullptr;
}
