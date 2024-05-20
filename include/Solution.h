#pragma once

#include <vector>
#include <ostream>
#include "Instance.h"

class Solution {
private:
    std::vector<int> cities;
    Instance instance;
public:
    explicit Solution(const Instance &instance);

    double evaluate();

    friend std::ostream &operator<<(std::ostream &os, const Solution &solution);

    void shuffle();

    size_t size();

    [[nodiscard]] const Instance &getInstance() const;

    int operator[](int i);

    void swap(int i, int j);

    void insert(int index, int city);

    void erase(int index);

    [[nodiscard]] std::vector<int> &getCities();
};
