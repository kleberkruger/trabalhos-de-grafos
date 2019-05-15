//
// https://github.com/woodfrog/FibonacciHeap/blob/master/FibHeap.cpp
//

#ifndef MST_FIBHEAP_H
#define MST_FIBHEAP_H


#include <cmath>
#include <vector>
#include <iostream>

namespace fib_heap {

    struct FibHeapNode {
        int vertex; // Kleber Kruger modificou
        float key; // assume the element is int...
        FibHeapNode *left;
        FibHeapNode *right;
        FibHeapNode *parent;
        FibHeapNode *child;
        int degree;
        bool mark;
    };


    class FibHeap {
    public:
        FibHeapNode *m_minNode;
        int m_numOfNodes;

        FibHeap() {  // initialize a new and empty Fib Heap
            m_minNode = nullptr;
            m_numOfNodes = 0;
        }

        FibHeap(int n, int s) : position(n, nullptr) {  // initialize a new and empty Fib Heap
            m_minNode = nullptr;
            m_numOfNodes = 0;

            float inf = std::numeric_limits<float>::infinity();

            for (int i = 0; i < n; i++) {
                insert(i == s ? 0 : inf, i);
            }
        }

        ~FibHeap() {
            _clear(m_minNode);
        }

        /* Insert a node with key value new_key
           and return the inserted node*/
        FibHeapNode *insert(float newKey, int vertex);

        /* Return the key of the minimum node*/
        int extractMin();

        /* Decrease the key of node x to newKey*/
        void decrease_key(FibHeapNode *x, float newKey);

        void decreaseKey(int vertex, float newKey);

        bool empty() {
            return m_numOfNodes == 0;
        }

    private:
        static const int m_minimumKey;

        FibHeapNode *_create_node(float newKey, int vertex);

        void _insert_node(FibHeapNode *newNode);

        void _remove_from_circular_list(FibHeapNode *x);

        FibHeapNode *_merge(FibHeapNode *a, FibHeapNode *b);

        void _make_child(FibHeapNode *child, FibHeapNode *parent);

        void _consolidate();

        void _unparent_all(FibHeapNode *x);

        FibHeapNode *_extract_min_node();

        void _decrease_key(FibHeapNode *x, float newKey);

        void _decreaseKey(int vertex, float newKey);

        void _cut(FibHeapNode *x, FibHeapNode *y);

        void _cascading_cut(FibHeapNode *y);

        void _clear(FibHeapNode *x);

        std::vector<FibHeapNode *> position;
    };

}

#endif //MST_FIBHEAP_H
