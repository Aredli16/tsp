#pragma once

#include <ostream>
#include "Graph.h"
#include "Solver.h"
#include "Solution.h"

class Context {
private:
    Graph graph;
    Solver *solver;
    Solution solution;
public:
    explicit Context(const string &filename, Solver *solver);

    friend ostream &operator<<(ostream &os, const Context &context);

};
