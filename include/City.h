#pragma once

#include <string>

class City {
private:
    std::string name;
    double latitude;
    double longitude;
public:
    City(std::string name, double latitude, double longitude);

    [[nodiscard]] double distance(const City &other) const;

    [[nodiscard]] double getRadianLatitude() const;

    [[nodiscard]] double getRadianLongitude() const;
};
