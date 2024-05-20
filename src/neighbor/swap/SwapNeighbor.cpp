#include <cmath>
#include "../../../include/neighbor/swap/SwapNeighbor.h"

Solution SwapNeighbor::generateNeighbor(Solution solution, int i, int j) {
    solution.swap(i, j);
    return solution;
}

Solution SwapNeighbor::generateNeighborByIndex(Solution solution, int index) {
    double n = (1 + sqrt(1 + 8 * index)) / 2;
    int i = index - (n * (n - 1)) / 2;
    int j = solution.size() - n + i;

    return generateNeighbor(solution, i, j);
}

int SwapNeighbor::getNeighborCount(Solution solution) {
    int n = solution.size();
    return (n * (n - 1)) / 2;
}
