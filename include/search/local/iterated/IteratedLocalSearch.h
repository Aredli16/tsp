#pragma once
#include "../LocalSearch.h"

class IteratedLocalSearch: public LocalSearch
{
public:
    Solution iteratedLocalSearch(Solution solution, Neighbor &neighbor, int maxIterations, int force);
};
