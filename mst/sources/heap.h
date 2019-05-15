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

#ifndef MST_HEAP_H
#define MST_HEAP_H

#include <iostream>
#include <vector>

class Heap {

    virtual int extractMin() = 0;

    virtual void decreaseKey(unsigned long index, float value) = 0;

    virtual bool empty() = 0;

protected:

//    virtual void build(int n, int s) = 0;
};



#endif //MST_HEAP_H
