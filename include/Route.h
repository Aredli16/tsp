#pragma once

#include <ostream>
#include "City.h"

class Route {
private:
    City cityA;
    City cityB;
    double distance;
public:
    friend ostream &operator<<(ostream &os, const Route &route);

public:
    Route(City cityA, City cityB);

    [[nodiscard]] double getDistance() const;
};
