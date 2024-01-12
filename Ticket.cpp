#include "Ticket.h"

Ticket::Ticket(const Airport& dep, const Airport& arr, const std::string& name)
        : departure(dep), arrival(arr), passengerName(name) {}

void Ticket::displayInfo() const {
    std::cout << "Passenger Name: " << passengerName << std::endl;
    std::cout << "Departure Airport: " << departure.getName() << std::endl;
    std::cout << "Arrival Airport: " << arrival.getName() << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Ticket& ticket) {
    out << "Passenger Name: " << ticket.passengerName << std::endl;
    out << "Departure Airport: " << ticket.departure.getName() << std::endl;
    out << "Arrival Airport: " << ticket.arrival.getName();
    return out;
}
