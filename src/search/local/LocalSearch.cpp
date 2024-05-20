#include "../../../include/search/local/LocalSearch.h"

#include <algorithm>
#include <numeric>
#include <random>

Solution LocalSearch::search(Solution solution, Neighbor& neighbor)
{
    double bestDistance = solution.evaluate();
    for (int i = 0; i < neighbor.getNeighborCount(solution) - 1; ++i)
    {
        Solution neighborSolution = neighbor.generateNeighborByIndex(solution, i);
        double neighborDistance = neighborSolution.evaluate();
        if (neighborDistance < bestDistance)
        {
            solution = neighborSolution;
            bestDistance = neighborDistance;
        }
    }
    return solution;
}

Solution LocalSearch::descentAlgorithm(Solution solution, Neighbor& neighbor)
{
    double distanceSolution = solution.evaluate();
    Solution* bestSolution = nullptr;
    double bestDistance = RAND_MAX;

    while (bestDistance > distanceSolution)
    {
        bestSolution = &solution;
        bestDistance = distanceSolution;
        solution = search(solution, neighbor);
        distanceSolution = solution.evaluate();
    }

    return *bestSolution;
}

Solution LocalSearch::firstImprover(Solution solution, Neighbor& neighbor)
{
    for (int i = 0; i < neighbor.getNeighborCount(solution); ++i) {
        Solution neighborSolution = neighbor.generateNeighborByIndex(solution, i);
        if (neighborSolution.evaluate() < solution.evaluate()) {
            return neighborSolution;
        }
    }
    return solution;
}

Solution LocalSearch::firstRandomImprover(Solution solution, Neighbor& neighbor)
{
    int neighborCount = neighbor.getNeighborCount(solution);
    std::vector<int> indices(neighborCount);
    std::iota(indices.begin(), indices.end(), 0);
    std::shuffle(indices.begin(), indices.end(), std::mt19937(std::random_device()()));

    for (int i : indices) {
        Solution neighborSolution = neighbor.generateNeighborByIndex(solution, i);
        if (neighborSolution.evaluate() < solution.evaluate()) {
            return neighborSolution;
        }
    }
    return solution;
}

Solution LocalSearch::perturb(Solution solution, Neighbor& neighbor, int force)
{
    std::mt19937 rng(std::random_device{}());
    for (int i = 0; i < force; ++i) {
        int index = rng() % neighbor.getNeighborCount(solution);
        solution = neighbor.generateNeighborByIndex(solution, index);
    }
    return solution;
}
