#ifndef MST_HEAP_H
#define MST_HEAP_H

#include <vector>
#include <algorithm>
#include <cmath>

class Heap {
    virtual void heapify() = 0;
    virtual void build() = 0;
    virtual void decreaseKey() = 0;
    virtual void extractMin() = 0;
    virtual bool find() = 0;
    virtual bool empty() = 0;

    inline int parent(int i){return floor((i-1)/2)};
    inline int left(int i){return 2*i + 1;};
    inline int right(int i){return 2*i + 2;};


    std::vector<int> h;
};

#endif // MST_HEAP_H