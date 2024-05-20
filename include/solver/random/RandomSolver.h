#pragma once

#include "../Solver.h"

class RandomSolver : public Solver {
public:
    void operator()(Solution &solution) override;
};
