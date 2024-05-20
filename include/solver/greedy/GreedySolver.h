#pragma once

#include "../Solver.h"

class GreedySolver : public Solver {
public:
    void operator()(Solution &solution) override;
};
