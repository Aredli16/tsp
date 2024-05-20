#include <random>

#include "../include/Solution.h"

#include <algorithm>

Solution::Solution(const Instance &instance) : instance(instance) {
    for (int i = 0; i < instance.getCities().size(); ++i) {
        cities.push_back(i);
    }
}

double Solution::evaluate() {
    double distance = 0.0;

    for (int i = 0; i < cities.size() - 1; ++i) {
        distance += instance[cities[i]].distance(instance[cities[i + 1]]);
    }

    distance += instance[cities[cities.size() - 1]].distance(instance[cities[0]]);

    return distance;
}

std::ostream &operator<<(std::ostream &os, const Solution &solution) {
    for (int city: solution.cities) {
        os << city << " ";
    }

    return os;
}

void Solution::shuffle() {
    std::shuffle(cities.begin(), cities.end(), std::mt19937(std::random_device()()));
}

size_t Solution::size() {
    return cities.size();
}

const Instance &Solution::getInstance() const {
    return instance;
}

int Solution::operator[](int i) {
    return cities[i];
}

void Solution::swap(int i, int j) {
    std::swap(cities[i], cities[j]);
}

void Solution::insert(int index, int city) {
    cities.insert(cities.begin() + index + 1, city);
}

void Solution::erase(int index) {
    cities.erase(cities.begin() + index);
}

std::vector<int> &Solution::getCities() {
    return cities;
}
