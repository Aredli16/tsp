#include "../../../../include/search/local/variable/VariableLocalSearch.h"

Solution VariableLocalSearch::variableNeighborhoodSearch(Solution solution, std::vector<Neighbor*> neighbors,
    int maxIterations, int force)
{
    Solution bestSolution = solution;
    double bestDistance = solution.evaluate();

    for (int i = 0; i < maxIterations; ++i) {
        for (Neighbor* neighbor : neighbors) {
            const Solution perturbedSolution = perturb(bestSolution, *neighbor, force);
            Solution localOptimum = descentAlgorithm(perturbedSolution, *neighbor);
            const double localOptimumDistance = localOptimum.evaluate();

            if (localOptimumDistance < bestDistance) {
                bestSolution = localOptimum;
                bestDistance = localOptimumDistance;
            }
        }
    }

    return bestSolution;
}
