#ifndef FLIGHT_H
#define FLIGHT_H

#include "Airport.h"
#include "Airline.h"
#include <string>

class Flight {
private:
    Airport departure;
    Airport arrival;
    std::string departureTime;
    std::string arrivalTime;
    const Airline* airline;

public:
    Flight(const Airport& dep, const Airport& arr, const std::string& depTime, const std::string& arrTime);
    Flight(const Airport& dep, const Airport& arr, const std::string& depTime, const std::string& arrTime, const Airline& al);

    void displayInfo() const;
};

#endif // FLIGHT_H
