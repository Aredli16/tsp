#include <utility>
#include <cmath>

#include "../include/City.h"

City::City(string name, double latitude, double longitude) : name(std::move(name)), latitude(latitude),
                                                             longitude(longitude) {}

double City::distanceTo(const City &city) const {
    return 6378.137 * acos(sin(toRadian(this->latitude)) * sin(toRadian(city.latitude)) +
                           cos(toRadian(this->latitude)) * cos(toRadian(city.latitude)) *
                           cos(toRadian(this->longitude) - toRadian(city.longitude)));;
}

double City::toRadian(double val) {
    return val * M_PI / 180;
}

ostream &operator<<(ostream &os, const City &city) {
    os << "name: " << city.name << " latitude: " << city.latitude << " longitude: " << city.longitude;
    return os;
}
