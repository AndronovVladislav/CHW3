cmake_minimum_required(VERSION 3.22)
project(IHW3)

set(CMAKE_CXX_STANDARD 14)

add_executable(IHW3
#        GraphAlgorithms/floyd_warshall.cpp
        GraphAlgorithms/dijkstra.cpp
#        GraphAlgorithms/ford_bellman.cpp
        Utils/CSVReader.cpp
        Utils/CSVReader.h
        Utils/GraphConstructor.cpp
        Utils/GraphConstructor.h
        Utils/common.h
)