#include <fstream>
#include <iostream>
#include "../include/Graph.h"

Graph::Graph(const string &filename) {
    ifstream file("assets/" + filename);

    if (!file.is_open()) {
        cerr << "Error opening file " << filename << endl;
        exit(1);
    }

    int n;
    file >> n;

    for (int i = 0; i < n; i++) {
        string name;
        double latitude, longitude;
        file >> name >> latitude >> longitude;
        addCity(City(name, latitude, longitude));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            addRoute(Route(cities[i], cities[j]));
        }
    }

    file.close();
}

void Graph::addCity(const City &city) {
    cities.push_back(city);
}

void Graph::addRoute(const Route &route) {
    routes.push_back(route);
}

double Graph::getTotalDistance() {
    double totalDistance = 0;

    for (const Route &route: routes) {
        totalDistance += route.getDistance();
    }

    return totalDistance;
}

ostream &operator<<(ostream &os, const Graph &graph) {
    for (const City &city: graph.cities) {
        os << city << endl;
    }

    for (const Route &route: graph.routes) {
        os << route << endl;
    }

    return os;
}

const vector<City> &Graph::getCities() const {
    return cities;
}
