#include <cmath>
#include "../../../include/neighbor/twoopt/TwoOptNeighbor.h"

Solution TwoOptNeighbor::generateNeighbor(Solution solution, int i, int j) {
    std::reverse(solution.getCities().begin() + i, solution.getCities().begin() + j + 1);
    return solution;
}

Solution TwoOptNeighbor::generateNeighborByIndex(Solution solution, int index) {
    double n = (1 + sqrt(1 + 8 * index)) / 2;
    int i = index - (n * (n - 1)) / 2;
    int j = solution.size() - n + i;

    return generateNeighbor(solution, i, j);
}

int TwoOptNeighbor::getNeighborCount(Solution solution) {
    int n = solution.size();
    return (n * (n - 1)) / 2;
}
