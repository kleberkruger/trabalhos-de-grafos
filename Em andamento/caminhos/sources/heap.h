/**
 * Algoritmos em Grafos (MO412)
 *
 * @author: Kleber Kruger <kleberkruger@gmail.com>
 * @author: Felipe Barbosa <felipebarbosa@uft.edu.com>
 * @author: Rodrigo Kanehisa <rodrigokanehisa@gmail.com>
 */

#ifndef MST_HEAP_H
#define MST_HEAP_H

#include <iostream>
#include <vector>
#include <limits>

class Heap {

    virtual int extractMin() = 0;

    virtual void decreaseKey(unsigned long vertex, double value) = 0;

    virtual bool empty() = 0;

protected:

//    virtual void build(int n, int s) = 0;
};



#endif //MST_HEAP_H
