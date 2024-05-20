#pragma once

#include "../Solution.h"
#include "../neighbor/Neighbor.h"

class Search {
public:
    virtual Solution search(Solution solution, Neighbor &neighbor) = 0;
};
