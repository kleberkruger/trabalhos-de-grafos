#include <iostream>
#include "fibonacciheap.h"

using std::cout;
using std::endl;

int main(int argc, char *argv[]) {
	int n = 10;
    FibonacciHeap H = FibonacciHeap(n,0);
    for(int i = 0; i < n; i++){
    	H.decreaseKey(i,i);
    	cout << H.extractMin() << endl;
    }

    return EXIT_SUCCESS;
}
