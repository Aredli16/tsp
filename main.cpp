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
#include "include/search/local/iterated/IteratedLocalSearch.h"

int main()
{
    int choice;

    std::cout << "1. france_10.tsp" << std::endl << "2. france_50.tsp" << std::endl << "3. france_100.tsp" << std::endl
        << "4. france_200.tsp" << std::endl << "5. france_500.tsp" << std::endl;
    std::cout << "Choose the instance do you want to use: ";

    std::cin >> choice;
    std::string filename;

    switch (choice)
    {
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

    const Instance instance(filename);
    Solution initialSolution(instance);

    std::cout << "Initial Solution: " << initialSolution << std::endl;
    std::cout << "Initial Solution Distance: " << initialSolution.evaluate() << std::endl;


    LocalSearch search;

    Neighbor* swapNeighbor = new SwapNeighbor();
    Neighbor* reintegrationNeighbor = new ReintegrationNeighbor();
    Neighbor* twoOptNeighbor = new TwoOptNeighbor();

    Solution solutionSwapNeighbor = search.search(initialSolution, *swapNeighbor);
    std::cout << "Solution with Swap Neighbor: " << solutionSwapNeighbor << std::endl;
    std::cout << "Solution with Swap Neighbor Distance: " << solutionSwapNeighbor.evaluate() << std::endl;

    Solution solutionReintegrationNeighbor = search.search(initialSolution, *reintegrationNeighbor);
    std::cout << "Solution with Reintegration Neighbor: " << solutionReintegrationNeighbor << std::endl;
    std::cout << "Solution with Reintegration Neighbor Distance: " << solutionReintegrationNeighbor.evaluate() <<
        std::endl;

    Solution solutionTwoOptNeighbor = search.search(initialSolution, *twoOptNeighbor);
    std::cout << "Solution with TwoOpt Neighbor: " << solutionTwoOptNeighbor << std::endl;
    std::cout << "Solution with TwoOpt Neighbor Distance: " << solutionTwoOptNeighbor.evaluate() << std::endl;

    Solution solutionSwapNeighborDescent = search.descentAlgorithm(initialSolution, *swapNeighbor);
    std::cout << "Solution with Swap Neighbor Descent: " << solutionSwapNeighborDescent << std::endl;
    std::cout << "Solution with Swap Neighbor Descent Distance: " << solutionSwapNeighborDescent.evaluate() <<
        std::endl;

    Solution solutionReintegrationNeighborDescent = search.descentAlgorithm(initialSolution, *reintegrationNeighbor);
    std::cout << "Solution with Reintegration Neighbor Descent: " << solutionReintegrationNeighborDescent << std::endl;
    std::cout << "Solution with Reintegration Neighbor Descent Distance: " << solutionReintegrationNeighborDescent.
        evaluate() << std::endl;

    Solution solutionTwoOptNeighborDescent = search.descentAlgorithm(initialSolution, *twoOptNeighbor);
    std::cout << "Solution with TwoOpt Neighbor Descent: " << solutionTwoOptNeighborDescent << std::endl;
    std::cout << "Solution with TwoOpt Neighbor Descent Distance: " << solutionTwoOptNeighborDescent.evaluate() <<
        std::endl;

    Solution solutionSwapNeighborFirstImprover = search.firstImprover(initialSolution, *swapNeighbor);
    std::cout << "Solution with Swap Neighbor First Improver: " << solutionSwapNeighborFirstImprover << std::endl;
    std::cout << "Solution with Swap Neighbor First Improver Distance: " << solutionSwapNeighborFirstImprover.evaluate()
        << std::endl;

    Solution solutionReintegrationNeighborFirstImprover = search.firstImprover(initialSolution, *reintegrationNeighbor);
    std::cout << "Solution with Reintegration Neighbor First Improver: " << solutionReintegrationNeighborFirstImprover
        << std::endl;
    std::cout << "Solution with Reintegration Neighbor First Improver Distance: " <<
        solutionReintegrationNeighborFirstImprover.evaluate() << std::endl;

    Solution solutionTwoOptNeighborFirstImprover = search.firstImprover(initialSolution, *twoOptNeighbor);
    std::cout << "Solution with TwoOpt Neighbor First Improver: " << solutionTwoOptNeighborFirstImprover << std::endl;
    std::cout << "Solution with TwoOpt Neighbor First Improver Distance: " << solutionTwoOptNeighborFirstImprover.
        evaluate() << std::endl;

    Solution solutionSwapNeighborFirstRandomImprover = search.firstRandomImprover(initialSolution, *swapNeighbor);
    std::cout << "Solution with Swap Neighbor First Random Improver: " << solutionSwapNeighborFirstRandomImprover <<
        std::endl;
    std::cout << "Solution with Swap Neighbor First Random Improver Distance: " <<
        solutionSwapNeighborFirstRandomImprover.evaluate() << std::endl;

    Solution solutionReintegrationNeighborFirstRandomImprover = search.firstRandomImprover(
        initialSolution, *reintegrationNeighbor);
    std::cout << "Solution with Reintegration Neighbor First Random Improver: " <<
        solutionReintegrationNeighborFirstRandomImprover << std::endl;
    std::cout << "Solution with Reintegration Neighbor First Random Improver Distance: " <<
        solutionReintegrationNeighborFirstRandomImprover.evaluate() << std::endl;

    Solution solutionTwoOptNeighborFirstRandomImprover = search.firstRandomImprover(initialSolution, *twoOptNeighbor);
    std::cout << "Solution with TwoOpt Neighbor First Random Improver: " << solutionTwoOptNeighborFirstRandomImprover <<
        std::endl;
    std::cout << "Solution with TwoOpt Neighbor First Random Improver Distance: " <<
        solutionTwoOptNeighborFirstRandomImprover.evaluate() << std::endl;

    return 0;
}
