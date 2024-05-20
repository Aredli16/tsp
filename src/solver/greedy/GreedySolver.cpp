#include "../../../include/solver/greedy/GreedySolver.h"

void GreedySolver::operator()(Solution &solution) {
    for (int i = 0; i < solution.size(); ++i) {
        double min = RAND_MAX;
        int index = -1;

        for (int j = i + 1; j < solution.size(); ++j) {
            double distance = solution.getInstance()[solution[i]].distance(solution.getInstance()[solution[j]]);

            if (distance < min) {
                min = distance;
                index = j;
            }
        }

        solution.swap(i + 1, index);
    }
}
