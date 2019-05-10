cmake_minimum_required(VERSION 3.14)
project(mst)

set(CMAKE_CXX_STANDARD 17)

add_executable(mst sources/main.cpp sources/graph.cpp sources/graph.h sources/prim.cpp sources/prim.h sources/kruskal.cpp sources/kruskal.h)