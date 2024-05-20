#include "../../../../include/search/local/iterated/IteratedLocalSearch.h"

Solution IteratedLocalSearch::iteratedLocalSearch(Solution solution, Neighbor& neighbor, int maxIterations, int force)
{
    while (maxIterations--) {
        const Solution perturbedSolution = perturb(solution, neighbor, force);
        Solution localOptimum = descentAlgorithm(perturbedSolution, neighbor);
        const double localOptimumDistance = localOptimum.evaluate();

        if (localOptimumDistance < solution.evaluate()) {
            solution = localOptimum;
        }
    }
}
