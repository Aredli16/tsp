#pragma once

#include "../Search.h"

class LocalSearch : public Search {
public:
    Solution search(Solution solution, Neighbor &neighbor) override;

    Solution descentAlgorithm(Solution solution, Neighbor &neighbor);
};
