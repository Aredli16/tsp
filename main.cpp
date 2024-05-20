#include <iostream>
#include "include/Instance.h"
#include "include/Solution.h"
#include "include/solver/random/RandomSolver.h"
#include "include/solver/greedy/GreedySolver.h"
#include "include/neighbor/swap/SwapNeighbor.h"
#include "include/neighbor/reintegration/ReintegrationNeighbor.h"
#include "include/neighbor/twoopt/TwoOptNeighbor.h"
#include "include/search/Search.h"
#include "include/search/local/LocalSearch.h"

int main() {
    int choice;

    std::cout << "1. france_10.tsp" << std::endl << "2. france_50.tsp" << std::endl << "3. france_100.tsp" << std::endl
              << "4. france_200.tsp" << std::endl << "5. france_500.tsp" << std::endl;
    std::cout << "Choose the instance do you want to use: ";

    std::cin >> choice;
    std::string filename;

    switch (choice) {
        case 1:
            filename = "france_10.tsp";
            break;
        case 2:
            filename = "france_50.tsp";
            break;
        case 3:
            filename = "france_100.tsp";
            break;
        case 4:
            filename = "france_200.tsp";
            break;
        case 5:
            filename = "france_500.tsp";
            break;
        default:
            std::cout << "Invalid choice" << std::endl;
            return 1;
    }

    Instance instance(filename);
    Solution solution(instance);

    Neighbor *neighbor = new SwapNeighbor();
    Solution solutionSwapNeighbor = neighbor->generateNeighbor(solution, 2, 5);

    std::cout << "Swap Neighbor Solution: " << solutionSwapNeighbor << std::endl;
    std::cout << "Swap Neighbor Solution Count: " << neighbor->getNeighborCount(solutionSwapNeighbor) << std::endl;

    neighbor = new ReintegrationNeighbor();
    Solution solutionReintegrationNeighbor = neighbor->generateNeighbor(solution, 2, 5);

    std::cout << "Reintegration Neighbor Solution: " << solutionReintegrationNeighbor << std::endl;
    std::cout << "Reintegration Neighbor Solution Count: " << neighbor->getNeighborCount(solutionReintegrationNeighbor)
              << std::endl;

    neighbor = new TwoOptNeighbor();
    Solution solutionTwoOptNeighbor = neighbor->generateNeighbor(solution, 2, 5);

    std::cout << "TwoOpt Neighbor Solution: " << solutionTwoOptNeighbor << std::endl;
    std::cout << "TwoOpt Neighbor Solution Count: " << neighbor->getNeighborCount(solutionTwoOptNeighbor) << std::endl;

    LocalSearch search;
    Solution localSearchSolution = search.descentAlgorithm(solution, *neighbor);

    std::cout << "Local Search Solution: " << localSearchSolution << std::endl;
    std::cout << "Local Search Solution Distance: " << localSearchSolution.evaluate() << std::endl;
    return 0;
}
