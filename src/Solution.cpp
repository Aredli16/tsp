#include "../include/Solution.h"

Solution::Solution(const Graph &graph) {
    for (int i = 0; i < graph.getCities().size(); i++) {
        cities.push_back(i);
    }
}

ostream &operator<<(ostream &os, const Solution &solution) {
    for (int city: solution.cities) {
        os << city << " ";
    }

    return os;
}

const vector<int> &Solution::getCities() const {
    return cities;
}
