#include <utility>

#include "../include/Route.h"

Route::Route(City cityA, City cityB) : cityA(std::move(cityA)), cityB(std::move(cityB)),
                                       distance(cityA.distanceTo(cityB)) {}

double Route::getDistance() const {
    return distance;
}

ostream &operator<<(ostream &os, const Route &route) {
    os << "cityA: " << route.cityA << " cityB: " << route.cityB << " distance: " << route.distance;
    return os;
}
