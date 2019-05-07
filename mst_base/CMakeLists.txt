cmake_minimum_required(VERSION 3.14)
project(mst)

set(CMAKE_CXX_STANDARD 17)

add_executable(mst sources/Main.cpp sources/Graph.cpp sources/Graph.h sources/DisjointSet.cpp sources/DisjointSet.h)