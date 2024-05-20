#include "../../../include/neighbor/reintegration/ReintegrationNeighbor.h"

Solution ReintegrationNeighbor::generateNeighbor(Solution solution, int i, int j) {
    solution.insert(j, solution[i]);
    solution.erase(i);
    return solution;
}

Solution ReintegrationNeighbor::generateNeighborByIndex(Solution solution, int index) {
    int i, j;

    if (index <= solution.size() - 2) {
        i = 0;
        j = index + 1;
    } else {
        i = (index - 1) / (solution.size() - 2);
        j = (index - 1) % (solution.size() - 2);
        if (j >= i - 1)
            j += 2;
    }

    return generateNeighbor(solution, i, j);
}

int ReintegrationNeighbor::getNeighborCount(Solution solution) {
    int n = solution.size();
    return (n - 1) * (n - 1);
}
