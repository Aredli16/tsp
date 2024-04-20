#pragma oncle

#include <string>
#include <ostream>

using namespace std;

class City {
private:
    string name;
    double latitude;
    double longitude;
public:
    City(string name, double latitude, double longitude);

    [[nodiscard]] double distanceTo(const City &city) const;

    static double toRadian(double val);

    friend ostream &operator<<(ostream &os, const City &city);
};
