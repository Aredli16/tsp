#include <fstream>
#include "../include/Instance.h"

Instance::Instance(const std::string &filename) {
    std::ifstream file("assets/" + filename);

    if (!file.is_open()) {
        throw std::runtime_error("Could not open file " + filename);
    }

    int n;
    file >> n;

    for (int i = 0; i < n; ++i) {
        std::string name;
        double latitude, longitude;
        file >> name >> latitude >> longitude;
        cities.emplace_back(name, latitude, longitude);
    }
}

const std::vector<City> &Instance::getCities() const {
    return cities;
}

City Instance::operator[](int i) const {
    return cities[i];
}
