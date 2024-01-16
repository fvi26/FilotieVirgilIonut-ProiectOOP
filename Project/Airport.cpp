#include "Airport.h"

Airport::Airport(const std::string& n) : name(n) {}

const std::string& Airport::getName() const {
    return name;
}

std::ostream& operator<<(std::ostream& out, const Airport& airport) {
    out << "Airport Name: " << airport.name;
    return out;
}
