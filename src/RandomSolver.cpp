#include <random>
#include <algorithm>
#include <ctime>
#include "../include/RandomSolver.h"

void RandomSolver::operator()(Solution solution) {
    std::random_device rd;
    std::mt19937 g(rd());
    g.seed(time(nullptr));
    std::shuffle(solution.getCities().begin(), solution.getCities().end(), g);
}
