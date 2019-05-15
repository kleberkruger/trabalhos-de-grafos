cmake_minimum_required(VERSION 3.14)
project(mst)

set(CMAKE_CXX_STANDARD 17)

add_executable(mst sources/main.cpp sources/graph.cpp sources/graph.h sources/disjointset.cpp sources/disjointset.h sources/arrayset.cpp sources/arrayset.h sources/listset.cpp sources/listset.h sources/unionfind.cpp sources/unionfind.h sources/fastunionfind.cpp sources/fastunionfind.h sources/heap.cpp sources/heap.h sources/arrayheap.cpp sources/arrayheap.h sources/binaryheap.cpp sources/binaryheap.h sources/fibonacciheap.cpp sources/fibonacciheap.h sources/fibheap.cpp sources/fibheap.h)