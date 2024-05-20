#include "../../../include/solver/random/RandomSolver.h"

void RandomSolver::operator()(Solution &solution) {
    solution.shuffle();
}
