cmake_minimum_required(VERSION 3.27)
project(tsp)

set(CMAKE_CXX_STANDARD 23)

add_executable(tsp main.cpp
        src/City.cpp
        include/City.h
        src/Instance.cpp
        include/Instance.h
        src/Solution.cpp
        include/Solution.h
        include/solver/Solver.h
        src/solver/random/RandomSolver.cpp
        include/solver/random/RandomSolver.h
        src/solver/greedy/GreedySolver.cpp
        include/solver/greedy/GreedySolver.h
        include/neighbor/Neighbor.h
        src/neighbor/swap/SwapNeighbor.cpp
        include/neighbor/swap/SwapNeighbor.h
        src/neighbor/reintegration/ReintegrationNeighbor.cpp
        include/neighbor/reintegration/ReintegrationNeighbor.h
        src/neighbor/twoopt/TwoOptNeighbor.cpp
        include/neighbor/twoopt/TwoOptNeighbor.h
        include/search/Search.h
        src/search/local/LocalSearch.cpp
        include/search/local/LocalSearch.h
        src/search/local/iterated/IteratedLocalSearch.cpp
        include/search/local/iterated/IteratedLocalSearch.h
        src/search/local/variable/VariableLocalSearch.cpp
        include/search/local/variable/VariableLocalSearch.h
)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})
