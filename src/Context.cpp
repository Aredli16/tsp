#include "../include/Context.h"

Context::Context(const string &filename, Solver *solver) : solver(solver), graph(filename), solution(graph) {
}

ostream &operator<<(ostream &os, const Context &context) {
    os << "graph: " << context.graph << " solver: " << context.solver << " solution: " << context.solution;
    return os;
}
