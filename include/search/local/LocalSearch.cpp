#include "LocalSearch.h"

Solution LocalSearch::search(Solution solution, Neighbor &neighbor) {
    double bestDistance = solution.evaluate();
    for (int i = 0; i < neighbor.getNeighborCount(solution) - 1; ++i) {
        Solution neighborSolution = neighbor.generateNeighborByIndex(solution, i);
        double neighborDistance = neighborSolution.evaluate();
        if (neighborDistance < bestDistance) {
            solution = neighborSolution;
            bestDistance = neighborDistance;
        }
    }
    return solution;
}

Solution LocalSearch::descentAlgorithm(Solution solution, Neighbor &neighbor) {
    double distanceSolution = solution.evaluate();
    Solution *bestSolution = nullptr;
    double bestDistance = RAND_MAX;

    while (bestDistance > distanceSolution) {
        bestSolution = &solution;
        bestDistance = distanceSolution;
        solution = search(solution, neighbor);
        distanceSolution = solution.evaluate();
    }

    return *bestSolution;
}
