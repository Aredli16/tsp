#pragma once

#include "Solution.h"

class Solver {
protected:
    virtual void operator()(Solution solution) = 0;
};
