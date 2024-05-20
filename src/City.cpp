#include <utility>
#include <cmath>

#include "../include/City.h"

City::City(std::string name, double latitude, double longitude) : name(std::move(name)), latitude(latitude),
                                                                  longitude(longitude) {}

double City::distance(const City &other) const {
    return 6378.137 * acos(sin(getRadianLatitude()) * sin(other.getRadianLatitude()) +
                           cos(getRadianLatitude()) * cos(other.getRadianLatitude()) *
                           cos(getRadianLongitude() - other.getRadianLongitude()));
}

double City::getRadianLatitude() const {
    return M_PI * latitude / 180;
}

double City::getRadianLongitude() const {
    return M_PI * longitude / 180;
}
