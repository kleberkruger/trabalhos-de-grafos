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

#include "listset.h"

ListDisjointSet::ListDisjointSet(int n) : nodes(n) {
    makeSet();
}

void ListDisjointSet::makeSet() {
    for (int i = 0; i < nodes.size(); i++) {
        nodes[i].id = i;
        nodes[i].parent = &nodes[i];
    }
}

int ListDisjointSet::find(int x) {
    return nodes[x].parent->id;
}

void ListDisjointSet::join(int x, int y) {

}

bool ListDisjointSet::sameSet(int x, int y) {
    return false;
}
