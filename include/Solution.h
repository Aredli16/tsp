#pragma once

#include <vector>
#include <ostream>
#include "Graph.h"

using namespace std;

class Solution {
private:
    vector<int> cities;
public:
    explicit Solution(const Graph &graph);

    friend ostream &operator<<(ostream &os, const Solution &solution);

    const vector<int> &getCities() const;
};
