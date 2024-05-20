#pragma once

#include <vector>
#include "City.h"

class Instance {
private:
    std::vector<City> cities;
public:
    explicit Instance(const std::string &filename);

    [[nodiscard]] const std::vector<City> &getCities() const;

    City operator[](int i) const;
};
