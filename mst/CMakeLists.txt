cmake_minimum_required(VERSION 3.14)
project(mst)

set(CMAKE_CXX_STANDARD 17)

add_executable(mst sources/main.cpp sources/disjoint_set.cpp sources/disjoint_set.h sources/graph.cpp sources/graph.h sources/kruskal.cpp sources/kruskal.h)