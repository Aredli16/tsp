#pragma once

#include "../Solution.h"

class Neighbor {
public:
    virtual Solution generateNeighbor(Solution solution, int i, int j) = 0;

    virtual Solution generateNeighborByIndex(Solution solution, int index) = 0;

    virtual int getNeighborCount(Solution solution) = 0;
};
