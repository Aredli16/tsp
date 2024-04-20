cmake_minimum_required(VERSION 3.27)
project(tsp)

set(CMAKE_CXX_STANDARD 23)

add_executable(tsp src/main.cpp
        src/City.cpp
        include/City.h
        include/Graph.h
        src/Graph.cpp
        include/Solver.h
        src/Route.cpp
        include/Route.h
        src/TSPApplication.cpp
        include/TSPApplication.h
        src/Context.cpp
        include/Context.h
        src/Solution.cpp
        include/Solution.h
        src/RandomSolver.cpp
        include/RandomSolver.h)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})
