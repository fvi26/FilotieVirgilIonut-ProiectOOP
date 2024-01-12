#include "Flight.h"
#include <iostream>

Flight::Flight(const Airport& dep, const Airport& arr, const std::string& depTime, const std::string& arrTime)
        : departure(dep), arrival(arr), departureTime(depTime), arrivalTime(arrTime), airline(nullptr) {}

Flight::Flight(const Airport& dep, const Airport& arr, const std::string& depTime, const std::string& arrTime, const Airline& al)
        : departure(dep), arrival(arr), departureTime(depTime), arrivalTime(arrTime), airline(&al) {}

void Flight::displayInfo() const {
    std::cout << "Flight Information:" << std::endl;
    std::cout << "Departure Airport: " << departure.getName() << std::endl;
    std::cout << "Arrival Airport: " << arrival.getName() << std::endl;
    std::cout << "Departure Time: " << departureTime << std::endl;
    std::cout << "Arrival Time: " << arrivalTime << std::endl;

    if (airline != nullptr) {
        std::cout << "Airline: " << airline->getName() << std::endl;
    }

    std::cout << "---------------------------------" << std::endl;
}
