#pragma once

#include "../Neighbor.h"

class TwoOptNeighbor : public Neighbor {
public:
    Solution generateNeighbor(Solution solution, int i, int j) override;

    Solution generateNeighborByIndex(Solution solution, int index) override;


    int getNeighborCount(Solution solution) override;
};
