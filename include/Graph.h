#pragma once

#include <vector>
#include <ostream>
#include "Route.h"

using namespace std;

class Graph {
private:
    vector<City> cities;
    vector<Route> routes;
public:
    explicit Graph(const string &filename);

    void addCity(const City &city);

    void addRoute(const Route &route);

    friend ostream &operator<<(ostream &os, const Graph &graph);

    double getTotalDistance();

    [[nodiscard]] const vector<City> &getCities() const;
};
