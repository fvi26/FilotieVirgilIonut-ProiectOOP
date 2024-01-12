#include "Airline.h"
#include "AirlineError.h"

Airline::Airline(const std::string& n) : name(n) {}

const std::string& Airline::getName() const {
    return name;
}

void Airline::makeReservation(const Reservation& r, int quantity) {
    if (quantity <= 0) {
        throw AirlineError("Invalid quantity for reservation.");
    }

    for (int i = 0; i < quantity; ++i) {
        reservations.push_back(r);
    }
}

void Airline::displayReservations() const {
    for (const Reservation& r : reservations) {
        std::cout << r << "---------------------------------" << std::endl;
    }
}

void Airline::displayInfo() const {
    std::cout << "Airline Name: " << name << std::endl;
}

Airline::~Airline() {
    reservations.clear();
}

std::ostream& operator<<(std::ostream& out, const Airline& airline) {
    out << airline.name;
    return out;
}
